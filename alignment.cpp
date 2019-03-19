#include <opencv2/opencv.hpp>
#include <opencv2/xfeatures2d.hpp>
#include <opencv2/features2d.hpp>
 
using namespace std;
using namespace cv;
using namespace cv::xfeatures2d;
 
const int MAX_FEATURES = 200;
const float GOOD_MATCH_PERCENT = 0.05f;

Mat alignment(Mat &im1, Mat &im2){

  // Convert images to grayscale
  Mat im1Gray, im2Gray;
  cvtColor(im1, im1Gray, COLOR_BGR2GRAY);
  cvtColor(im2, im2Gray, COLOR_BGR2GRAY);
   
  // Variables to store keypoints and descriptors
  std::vector<KeyPoint> keypoints1, keypoints2;
  Mat descriptors1, descriptors2;
   
  // Detect ORB features and compute descriptors.
  Ptr<Feature2D> orb = ORB::create(MAX_FEATURES);
  orb->detectAndCompute(im1Gray, Mat(), keypoints1, descriptors1);
  orb->detectAndCompute(im2Gray, Mat(), keypoints2, descriptors2);
   
  // Match features.
  std::vector<DMatch> matches;
  Ptr<DescriptorMatcher> matcher = DescriptorMatcher::create("BruteForce-Hamming");
  matcher->match(descriptors1, descriptors2, matches, Mat());
   
  // Sort matches by score
  std::sort(matches.begin(), matches.end());
   
  // Remove not so good matches
  const int numGoodMatches = matches.size() * GOOD_MATCH_PERCENT;
  matches.erase(matches.begin()+numGoodMatches, matches.end());

  // Extract location of good matches && calcue the distence on a line
  std::vector<Point2f> points1, points2;

  double add = 0;
  
  for( size_t i = 0; i < matches.size(); i++ )
  {
    points1.push_back( keypoints1[ matches[i].queryIdx ].pt );
    points2.push_back( keypoints2[ matches[i].trainIdx ].pt );

    // printf("point1.x=%f,point1.y=%f",points1[i].x,points1[i].y);

    add += points1[i].y - points2[i].y;
  }
  
  add /= matches.size();
 
  add /= 2;

  int hei = im1.size().height;
  int wid = im1.size().width;

  Mat combin(hei, wid * 2 ,im1.type());
 
  if(add > 0){

    int subhei = hei-add*1;
    im2 = Mat(im2,Rect(0,0,wid,subhei));
    im1 = Mat(im1,Rect(0,hei - subhei,wid,subhei));

    Mat submat = combin.rowRange(hei - subhei,hei).colRange(wid,combin.size().width);;
    im2.copyTo(submat);
  
    submat = combin.rowRange(0,subhei).colRange(0,wid);
    im1.copyTo(submat);
    
  }else{

    int subhei = hei-add*(-1);

    im1 = Mat(im1,Rect(0,0,wid,subhei));
    im2 = Mat(im2,Rect(0,hei - subhei,wid,subhei));

    Mat submat = combin.rowRange(hei - subhei,hei).colRange(0,wid);
    im1.copyTo(submat);
  
    submat = combin.rowRange(0,subhei).colRange(wid,combin.size().width);
    im2.copyTo(submat);

  }

  
  
  return combin;
  
 
}

  
int main()
{
  string refFilename("right.jpg"); 
  cout << "Reading reference image : " << refFilename << endl; 
  Mat left = imread(refFilename);

  string imFilename("left.jpg");
  cout << "Reading image to align : " << imFilename << endl; 
  Mat right = imread(imFilename);

  Mat out = alignment(left, right);

  string outFilename("aligned.jpg");
  cout << "Saving aligned image : " << outFilename << endl; 
  imwrite(outFilename, out);

  
 
 
  return 0;
}
