#include <iostream>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>
#include <opencv2/core/core.hpp>
#include <cmath>

#define PRADIUS 5
enum MOUSE_STATUS { MOUSE_STATUS_HOLDING, MOUSE_STATUS_NORMAL };

void mousecallback(int event, int x, int y, int, void* p){
	static MOUSE_STATUS status = MOUSE_STATUS_NORMAL;
	static cv::Point2f* currentpoint;
	cv::Point2f* des_points = (cv::Point2f*)p;

	if( status == MOUSE_STATUS_NORMAL && event == CV_EVENT_LBUTTONDOWN){
		float mindis = 100000;
		float dis;
		cv::Point2f* minpoint = des_points;
		for(int i=0 ; i < 4 ; i++){
			dis = sqrtf(
					(x - des_points[i].x) * (x - des_points[i].x) + 
					(y - des_points[i].y) * (y - des_points[i].y)
				   );
			if( dis < mindis ){
				mindis = dis;
				minpoint = des_points + i;
			}
		}
		if( mindis < PRADIUS * 2 ){
			currentpoint = minpoint;
			status = MOUSE_STATUS_HOLDING;
		}
	}else if(status == MOUSE_STATUS_HOLDING){
		if(event == CV_EVENT_LBUTTONUP)
			status = MOUSE_STATUS_NORMAL;
		else{
			currentpoint->x = x;
			currentpoint->y = y;
		}
	}
}

int main(int argc, const char *argv[])
{
	cv::Mat img;
	cv::Mat warp_mat(3, 3, CV_32FC1);
	char* source_window = "source";
	char* dest_window = "destination";
	int interpolation_method = 1;
	char key;

	img = cv::imread(argv[1], 1);
	cv::namedWindow(source_window, CV_WINDOW_AUTOSIZE);
	cv::namedWindow(dest_window, CV_WINDOW_AUTOSIZE);
	cv::createTrackbar("interpolation", source_window, &interpolation_method, 4);
	cv::imshow(source_window, img);

	cv::Point2f src_points[4];
	cv::Point2f des_points[4];
	cv::setMouseCallback(dest_window, mousecallback, des_points);

	src_points[0] = cv::Point2f( 0, 0 );
	src_points[1] = cv::Point2f( img.cols-1, 0 );
	src_points[2] = cv::Point2f( 0, img.rows-1 );
	src_points[3] = cv::Point2f( img.cols-1, img.rows-1 );

	des_points[0] = cv::Point2f( img.cols*0.25, img.rows*0.25 );
	des_points[1] = cv::Point2f( img.cols*1.25, img.rows*0.25 );
	des_points[2] = cv::Point2f( img.cols*0.25, img.rows*1.25 );
	des_points[3] = cv::Point2f( img.cols*1.25, img.rows*1.25 );

	cv::Mat desimg = cv::Mat::zeros(img.cols * 1.5, img.rows * 1.5, img.type());


	for(;;){
		warp_mat = cv::getPerspectiveTransform(src_points, des_points);
		cv::warpPerspective(img, desimg, warp_mat, desimg.size(), interpolation_method);
		cv::circle(desimg, des_points[0], PRADIUS, cv::Scalar(255, 0, 0), -1);
		cv::circle(desimg, des_points[1], PRADIUS, cv::Scalar(0, 255, 0), -1);
		cv::circle(desimg, des_points[2], PRADIUS, cv::Scalar(0, 0, 255), -1);
		cv::circle(desimg, des_points[3], PRADIUS, cv::Scalar(0, 255, 255), -1);
		cv::imshow(dest_window, desimg);
		key = cv::waitKey(30);
		if( key==27 )
			break;
	}
	return 0;
}



