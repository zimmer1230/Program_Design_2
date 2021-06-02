#include <stdio.h>
#include <math.h>
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


int delta_t = 100;

double dist_calc( double x1, double x2, double y1, double y2 ){
          return  (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) ;
}

int is_touched_balls(sphere b1, sphere b2){
          if( dist_calc( b1.Px, b2.Px, b1.Py, b2.Py ) - (b1.r + b2.r)*(b1.r + b2.r) < 1 )
                    return 1;
          else return 0;
}

int main(){
          scanf("%d",&K);
          scanf( "%lf%lf", &box.x,&box.y );
          box.x*=100;
          box.y*=100;
          for(int i=0;i<K;i++){
                    scanf( "%lf%lf%lf%lf%lf%lf", &ball[i].r, &ball[i].m, &ball[i].Px, &ball[i].Py, &ball[i].Vx, &ball[i].Vy );
                    ball[i].r*=100, ball[i].Px*=100, ball[i].Py*=100;
                    ball[i].Px+=400,ball[i].Py+=400;
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


          int time = 0;
          //draw initial ball
          img_box_only.copyTo(img_1);
          for(int i=0;i<K;i++){
                    circle( img_1, Point( ball[i].Px,ball[i].Py ), ball[i].r, Scalar(0,0,0), 2 );
          }
          imshow("409410058",img_1);
          waitKey(delta_t);
          //draw initial ball

          //draw moving
          auto drawing_img=&img_1;
          while(1){

                    if( drawing_img == &img_1 ) drawing_img=&img_2;
                    else drawing_img=&img_1;

                    img_box_only.copyTo(*drawing_img);

                    for(int i=0;i<K-1;i++){
                              for(int j=i+1;j<K;j++){
                                        if( is_touched_balls( ball[i],ball[j] ) ){
                                                  ball[i].Vx = ball[i].Vx * ( (ball[i].m - ball[j].m)/(ball[i].m +ball[j].m) )+ 2*ball[j].m/(ball[i].m + ball[j].m);
                                                  printf("ball %d : %lf\n",i,ball[i].Vx);
                                                  printf("ball %d : %lf\n",i,ball[j].Vx);
                                                  ball[j].Vx = ball[j].Vx * ( (ball[j].m - ball[i].m)/(ball[j].m +ball[i].m) )+ 2*ball[i].m/(ball[j].m + ball[i].m);
                                                  while( is_touched_balls( ball[i],ball[j] )==1) {
                                                            circle( *drawing_img, Point(  ball[i].Px += ball[i].Vx, ball[i].Py += ball[i].Vy), ball[i].r, Scalar(0,0,0), 2 );
                                                            circle( *drawing_img, Point(  ball[j].Px += ball[j].Vx, ball[j].Py += ball[j].Vy), ball[j].r, Scalar(0,0,0), 2 );
                                                            imshow("409410058",*drawing_img);
                                                            waitKey(delta_t);
                                                            img_box_only.copyTo(*drawing_img);
                                                  }
                                        }
                              }
                    }
                    for(int i=0;i<K;i++){
                              circle( *drawing_img, Point(  ball[i].Px += ball[i].Vx, ball[i].Py += ball[i].Vy), ball[i].r, Scalar(0,0,0), 2 );
                    }

                    imshow("409410058",*drawing_img);
                    waitKey(delta_t);
          }

          imshow( "window",img_1 );
          waitKey(0);










return 0;
}
