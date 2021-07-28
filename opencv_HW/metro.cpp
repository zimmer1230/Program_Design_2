#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

Mat img( 800,800,CV_8UC3,Scalar(255,255,255) );
int delay = 500;

int main(){
          while(1){
                    line( img,Point(400,600), Point( 600,200 ), Scalar(255,255,255), 3 );
                    line( img,Point(400,600), Point( 200,200 ), Scalar(0,0,0), 3 );
                    imshow("Metro",img);
                    waitKey(delay);
                    line( img,Point(400,600), Point( 200,200 ), Scalar(255,255,255), 3 );
                    line( img,Point(400,600), Point( 600,200 ), Scalar(0,0,0), 3 );
                    imshow("Metro",img);
                    waitKey(delay);
          }




}
