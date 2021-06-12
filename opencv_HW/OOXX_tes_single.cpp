#include <stdio.h>
#include <iostream>
#include <opencv2/opencv.hpp>
using namespace cv;
using namespace std;

Mat img(900, 900, CV_8UC3, Scalar(255,255,255)); //8 unsigned int channel 3
Mat fin(300,900, CV_8UC3, Scalar(255,255,255));

int table[3][3]; //cur
void show_table(int table[3][3]);

int judge(int table[3][3]);
int min_max_search(int,int[3][3]);
int which_frame(Point pt);
int which_frame(int,int);
void CallBackFunc(int event, int x, int y, int flags, void* userdata);

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



void show_table(int table[3][3]){
          for(int i=0;i<3;i++){
                    for(int j=0;j<3;j++){
                              if( table[i][j] == 8 ){
                                        switch( which_frame(i,j) ){
                                                  case 1:
                                                            circle( img, Point( 150,150 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 2:
                                                            circle( img, Point( 450,150 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 3:
                                                            circle( img, Point( 750,150 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 4:
                                                            circle( img, Point( 150,450 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 5:
                                                            circle( img, Point( 450,450 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 6:
                                                            circle( img, Point( 750,450 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 7:
                                                            circle( img, Point( 150,750 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 8:
                                                            circle( img, Point( 450,750 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  case 9:
                                                            circle( img, Point( 750,750 ), 50, Scalar( 0,0,0 ), 3 );
                                                            break;
                                                  default:
                                                            break;
                                        }
                              }
                              else if( table[i][j] == 1 ){
                                        switch( which_frame(i,j) ){
                                        case 1:
                                                  line( img,Point( 150+50,150+50 ), Point(150-50, 150-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 150+50,150-50 ), Point(150-50, 150+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 2:
                                                  line( img,Point( 450+50,150+50 ), Point(450-50, 150-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 450+50,150-50 ), Point(450-50, 150+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 3:
                                                  line( img,Point( 750+50,150+50 ), Point(750-50,150-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 750+50,150-50 ), Point(750-50, 150+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 4:
                                                  line( img,Point( 150+50,450+50 ), Point(150-50, 450-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 150+50,450-50 ), Point(150-50, 450+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 5:
                                                  line( img,Point( 450+50,450+50 ), Point(450-50, 450-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 450+50,450-50 ), Point(450-50, 450+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 6:
                                                  line( img,Point( 750+50,450+50 ), Point(750-50, 450-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 750+50,450-50 ), Point(750-50, 450+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 7:
                                                  line( img,Point( 150+50,750+50 ), Point(150-50, 750-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 150+50,750-50 ), Point(150-50, 750+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 8:
                                                  line( img,Point( 450+50,750+50 ), Point(450-50, 750-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 450+50,750-50 ), Point(450-50, 750+50), Scalar(0,0,0), 3 );
                                                  break;
                                        case 9:
                                                  line( img,Point( 750+50,750+50 ), Point(750-50, 750-50), Scalar(0,0,0), 3 );
                                                  line( img,Point( 750+50,750-50 ), Point(750-50, 750+50), Scalar(0,0,0), 3 );
                                                  break;
                                        default:
                                                  break;
                                        }

                              }
                    }
          }
          imshow("death is like windows",img);
}
void copy_table(int source[3][3], int target[3][3]){
          for(int i=0; i<3; i++){
                    for( int j=0; j<3; j++){
                              target[i][j] = source[i][j];
                    }
          }
}

int judge(int table[3][3]){  // return 1 : O win ; 0 : Tie ; -1 : X win
          int O_win = 0, X_win = 0;
          int sum = 0;
          for( int i = 0; i<3; i++ ){
                    sum = 0;
                    for( int j = 0; j<3; j++ ){
                              sum += table[i][j];
                    }
                    if ( sum == 24 ){
                              O_win = 1;
                              break;
                    }
                    else if( sum == 3 ){
                              X_win = 1;
                              break;
                    }
          }
          if ( O_win == 0 && X_win == 0 ){
                    for( int i = 0; i<3; i++ ){
                              sum = 0;
                              for( int j = 0; j<3; j++ ){
                                        sum += table[j][i];
                              }
                              if ( sum == 24 ){
                                        O_win = 1;
                                        break;
                              }
                              else if( sum == 3 ){
                                        X_win = 1;
                                        break;
                              }
                    }
          }
          if( O_win == 0 && X_win == 0 ){
                    sum = 0;
                    sum = table[0][0] + table[1][1] + table [2][2];
                    if ( sum == 24 ){
                              O_win = 1;
                    }
                    else if( sum == 3 ){
                              X_win = 1;
                    }
          }
          if( O_win == 0 && X_win == 0 ){
                    sum = 0;
                    sum = table[2][0] + table[1][1] + table [0][2];
                    if ( sum == 24 ){
                              O_win = 1;
                    }
                    else if( sum == 3 ){
                              X_win = 1;
                    }
          }



          if( O_win ){
                    return 1;
          }
          else if( X_win ){
                    return -1;
          }
          else return 0;
}

#define min 1
#define max 8
int min_max_search(int node_type, int table[3][3]){ // return the score of table[][]
          if( judge(table) == 1 || judge(table) == -1 ) return judge(table);
          int gaming = 0;
          for( int i = 0; i<2; i++ ){
                    for( int j=0; j<2; j++ ){
                              if( table[i][j]==0 ){
                                        gaming = 1;
                              }
                    }
          }
          if ( gaming == 0 ) return 0;
//---------------------------------
          int tmp_table[3][3];
          int k;
          if( node_type == min ){
                    k = 2;
                    int result;
                    for( int i=0;i<3;i++ ){
                              for(int j = 0; j<3; j++){
                                        if ( table[i][j] == 0 ){
                                                  table[i][j] = node_type; // 1
                                                  if( k > ( result = min_max_search(max,table) ) ){
                                                            k = result;
                                                            table[i][j] = 0;
                                                            copy_table(table,tmp_table);
                                                            tmp_table[i][j] = node_type;
                                                  }
                                                  table[i][j] = 0;
                                        }
                              }
                    }
          }
          else if( node_type == max ){
                    k = -2;
                    int result;
                    for( int i=0;i<3;i++ ){
                              for(int j = 0; j<3; j++){
                                        if ( table[i][j] == 0 ){
                                                  table[i][j] = node_type; // 8
                                                  if( k < ( result = min_max_search(max,table) ) ){
                                                            k = result;
                                                            table[i][j] = 0;
                                                            copy_table(table,tmp_table);
                                                            tmp_table[i][j] = node_type;
                                                  }
                                                  table[i][j] = 0;
                                        }
                              }
                    }
          }
          return k;
}

/*        1        2         3
           4        5         6
           7        8         9
*/

int which_frame(Point pt){
          if( pt.y < 300 ){
                    if( pt.x < 300 ) return 1;
                    if (pt.x < 600 ) return 2;
                    else return 3;
          }
          if( pt.y < 600 ){
                    if( pt.x < 300 ) return 4;
                    if (pt.x < 600 ) return 5;
                    else return 6;
          }
          else {
                    if( pt.x < 300 ) return 7;
                    if (pt.x < 600 ) return 8;
                    else return 9;
          }
}
int which_frame(int i, int j){
          if( i == 0 ){
                    if( j == 0 ) return 1;
                    else if( j == 1 ) return 2;
                    else if ( j == 2 ) return 3;
          }
          else if( i == 1 ){
                    if( j == 0 ) return 4;
                    if( j == 1 ) return 5;
                    if( j == 2 ) return 6;
          }
          else{
                    if( j == 0 ) return 7;
                    if( j == 1 ) return 8;
                    if ( j ==2 ) return 9;
          }
          return 87;
}

void CallBackFunc(int event, int x, int y, int flags, void* userdata)
{
     Point pt1;
    // when LeftMouseButton click
     if  ( event == EVENT_LBUTTONDOWN )
     {
          pt1 = Point(x,y);
          cout << "Left button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;
          switch( which_frame(pt1) ){
          case 1:
                    if( table[0][0] != 0 )
                              break;
                    table[0][0] = 8;
                    break;
          case 2:
                    if( table[0][1] != 0 )
                              break;
                    table[0][1] = 8;
                    break;
          case 3:
                    if( table[0][2] != 0 )
                              break;
                    table[0][2] = 8;
                    break;
          case 4:
                    if( table[1][0] != 0 )
                              break;
                    table[1][0] = 8;
                    break;
          case 5:
                    if( table[1][1] != 0 )
                              break;
                    table[1][1] = 8;
                    break;
          case 6:
                    if( table[1][2] != 0 )
                              break;
                    table[1][2] = 8;
                    break;
          case 7:
                    if( table[2][0] != 0 )
                              break;
                    table[2][0] = 8;
                   break;
          case 8:
                    if( table[2][1] != 0 )
                              break;
                    table[2][1] = 8;
                    break;
          case 9:
                    if( table[2][2] != 0 )
                              break;
                    table[2][2] = 8;
                    break;
          default:
                    break;
          }
          show_table(table);
          waitKey(1000);

          if( judge(table) == 1 ) printf("O wins\n");
          if( judge(table) == -1 ) printf("X wins\n");

          int tmp_table[3][3]={};
          copy_table(table,tmp_table);

          int k = 2; // unsigned
          int result;
          for( int i=0; i<3; i++ ){
                    for( int j = 0; j<3; j++ ){
                              if( table[i][j] == 0 ){
                                        table[i][j]=1;
                                        if( k > ( result = min_max_search(min,table) ) ){
                                                  k = result;
                                                  table[i][j] = 0;
                                                  copy_table(table,tmp_table);
                                                  tmp_table[i][j] = 1;
                                        }
                                        table[i][j] = 0;
                              }
                    }
          }
          copy_table(tmp_table,table);
          for(int i = 0; i<3; i++){
                    for(int j=0; j<3; j++){
                              printf("%d ",table[i][j]);
                    }
                    printf("\n");
          }
          show_table(table);


     }
}

