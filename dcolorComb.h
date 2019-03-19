#pragma once

#include <opencv2/opencv.hpp>  
#include <vector>  
using namespace std;
using namespace cv;


class dcolorComb
{
public:
	//原图 ； 压缩角度 ；上下剪切比例；左右剪切比例
	dcolorComb(Mat src,float rad,float h,float v); 
	~dcolorComb();

	Mat process();
	void makeMask();
	Mat T_adjust(Mat &sr);
	Mat C_adjust(Mat & inputL, Mat & inputR);

private:

	Mat src;			//输入原图

	static int *m_Data;	//掩码存储

	int hei;
	int wid;
	int dhei;
	float rad;		//压缩角度
	float hor_rate; //垂直剪切比例
	float ver_rate;	//水平剪切比例
};
