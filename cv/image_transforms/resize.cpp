#include <iostream>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/core/core.hpp>
#include <cstdlib>



int main(int argc, const char *argv[])
{
	std::string win_name = "resize";
	cv::namedWindow(win_name, CV_WINDOW_AUTOSIZE);
	if(argc < 2)
		exit(1);
	cv::Mat img = cv::imread(*(argv+1));
	cv::Mat desimg;
	char key;

	int rows = img.rows, cols = img.cols;
	int cfx = 10, cfy = 10;
	int interpolation_method = 1;

#ifdef USESIZE
	cv::createTrackbar("rows", win_name, &rows, img.rows * 2);
	cv::createTrackbar("cols", win_name, &cols, img.cols * 2);
#endif
	cv::createTrackbar("fx", win_name, &cfx, 20);
	cv::createTrackbar("fy", win_name, &cfy, 20);
	cv::createTrackbar("interpolation", win_name, &interpolation_method, 4);

	for(;;){
#ifndef USESIZE
		cv::resize(img, desimg, cv::Size(0, 0), cfx * 0.1, cfy * 0.1, interpolation_method);
#else
		cv::resize(img, desimg, cv::Size(rows, cols), cfx * 0.1, cfy * 0.1, interpolation_method);
#endif
		cv::imshow(win_name, desimg);
		key = cv::waitKey(30);
		if(key==27)
			break;
	}
	return 0;
}

