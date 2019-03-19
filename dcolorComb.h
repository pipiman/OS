#pragma once

#include <opencv2/opencv.hpp>  
#include <vector>  
using namespace std;
using namespace cv;


class dcolorComb
{
public:
	//ԭͼ �� ѹ���Ƕ� �����¼��б��������Ҽ��б���
	dcolorComb(Mat src,float rad,float h,float v); 
	~dcolorComb();

	Mat process();
	void makeMask();
	Mat T_adjust(Mat &sr);
	Mat C_adjust(Mat & inputL, Mat & inputR);

private:

	Mat src;			//����ԭͼ

	static int *m_Data;	//����洢

	int hei;
	int wid;
	int dhei;
	float rad;		//ѹ���Ƕ�
	float hor_rate; //��ֱ���б���
	float ver_rate;	//ˮƽ���б���
};
