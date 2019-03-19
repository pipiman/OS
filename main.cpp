
//#include "CalculateTime.h"
#include"Divid.h"

int main()
{
  	Mat src = imread("data/1.jpg");
	//	CalculateTime time;

	dividedM my(src, 5, 0.02, 0.06,0.09);
	//	time.start();

	my.pace1();
	//	time.stop();
	//	printf("%lf\n", time.stop_start());
	//	imwrite("result.jpg", out);

  
	
	//	cvNamedWindow("123", CV_WINDOW_NORMAL);
	//	imshow("123", src);
	//	waitKey(0);
	

  
	return 0;
}

