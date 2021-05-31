#include <stdio.h>
#include <opencv2/opencv.hpp>
using namespace cv;

Mat img_box_only(800, 800, CV_8UC3, Scalar(255,255,255));
Mat img_1(800, 800, CV_8UC3, Scalar(255,255,255));
Mat img_2(800, 800, CV_8UC3, Scalar(255,255,255));

struct box_size{
    double x;
    double y;
}box;

int K; //number of spheres
struct sphere{
    double r;
    double m;
    double Vx;
    double Vy;
    double Px;
    double Py;
};
#define struct sphere sphere
sphere ball[10];




int main(){
          scanf("%d",&K);
          scanf( "%lf%lf", &box.x,&box.y );
          box.x*=100;
          box.y*=100;
          for(int i=0;i<K;i++){
                    scanf( "%lf%lf%lf%lf%lf%lf", &ball[i].r, &ball[i].m, &ball[i].Px, &ball[i].Py, &ball[i].Vx, &ball[i].Vy );
          }

          //draw box
          line(  img_box_only, Point( 400+box.x, 400+box.y ),
                                                  Point( 400-box.x, 400+box.y ),
                    Scalar( 0,0,0 ), 2);
          line(  img_box_only, Point( 400+box.x, 400-box.y ),
                                                  Point( 400-box.x, 400-box.y ),
                    Scalar( 0,0,0 ), 2);

          line(  img_box_only, Point( 400+box.x, 400+box.y ),
                                                  Point( 400+box.x, 400-box.y ),
                    Scalar( 0,0,0 ), 2);
          line(  img_box_only, Point( 400-box.x, 400+box.y ),
                                                  Point( 400-box.x, 400-box.y ),
                    Scalar( 0,0,0 ), 2);
          //draw box
          imshow( "box",img_box_only );
          waitKey(0);






return 0;
}
