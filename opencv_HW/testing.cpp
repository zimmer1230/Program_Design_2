#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

int main(){
          Mat img_1(400,400,CV_8UC3,Scalar(255,255,255));
          Mat img_2(400,400,CV_8UC3,Scalar(255,255,255));
          auto drawing_img = &img_1;
          circle( *drawing_img, Point( 200,200 ), 100, Scalar(0,0,0), 3 );
          imshow("lalala",*drawing_img);
          waitKey(0);
          return 0;


}
