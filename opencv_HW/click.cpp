#include <iostream>
#include <opencv2/opencv.hpp>
using namespace std;
using namespace cv;


//create a empty image size is 400*400, color is white
Mat img(400, 400, CV_8UC3, Scalar(255,255,255));

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

     }

    //when RightMouseButton click
     if  ( event == EVENT_RBUTTONDOWN )
     {

         //load position of RightMouseButton click
          pt2 = Point(x,y);
          cout << "Right button of the mouse is clicked - position (" << x << ", " << y << ")" << endl;

         //Draw a line between pt1 and pt2
         line(img, pt1,pt2,Scalar(255,255,0),1);

         //show the result on your window
         imshow("new window",img);
     }
}

int main(int argc, char** argv)
{
     //if fail to read the image
     if ( img.empty() )
     {
          cout << "Error loading the image" << endl;
          return -1;
     }

     //Create a window
     namedWindow("Panel Window");

     //set the callback function for any mouse event
     setMouseCallback("Panel Window", CallBackFunc, NULL);


          waitKey(0);




     return 0;

}
