#pragma once

#include <opencv2/opencv.hpp>  
#include <vector>  
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d.hpp>

using namespace cv::xfeatures2d;
using namespace std;
using namespace cv;

const int MAX_FEATURES = 200;
const float GOOD_MATCH_PERCENT = 0.05f;

class dividedM
{
public:
	//ԭͼ �� ѹ���Ƕ� �����¼��б��������Ҽ��б���
  dividedM(Mat &src,float press,float h_up,float h_down, float w); 

  //divide to left&right,control the flow, return resault
  void pace1();

  //alignment first 
  void pace2();

  //press
  void pace3(Mat &img);

  //cut & resize & combin
  // Mat pace4()
  

private:

  Mat src,left,right;

  //casue at last the image should resize to th very first size, so keep the very first size at begein
  int hei;
  int wid;

  int subhei;
  int subwid;

  //store the para related to press and divide
  int dwid;

  //the para that people want to manage
  float press;	//ѹ���Ƕ�
  float hor_up; //��ֱ�����ϲ����� 14%
  float hor_down; //��ֱ�����²�����5%
  float ver_rate;	//ˮƽ���б���6%
};
