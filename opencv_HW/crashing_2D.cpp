#include <stdio.h>
#include <math.h>
#include <opencv2/opencv.hpp>
using namespace cv;

Mat img_box_only(1200, 1200, CV_8UC3, Scalar(255,255,255));
Mat img_1(1200, 1200, CV_8UC3, Scalar(255,255,255));
Mat img_2(1200, 1200, CV_8UC3, Scalar(255,255,255));

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
typedef struct sphere sphere;
typedef struct box_size vect;
sphere ball[10];



int delta_t = 2;

double dist_calc( double x1, double x2, double y1, double y2 ){ //dist_sq
          return  (x1-x2)*(x1-x2)+(y1-y2)*(y1-y2) ;
}
double dist_calc( vect v ){
          return v.x*v.x + v.y*v.y;
}

double dot_product( vect a, vect b){
          return a.x*b.x + a.y* b.y;
}

int is_touched_balls(sphere b1, sphere b2){
          if( dist_calc( b1.Px, b2.Px, b1.Py, b2.Py ) - (b1.r + b2.r)*(b1.r + b2.r) < 1 )
                    return 1;
          else return 0;
}

int is_touched_walls( sphere b ){  //right : 1 left : 2 up : 3 down : 4 right-up : 5 right-down : 6 left-up : 7 left-down : 8
          if( b.Px + b.r >= 600+box.x && b.Py - b.r <= 600-box.y &&  b.r <= box.x&& b.r <= box.y )
                    return 5;
          if( b.Px + b.r >= 600+box.x && b.Py + b.r >= 600+box.y &&  b.r <= box.x && b.r <= box.y)
                    return 6;
          if( b.Px - b.r <= 600-box.x && b.Py - b.r <= 600-box.y && b.r <= box.x && b.r <= box.y )
                    return 7;
          if( b.Px - b.r <= 600-box.x && b.Py + b.r <= 600-box.y && b.r <= box.x && b.r <= box.y )
                    return 8;
          if( b.Px + b.r >= 600+box.x && b.r <= box.x ) //right
                    return 1;
          if( b.Px - b.r <= 600-box.x && b.r <= box.x  ) //left
                    return 2;
          if( b.Py - b.r <= 600-box.y && b.r <= box.y ) //up
                    return 3;
          if( b.Py + b.r >= 600+box.y && b.r <= box.y) // down
                    return 4;
          return 0;
}

int main(){
          scanf("%d",&K);
          scanf( "%lf%lf", &box.x,&box.y );
          box.x*=100;
          box.y*=100;
          for(int i=0;i<K;i++){
                    scanf( "%lf%lf%lf%lf%lf%lf", &ball[i].r, &ball[i].m, &ball[i].Vx, &ball[i].Vy, &ball[i].Px, &ball[i].Py );
                    ball[i].r*=100, ball[i].Px*=100, ball[i].Py*=100;
                    ball[i].Px+=600,ball[i].Py+=600;
          }

          //draw box
          line(  img_box_only, Point( 600+box.x, 600+box.y ),
                                                  Point( 600-box.x, 600+box.y ),
                    Scalar( 0,0,0 ), 2);
          line(  img_box_only, Point( 600+box.x, 600-box.y ),
                                                  Point( 600-box.x, 600-box.y ),
                    Scalar( 0,0,0 ), 2);

          line(  img_box_only, Point( 600+box.x, 600+box.y ),
                                                  Point( 600+box.x, 600-box.y ),
                    Scalar( 0,0,0 ), 2);
          line(  img_box_only, Point( 600-box.x, 600+box.y ),
                                                  Point( 600-box.x, 600-box.y ),
                    Scalar( 0,0,0 ), 2);
          //draw box


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
//                    if( drawing_img == &img_1 ) drawing_img=&img_2;
//                    else drawing_img=&img_1;

                    img_box_only.copyTo(*drawing_img);

                    //check crashing
                    for(int i=0;i<K-1;i++){
                              for(int j=i+1;j<K;j++){
                                        if( is_touched_balls( ball[i],ball[j] ) && !( ball[i].Vx == 0 && ball[i].Vy == 0 && ball[j].Vx == 0 && ball[j].Vy == 0 ) ){
                                                  printf("crashing!!\n");
                                                  vect rij ={   // r is a vector that from ball i 's  center to j ' s
                                                            .x = ball[j].Px - ball[i].Px,
                                                            .y = ball[j].Py - ball[i].Py
                                                  };
                                                  vect rji = {
                                                            .x = -rij.x,
                                                            .y = -rij.y
                                                  };
                                                  vect iV ={
                                                            .x = ball[i].Vx,
                                                            .y = ball[i].Vy
                                                  };
                                                  vect jV = {
                                                            .x = ball[j].Vx,
                                                            .y = ball[j].Vy
                                                  };
                                                  vect iV_j = { // iV projection on rij
                                                            .x = rij.x * dot_product( iV,rij )/dist_calc(rij) ,
                                                            .y = rij.y * dot_product( iV,rij )/dist_calc(rij)
                                                  };
                                                  vect iV_n = {  //iV_j + iV_n = iV
                                                            .x = iV.x - iV_j.x,
                                                            .y = iV.y - iV_j.y
                                                  };
                                                  vect jV_i = {
                                                            .x = rji.x * dot_product( jV, rji )/dist_calc(rji),
                                                            .y = rji.y * dot_product( jV, rji )/dist_calc(rji)
                                                  };
                                                  vect jV_n = {
                                                            .x = jV.x - jV_i.x,
                                                            .y = jV.y - jV_i.y
                                                  };

                                                  //update iV_j and jV_i
                                                  vect tmp_iV_j = iV_j;
                                                  iV_j.x =  ( ( ( ball[i].m - ball[j].m ) * iV_j.x + 2 * ball[j].m * jV_i.x ) / ( ball[i].m + ball[j].m ) );
                                                  iV_j.y =  ( ( ( ball[i].m - ball[j].m ) * iV_j.y + 2 * ball[j].m * jV_i.y ) / ( ball[i].m + ball[j].m ) );

                                                  jV_i.x = ( ( ( ball[j].m - ball[i].m ) * jV_i.x + 2 * ball[i].m * tmp_iV_j.x ) / ( ball[i].m + ball[j].m ) );
                                                  jV_i.y = ( ( ( ball[j].m - ball[i].m ) * jV_i.y + 2 * ball[i].m * tmp_iV_j.y ) / ( ball[i].m + ball[j].m ) );
                                                  //update iV_j and jV_i

                                                  //update iV and ball[i] ball[v]
                                                  iV.x = iV_j.x + iV_n.x;
                                                  iV.y = iV_j.y + iV_n.y;
                                                  ball[i].Vx = iV.x;
                                                  ball[i].Vy = iV.y;

                                                  jV.x = jV_i.x + jV_n.x;
                                                  jV.y = jV_i.y + jV_n.y;
                                                  ball[j].Vx = jV.x;
                                                  ball[j].Vy = jV.y;
                                                  //update iV and ball[i] ball[v]
                                                  printf(" new speed of ball %d : %lf\n",i,ball[i].Vx);
                                                  printf(" new speed of ball %d : %lf\n",j,ball[j].Vx);
                                                  while( is_touched_balls( ball[i],ball[j] )==1) {
                                                            circle( *drawing_img, Point(  ball[i].Px += ball[i].Vx, ball[i].Py += ball[i].Vy), ball[i].r, Scalar(0,0,0), 2 );
                                                            circle( *drawing_img, Point(  ball[j].Px += ball[j].Vx, ball[j].Py += ball[j].Vy), ball[j].r, Scalar(0,0,0), 2 );
                                                            for(int p = 0; p<K;p++){
                                                                      if( p == i || p == j ) continue;
                                                                      circle( *drawing_img, Point(  ball[p].Px += ball[p].Vx, ball[p].Py += ball[p].Vy), ball[p].r, Scalar(0,0,0), 2 );
                                                            }
                                                            imshow("409410058",*drawing_img);
                                                            waitKey(delta_t);
                                                            img_box_only.copyTo(*drawing_img);
                                                  }
                                        }
                              }
                    }

                    //check wall
                    for(int i=0; i<K; i++){
                              if( is_touched_walls( ball[i] )!=0 ){
                                        printf("wall!!\n");
                                        int state_which_wall = is_touched_walls( ball[i] );
                                        switch( is_touched_walls( ball[i] ) ){
                                                  case 1:
                                                            ball[i].Vx *= -1;
                                                            break;
                                                  case 2:
                                                            ball[i].Vx *= -1;
                                                            break;
                                                  case 3:
                                                            ball[i].Vy *= -1;
                                                            break;
                                                  case 4:
                                                            ball[i].Vy *= -1;
                                                            break;
                                                  case 5:
                                                            ball[i].Vx *= -1;
                                                            ball[i].Vy *= -1;
                                                            break;
                                                  case 6:
                                                            ball[i].Vx *= -1;
                                                            ball[i].Vy *= -1;
                                                            break;
                                                  case 7:
                                                            ball[i].Vx *= -1;
                                                            ball[i].Vy *= -1;
                                                            break;
                                                  case 8:
                                                            ball[i].Vx *= -1;
                                                            ball[i].Vy *= -1;
                                                            break;
                                                  default:
                                                            break;

                                        }
                                        while( is_touched_walls( ball[i] )== state_which_wall  ){
                                                  circle( *drawing_img, Point(  ball[i].Px += ball[i].Vx, ball[i].Py += ball[i].Vy), ball[i].r, Scalar(0,0,0), 2 );
                                                  for(int j=0;j<K;j++){
                                                            if( j == i ) continue;
                                                            circle( *drawing_img, Point(  ball[j].Px += ball[j].Vx, ball[j].Py += ball[j].Vy), ball[j].r, Scalar(0,0,0), 2 );
                                                  }
                                                  imshow( "409410058",*drawing_img );
                                                  waitKey(delta_t);
                                                  img_box_only.copyTo(*drawing_img);
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
