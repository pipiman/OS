
//首先分割成了两个图
Mat imgL = Mat(src, Rect(0, 0, wid / 2, hei));
Mat imgR = Mat(src, Rect(wid / 2, 0, wid / 2, hei));


transpose(imgL, imgL);
flip(imgL, imgL, 0);
transpose(imgR, imgR);
flip(imgR, imgR, 1);

Mat r_imgL = Mat::zeros(wid/2, hei, CV_8UC3);
Mat r_imgR = Mat::zeros(wid/2, hei, CV_8UC3);

uchar * dataL, *ptL, *dataR, *ptR;

//目标出现
int * p_mask = int[hei*(wid+1)/2];
memset(p_mask, 0, hei*wid);
double para = tan(rad * 3.1415926 / 360);
para_h = w * para;
int offset;
double m;
int p = h / 2 + para_h;

for (int i = 0; i < w/2; i++){

  for (int j = 0; j < para_h; j++){

    if (( j > para_h) && j<( h - para_h)){

      m = ( h * i / 2 - i*j ) * para;
      *p_mask = ( j-int(m / p)) * 3;
    }
    p_mask++;
  }
 }


for (int i = 0; i < wid/2; i++){
  dataL = (uchar*)imgL.ptr<uchar>(i);
  ptL = (uchar*)r_imgL.ptr<uchar>(i);
  dataR = (uchar*)imgR.ptr<uchar>(i);
  ptR = (uchar*)r_imgR.ptr<uchar>(i);

  for (int j = 0; j < hei; j++){
    
    if ((j>dhei+1) && j<(hei - dhei)-1){
      *(ptL + 0 + j * 3) = *(dataL + (*p_mask) +0);
      *(ptL + 1 + j * 3) = *(dataL + (*p_mask) +1);
      *(ptL + 2 + j * 3) = *(dataL + (*p_mask) +2);
      *(ptR + 0 + j * 3) = *(dataR + (*p_mask) + 0);
      *(ptR + 1 + j * 3) = *(dataR + (*p_mask) + 1);
      *(ptR + 2 + j * 3) = *(dataR + (*p_mask) + 2);
    }
    p_mask++;
  }
 }

transpose(r_imgR, r_imgR);
flip(r_imgR, r_imgR, 0);
transpose(r_imgL, r_imgL);
flip(r_imgL, r_imgL, 1);

