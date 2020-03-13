#include <iostream> 
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;
//肤色检测
/*int main()
{
	VideoCapture cap(0);

	double scale = 0.5;

	//0-180

	//肤色
	double i_minH = 0;
	double i_maxH = 20;
	//0-255
	double i_minS = 43;
	double i_maxS = 255;
	//0-255
	double i_minV = 55;
	double i_maxV = 255;

	while (1)
	{
		Mat frame;
		Mat hsvMat;
		Mat detectMat;

		cap >> frame;
		Size ResImgSiz = Size(frame.cols*scale, frame.rows*scale);
		Mat rFrame = Mat(ResImgSiz, frame.type());
		resize(frame, rFrame, ResImgSiz, INTER_LINEAR);

		cvtColor(rFrame, hsvMat, COLOR_BGR2HSV);

		rFrame.copyTo(detectMat);

		cv::inRange(hsvMat, Scalar(i_minH, i_minS, i_minV), Scalar(i_maxH, i_maxS, i_maxV), detectMat);

		imshow("whie: in the range", detectMat);
		imshow("frame", rFrame);

		waitKey(30);
	}
}
*/

//二值化练习
/*int main()
{   
	Mat result;
	Mat result_s;
	Mat srcMat = imread("E:\\dignal picture\\2.jpg",0);
	//全局二值化
		threshold(srcMat, result, 100, 255, THRESH_BINARY);
	//局部二值化
		adaptiveThreshold(srcMat, result_s, 255, ADAPTIVE_THRESH_GAUSSIAN_C, THRESH_BINARY_INV, 5, 10);

		imshow("yuantu", srcMat);
		imshow("quanju", result);
	    imshow("jubu", result_s);

		waitKey(0);
}*/

//回调函数
string window_name = "binaryMat";
void threshod_Mat(int th, void*data)
{
	Mat src = *(Mat*)(data);
	Mat dst;
	//二值化
	threshold(src, dst, th, 255, 0);
	imshow(window_name, dst);
}
int main() {
	Mat srcMat;
	Mat gryMat;
	int lowTH = 30 ;
	int maxTH = 255;
	srcMat = imread("D\\dignal picture\\2.jpg");
	if (!srcMat.data)
	{
		cout << "图像载入失败！" << endl;
		return 0;

	}
	cvtColor(srcMat, gryMat, CV_BGR2GRAY);
	imshow(window_name, gryMat);
	createTrackbar(
		"threshold",
		window_name,
		&lowTH,
		maxTH,
		threshod_Mat,
		&gryMat
	);
	waitKey(30);
	return 0;
}
