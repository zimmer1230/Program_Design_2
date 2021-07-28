#include <stdio.h>
#include <time.h>
#include <math.h>
#include <opencv2/opencv.hpp>

#define DEBUG 0

using namespace cv;

int delay = 5;

void generate_circle();
void CallBackFunc(int , int , int , int , void*);
//Mat img( 800,800,CV_8UC3,Scalar(255,255,255) );
Mat img( 1080,1920,CV_8UC3,Scalar(255,255,255) );
auto img_address = img;
Mat img2( 1080,1920,CV_8UC3,Scalar(255,255,255) );

int score = 0;
int main()
{
          int baseline;
          Size text_size = getTextSize("Press any key.", 0, 1, 2, &baseline);
          Point org;
          org.x = 960 - text_size.width / 2;
          org.y = 540 + text_size.height / 2;
          putText(img,"Press any key.", org, 0, 1, Scalar(0,0,0), 3);
          imshow("OUS!",img);
          waitKey(0);
#if DEBUG == 1
          while( 1 ){
          generate_circle();
          }
          //GAME OVER
          char score_str[20];
          sprintf( score_str,"%d", score );
          rectangle( img, Point( 0,0 ), Point( 1920,1080 ), Scalar(255,255,255), -1 );
          putText( img, score_str, Point( 40,40 ), 1, 3, Scalar(0,0,255),3  );

          text_size = getTextSize("GAME OVER", 0, 3, 2, &baseline);
          org.x = 960 - text_size.width / 2;
          org.y = 540 + text_size.height / 2;
          putText(img,"GAME OVER", org, 0, 3, Scalar(0,0,255), 3);
          imshow("OUS!",img);
          waitKey(0);
#endif // DEBUG
#if DEBUG == 0
          while( score >-2000 ){
          generate_circle();
          }
          //GAME OVER
          char score_str[20];
          sprintf( score_str,"%d", score );
          rectangle( img, Point( 0,0 ), Point( 1920,1080 ), Scalar(255,255,255), -1 );
          putText( img, score_str, Point( 40,40 ), 1, 3, Scalar(0,0,255),3  );

          text_size = getTextSize("GAME OVER", 0, 3, 2, &baseline);
          org.x = 960 - text_size.width / 2;
          org.y = 540 + text_size.height / 2;
          putText(img,"GAME OVER", org, 0, 3, Scalar(0,0,255), 3);
          imshow("OUS!",img);
          waitKey(0);
#endif // DEBUG
}

Point rdp;
int r ;
int clicked ;
auto current_img = img;
int current = 1;

Point generate_rand_point(){
          srand( rand() );
          return Point( 200+rand()%1521, 200+rand()%681 ); // 200<x<1720, 200<y<
}

int dist(Point a, Point b){
          return (a.x-b.x)*(a.x-b.x) + (a.y-b.y)*(a.y-b.y) ;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata){
     Point pt;
     if  ( event == EVENT_LBUTTONDOWN && clicked == 0 ){
          clicked = 1;
          printf("Click\n");
          pt = Point(x,y);
          Point org;
          if( dist( pt, rdp ) <=10000 ){
                    if( 150-r >45 ){
                              printf("Perfect\n");
                              int baseline;
                              Size text_size = getTextSize("Perfect", 0, 1, 2, &baseline);
                              org.x = rdp.x - text_size.width / 2;
                              org.y = rdp.y + text_size.height / 2;
                              putText(img,"Perfect", org, 0,1,Scalar(85,198,249),2);
                              score += 500;
                    }
                    else if( 150-r >40 ){
                              printf("Good\n");
                              int baseline;
                              Size text_size = getTextSize("Good", 0, 1, 2, &baseline);
                              org.x = rdp.x - text_size.width / 2;
                              org.y = rdp.y + text_size.height / 2;
                              putText(current_img,"Good", org, 0,1,Scalar(85,198,66),2);
                              score += 200;
                    }
                    else if( 150-r >35 ){
                              printf("OK\n");
                              int baseline;
                              Size text_size = getTextSize("OK", 0, 1, 2, &baseline);
                              org.x = rdp.x - text_size.width / 2;
                              org.y = rdp.y + text_size.height / 2;
                              putText(current_img,"OK", org, 0,1,Scalar(85,111,255),2);
                              score += 100;
                    }
                    else {
                              printf("MISS\n");
                              int baseline;
                              Size text_size = getTextSize("MISS", 0, 1, 2, &baseline);
                              org.x = rdp.x - text_size.width / 2;
                              org.y = rdp.y + text_size.height / 2;
                              putText(current_img,"MISS", org, 0,1,Scalar(0,0,255),2);
                              score -= 500;
                    }
          }
          else {
                    printf("MISS\n");
                    int baseline;
                    Size text_size = getTextSize("MISS", 0, 1, 2, &baseline);
                    org.x = rdp.x - text_size.width / 2;
                    org.y = rdp.y + text_size.height / 2;
                    putText(current_img,"MISS", org, 0,1,Scalar(0,0,255),2);
                    score -= 500;
          }
     }
}

void generate_circle(){
          clicked = 0;
          setMouseCallback("OUS!", CallBackFunc, NULL);
          namedWindow("OUS!");
          rdp = generate_rand_point();
          char score_str[20];
          sprintf( score_str,"%d", score );
          rectangle( current_img, Point( 0,0 ), Point( 1920,1080 ), Scalar(255,255,255), -1 );
          putText( current_img, score_str, Point( 40,40 ), 1, 3, Scalar(0,0,0),3  );
          circle( current_img, rdp, 100, Scalar(36,36,75), 3 );
          r = 150;
          while( r > 99 ){
                    circle( current_img, rdp, r, Scalar(255,255,255), 3 );
                    circle( current_img, rdp, r-=1, Scalar(127,127,235), 3 );
                    imshow("OUS!",current_img);
                    waitKey(delay);
          }
          if( clicked == 0 ){
                    Point org;
                    printf("MISS\n");
                    int baseline;
                    Size text_size = getTextSize("MISS", 0, 1, 2, &baseline);
                    org.x = rdp.x - text_size.width / 2;
                    org.y = rdp.y + text_size.height / 2;
                    putText(current_img,"MISS", org, 0,1,Scalar(0,0,255),2);
                    score -= 500;
                    imshow("OUS!",current_img);
                    waitKey(delay);
          }
          else{
                    imshow("OUS!",current_img);
                    waitKey(delay);
          }
          circle( current_img, rdp, 150, Scalar(255,255,255),-1 );
          if( current == 1){
                    current_img = img2;
                    current = 2;
          }
          else current_img = img;
}
