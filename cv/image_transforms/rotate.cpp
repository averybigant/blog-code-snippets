#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <cstdlib>

void mousecallback(int event, int x, int y, int, void* point){
	if(event == CV_EVENT_LBUTTONDBLCLK){
		((cv::Point2f*)point)->x = x;
		((cv::Point2f*)point)->y = y;
	}
}


int main(int argc, const char *argv[])
{
	cv::Mat img, des_img;
	cv::Mat affmat(2, 3, CV_32FC1);
	if(argc < 2)
		exit(1);
	img = cv::imread(*(argv + 1));

	int angle=0, scale=10;
	char key;
	cv::Point2f center;
	center.x = img.cols / 2;
	center.y = img.rows / 2;
	std::string winname = "rotate";
	cv::namedWindow(winname, CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("angle", winname, &angle, 360);
	cv::createTrackbar("scale", winname, &scale, 360);
	cv::setMouseCallback(winname, mousecallback, &center);

	for(;;){
		affmat = cv::getRotationMatrix2D(center, 1.0 * angle, 0.1 * scale);
		cv::warpAffine(img, des_img, affmat, img.size());
		cv::circle(des_img, center, 5, cv::Scalar(255, 0, 0), -1);
		imshow(winname, des_img);
		key = cv::waitKey(30);
		if(key==27)
			break;
	}
	
	return 0;
}
