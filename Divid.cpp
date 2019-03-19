#include"Divid.h"

dividedM::dividedM(Mat &src,float press,float h_up,float h_down, float w)
{
	this->src = src;
	this->press = press;
	this->hor_up = h_up;
	this->hor_down = h_down;
	this->ver_rate = w;
	hei = src.size().height;
	wid = src.size().width;

	subhei = wid / 2;
	subwid = hei;
}

void dividedM::pace1(){

  left = Mat(src, Rect(0, 0, wid / 2, hei));
  right = Mat(src, Rect(wid / 2, 0, wid / 2, hei));

  transpose(left, left);
  flip(left, left, 1);
  transpose(right, right);
  flip(right, right, 0);

  pace3(left);

  
}



/*Mat dcolorComb::C_adjust(Mat & inputL, Mat & inputR)
{
	int dh = int(((float)hei- dhei*2)*hor_rate);
	int dw = int((float)wid*ver_rate);
	int orwid = inputL.size().width;
	int orhei = inputL.size().height;
	
	inputL = Mat(inputL, Rect(dw, dh+ dhei, wid/2-2*dw, hei - 2 * (dh+dhei)));
	inputR = Mat(inputR, Rect(dw, dh + dhei, wid/2 - 2 * dw, hei - 2 * (dh + dhei)));

	cv::resize(inputL,inputL,cv::Size(orwid,orhei),0,0,INTER_LINEAR);
	cv::resize(inputR,inputR,cv::Size(orwid,orhei),0,0,INTER_LINEAR);

	int totalCols = inputL.cols + inputR.cols;
	Mat mergedDescriptors(hei, wid, inputL.type());
	Mat submat = mergedDescriptors.rowRange(0,inputL.rows).colRange(0,inputL.cols);
	inputL.copyTo(submat);
	submat = mergedDescriptors.rowRange(0,inputL.rows).colRange(inputL.cols, totalCols);
	inputR.copyTo(submat);

	return mergedDescriptors;

}

Mat dcolorComb::process()
{

	Mat out_T = T_adjust(this->src);

	return out_T;
}
*/

void dividedM::pace3(Mat &img){

 
  double pare = tan(press * 3.1415926 / 360);
   dwid = int(subhei * pare);
 
  vector<Point2f> src_corners(4);
  vector<Point2f> dst_corners(4);

  src_corners[0]= Point2f(0,0);
  src_corners[1]= Point2f(subwid - 1,0);
  src_corners[2]= Point2f(0, subhei - 1);
  src_corners[3]= Point2f(subwid - 1, subhei - 1);

  dst_corners[0]= Point2f(dwid,0);
  dst_corners[1]= Point2f(subwid - 1 - dwid,0);
  dst_corners[2]= Point2f(0, subhei - 1);
  dst_corners[3]= Point2f(subwid - 1, subhei - 1);


  Mat transMtx = getPerspectiveTransform(src_corners, dst_corners);
 
  warpPerspective(img, img, transMtx, Size(subwid, subhei));

  /*test
  printf("rows & cols:%d,%d\nhei & wid:%d,%d\n",img.rows,img.cols,subhei,subwid);

  
 string outFilename("pressed.jpg");
  cout << "Saving pressed image : " << outFilename << endl; 
  imwrite(outFilename, img);
  */
  return ;
}
