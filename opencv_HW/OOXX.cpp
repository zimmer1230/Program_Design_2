#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat img(900, 900, CV_8UC3, Scalar(255,255,255)); //8 unsigned int channel 3
Mat fin(300,900, CV_8UC3, Scalar(255,255,255));

int who_playing = 0; // 0: O , 1: X
int table [3][3];
void judge(){
          int value = 0;
          for( int i=0; i<3; i++ ){
                    value = 0;
                    for(int j=0; j<3; j++){
                              value += table[i][j];
                    }
                    if( value == 3 ){
                              namedWindow("Finish!!");
                              putText(fin,"X wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                              imshow("Finish!!",fin);
                              waitKey(0);
                    }
                    else if( value == 24 ){
                              namedWindow("Finish!!");
                              putText(fin,"O wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                              imshow("Finish!!",fin);
                              waitKey(0);
                    }
          }
          for( int j=0; j<3; j++ ){
                    value = 0;
                    for(int i=0; i<3; i++){
                              value += table[i][j];
                    }
                    if( value == 3 ){
                              namedWindow("Finish!!");
                              putText(fin,"X wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                              imshow("Finish!!",fin);
                              waitKey(0);
                    }
                    else if( value == 24 ){
                              namedWindow("Finish!!");
                              putText(fin,"O wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                              imshow("Finish!!",fin);
                              waitKey(0);
                    }
          }

          value = 0;
          value = table[0][0] + table[1][1] + table[2][2];
          if( value == 3 ){
                    namedWindow("Finish!!");
                    putText(fin,"X wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                    imshow("Finish!!",fin);
                    waitKey(0);
          }
          else if( value == 24 ){
                    namedWindow("Finish!!");
                    putText(fin,"O wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                    imshow("Finish!!",fin);
                    waitKey(0);
          }

          value = 0;
          value = table[2][0] + table [1][1] + table [0][2];
          if( value == 3 ){
                    namedWindow("Finish!!");
                    putText(fin,"X wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                    imshow("Finish!!",fin);
                    waitKey(0);
          }
          else if( value == 24 ){
                    namedWindow("Finish!!");
                    putText(fin,"O wins !!", Point( 0, 150 ), 0, 5, Scalar(0,0,0), 3 );
                    imshow("Finish!!",fin);
                    waitKey(0);
          }



}

/*
1         4         7
2         5         8
3         6         9
*/

int which_frame(Point pt){
          if ( pt.x < 300 ){
                    if( pt.y < 300 ) return 1;
                    if (pt.y < 600 ) return 2;
                    else return 3;
          }
          if( pt.x < 600 ){
                    if( pt.y < 300 ) return 4;
                    if (pt.y < 600 ) return 5;
                    else return 6;
          }
          else {
                    if( pt.y < 300 ) return 7;
                    if (pt.y < 600 ) return 8;
                    else return 9;
          }
}



//onMouse function
void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     static Point pt1,pt2;
    // when LeftMouseButton click
     if  ( event == EVENT_LBUTTONDOWN )
     {
         //load position of LeftMouseButton click
          pt1 = Point(x,y);
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          if( who_playing == 0 ){
                    switch( which_frame(pt1) ){
                    case 1:
                              circle( img, Point( 150,150 ), 50, Scalar(0,0,0), 3 );
                              table[0][0] = 8;
                              break;
                    case 2:
                              circle( img, Point( 150,450 ), 50, Scalar(0,0,0), 3 );
                              table[0][1] = 8;
                              break;
                    case 3:
                              circle( img, Point( 150,750 ), 50, Scalar(0,0,0), 3 );
                              table[0][2] = 8;
                              break;
                    case 4:
                              circle( img, Point( 450,150 ), 50, Scalar(0,0,0), 3 );
                              table[1][0] = 8;
                              break;
                    case 5:
                              circle( img, Point( 450,450 ), 50, Scalar(0,0,0), 3 );
                              table[1][1] = 8;
                              break;
                    case 6:
                              circle( img, Point( 450,750 ), 50, Scalar(0,0,0), 3 );
                              table[1][2] = 8;
                              break;
                    case 7:
                              circle( img, Point( 750,150 ), 50, Scalar(0,0,0), 3 );
                              table[2][0] = 8;
                             break;
                    case 8:
                              circle( img, Point( 750,450 ), 50, Scalar(0,0,0), 3 );
                              table[2][1] = 8;
                              break;
                    case 9:
                              circle( img, Point( 750,750 ), 50, Scalar(0,0,0), 3 );
                              table[2][2] = 8;
                              break;
                    default:
                              break;
                    }

                    imshow("death is like windows", img);
                    judge();
          }
          if( who_playing == 1 ){
                    switch( which_frame(pt1) ){
                    case 1:
                              line( img,Point( 150+50,150+50 ), Point(150-50, 150-50), Scalar(0,0,0), 3 );
                              line( img,Point( 150+50,150-50 ), Point(150-50, 150+50), Scalar(0,0,0), 3 );
                              table[0][0] = 1;
                              break;
                    case 2:
                              line( img,Point( 150+50,450+50 ), Point(150-50, 450-50), Scalar(0,0,0), 3 );
                              line( img,Point( 150+50,450-50 ), Point(150-50, 450+50), Scalar(0,0,0), 3 );
                              table[0][1] = 1;
                              break;
                    case 3:
                              line( img,Point( 150+50,750+50 ), Point(150-50,750-50), Scalar(0,0,0), 3 );
                              line( img,Point( 150+50,750-50 ), Point(150-50, 750+50), Scalar(0,0,0), 3 );
                              table[0][2] = 1;
                              break;
                    case 4:
                              line( img,Point( 450+50,150+50 ), Point(450-50, 150-50), Scalar(0,0,0), 3 );
                              line( img,Point( 450+50,150-50 ), Point(450-50, 150+50), Scalar(0,0,0), 3 );
                              table[1][0] = 1;
                              break;
                    case 5:
                              line( img,Point( 450+50,450+50 ), Point(450-50, 450-50), Scalar(0,0,0), 3 );
                              line( img,Point( 450+50,450-50 ), Point(450-50, 450+50), Scalar(0,0,0), 3 );
                              table[1][1] = 1;
                              break;
                    case 6:
                              line( img,Point( 450+50,750+50 ), Point(450-50, 750-50), Scalar(0,0,0), 3 );
                              line( img,Point( 450+50,750-50 ), Point(450-50, 750+50), Scalar(0,0,0), 3 );
                              table[1][2] = 1;
                              break;
                    case 7:
                              line( img,Point( 750+50,150+50 ), Point(750-50, 150-50), Scalar(0,0,0), 3 );
                              line( img,Point( 750+50,150-50 ), Point(750-50, 150+50), Scalar(0,0,0), 3 );
                              table[2][0] = 1;
                              break;
                    case 8:
                              line( img,Point( 750+50,450+50 ), Point(750-50, 450-50), Scalar(0,0,0), 3 );
                              line( img,Point( 750+50,450-50 ), Point(750-50, 450+50), Scalar(0,0,0), 3 );
                              table[2][1] = 1;
                              break;
                    case 9:
                              line( img,Point( 750+50,750+50 ), Point(750-50, 750-50), Scalar(0,0,0), 3 );
                              line( img,Point( 750+50,750-50 ), Point(750-50, 750+50), Scalar(0,0,0), 3 );
                              table[2][2] = 1;
                              break;
                    default:
                              break;
                    }
                    imshow("death is like windows", img);
                    judge();
          }
          who_playing = ( who_playing == 1 )? 0 : 1;

     }


}


int main(){


//drawing table
line( img, Point( 0, 300 ), Point( 900, 300 ), Scalar(0,0,0), 3 );
line( img, Point( 0, 600 ), Point( 900, 600 ), Scalar(0,0,0), 3 );
line( img, Point( 300, 0 ), Point( 300, 900 ), Scalar(0,0,0), 3 );
line( img, Point( 600, 0 ), Point( 600, 900 ), Scalar(0,0,0), 3 );
//drawing table

namedWindow( "death is like windows" );

//set the callback function for any mouse event
setMouseCallback("death is like windows", CallBackFunc, NULL);



imshow("death is like windows", img);
waitKey(0);








return 0;
}
