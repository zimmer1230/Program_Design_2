#include<bits/stdc++.h>
#include<opencv2/opencv.hpp>

using namespace std;
using namespace cv;

int boardx = 1000,boardy = 600,last_health = 3,IDT = 1;
Mat img(boardy,boardx,CV_8UC3,Scalar(255,255,255));
Mat nextimg;
Point line_previouspt1 = Point(435,535),line_previouspt2 = Point(565,535);
Point cir_pre = Point(500,522);
#define WINDOW "wid"

typedef struct Ball Ball;
struct Ball{
    float radius;
    float Vx,Vy;
    float Px,Py;
};
Ball ball;

typedef struct block block;
struct block{
    int start[2],finish[2];
};
block blocks[12];

int idt =0,Pxline;

int last_blocks[12] ;

void On_mouse(int event, int x, int y, int flags, void*);
void break_blocks(Ball ball,block blocks[]);
int main()
{
    img.copyTo(nextimg);
    namedWindow(WINDOW);
    line(img,Point(435,535),Point(565,535),Scalar(0,0,0),3);
    circle(img,Point(500,522),10,Scalar(255,255,0),-1);
    int length = 150,width = 50;
    for(int i=0;i<12;i++)
    {
        if(i < 4)
        {
            blocks[i].start[0] = 140+190*i,blocks[i].start[1] = 35;
            blocks[i].finish[0] = 140+190*i+length,blocks[i].finish[1] = 35+width;

                   // rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
        }
        else if(i >= 4 && i <8)
        {
            blocks[i].start[0] = 140+190*(i-4),blocks[i].start[1] = 185;
            blocks[i].finish[0] = 140+190*(i-4)+length,blocks[i].finish[1] = 185+width;
                    //rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
        }
        else
        {
            blocks[i].start[0] = 140+190*(i-8),blocks[i].start[1] = 335;
            blocks[i].finish[0] = 140+190*(i-8)+length,blocks[i].finish[1] = 335+width;
                   // rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
        }
       // cout << " start = ( " << blocks[i].start[0] << "," << blocks[i].start[1] << " ) finish = ( " << blocks[i].finish[0] << "," << blocks[i].finish[1] << " )\n";
        rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
    }
    ball.radius = 10 , ball.Vx = 0 , ball.Vy = -300 , ball.Px = 500 , ball.Py = 522;

    rectangle(img,Point(0,0),Point(95,60),Scalar(255,255,255),-1);
    putText(img,string("Health"), Point(5,30), 0, 1, Scalar(0,0,0),2);
    circle(img,Point(25,50),7,Scalar(0,0,255),-1);
    circle(img,Point(55,50),7,Scalar(0,0,255),-1);
    circle(img,Point(85,50),7,Scalar(0,0,255),-1);

    for(int i=0;i<12;i++)
            last_blocks[i] = 1;
    imshow(WINDOW,img);
    setMouseCallback(WINDOW, On_mouse, 0);
    waitKey(0);
}
/*
void break_blocks()
{
   // cout << " ( " << ball.Px << "," << ball.Py << " ) \n";
    for(int i=0;i<12;i++)
    {
        if(last_blocks[i])
        {
            cout <<"Y";
          if ( ( ball.Px >= blocks[i].start[0]) && ( ball.Px <= blocks[i].finish[0]) )
            {
                cout << " { " << i << " } ";
                if( ball.Py < blocks[i].start[1] && ball.Py + ball.radius >= blocks[i].start[1] )
                {
                    rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                    ball.Py = blocks[i].start[1]-ball.radius;
                    ball.Vy = -ball.Vy;
                    last_blocks[i] = 0;
                    return ;
                }
                else if( ball.Py  > blocks[i].finish[1] && ball.Py - ball.radius <= blocks[i].finish[1] )
                {
                    rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                    ball.Py = blocks[i].finish[1]+ball.radius;
                    ball.Vy = -ball.Vy;
                    last_blocks[i] = 0;
                    return ;
                }
            }
            else if( ball.Py - ball.radius >= blocks[i].start[1] && ball.Py + ball.radius >= blocks[i].finish[1] )
                {
                                    cout << " { " << i << " } ";
                    if( ball.Px < blocks[i].start[0] && ball.Px + ball.radius >= blocks[i].start[0] )
                    {
                        rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                        ball.Px = blocks[i].start[0]-ball.radius;
                        ball.Vx = -ball.Vx;
                        last_blocks[i] = 0;
                        return ;
                    }
                    else if( ball.Px > blocks[i].finish[0] && ball.Px - ball.radius <= blocks[i].finish[0] )
                    {
                        rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                        ball.Px = blocks[i].finish[0]+ball.radius;
                        ball.Vx = -ball.Vx;
                        last_blocks[i] = 0;
                        return ;
                    }
                }
        }
    }
    return ;
}*/

void On_mouse(int event, int x, int y, int flags, void*)
{
    if(IDT)
    {
        if(event == EVENT_LBUTTONDBLCLK)
        {
            ball.Vx = 2* ball.Vx;
            ball.Vy = 2*ball.Vy;
        }

        if(event == EVENT_RBUTTONDOWN)
        {
            ball.Vx = 0.5 * ball.Vx;
            ball.Vy = 0.5 * ball.Vy;
        }

        if(event == EVENT_MOUSEMOVE)
        {
            line(img,line_previouspt1,line_previouspt2,Scalar(255,255,255),3);
            if(!idt)
                circle(img,cir_pre,10,Scalar(255,255,255),-1);
            if(x-65 < 0)
                x = 65;
            else if(x+65 > 1000)
                x = 935;
            line(img,Point(x-65,535),Point(x+65,535),Scalar(0,0,0),3);
            line_previouspt1 = Point(x-65,535);
            line_previouspt2 = Point(x+65,535);
            Pxline = x;

            if(!idt)
            {
                circle(img,Point(x,522),10,Scalar(255,255,0),-1);
                ball.Px = x,ball.Py = 522;
                cir_pre = Point(x,522);
            }
            imshow(WINDOW,img);
        }
        if(event == EVENT_LBUTTONDOWN)
        {
            cout << "UUUUU";
            idt = 1;
            float dt = 1.0/60.0;
            while(idt)
            {
               // setMouseCallback(WINDOW,mouse,0);

                circle(img,Point(ball.Px,ball.Py),ball.radius,Scalar(255,255,255),-1);
                ball.Px += ball.Vx*dt;
                ball.Py += ball.Vy*dt;

                if(ball.Px - ball.radius <= 0)
                {
                    ball.Px = ball.radius;
                    ball.Vx = -ball.Vx;
                }
                if(ball.Px + ball.radius >= boardx)
                {
                    ball.Px = 1000 - ball.radius;
                    ball.Vx = -ball.Vx;
                }
                if(ball.Py - ball.radius <= 0)
                {
                    ball.Py = ball.radius;
                    ball.Vy = -ball.Vy;
                }
                if((ball.Py + ball.radius) >= 532 && (ball.Py + ball.radius) <= 538)
                {
                    if((ball.Px + ball.radius) >= Pxline - 65 && (ball.Px - ball.radius) <= Pxline + 65)
                    {
                        line(img,Point(Pxline-65,535),Point(Pxline+65,535),Scalar(0,0,0),3);
                        imshow(WINDOW,img);
                        if(ball.Px < Pxline)
                        {
                          /*  if(ball.Vx < 0)
                            {
                               ball.Vy = -70;
                            }
                            else
                            {
                                ball.Vx = -70;
                                ball.Vy = -70;
                            }*/
                                float changex = (ball.Px - Pxline + 65) * (250.0/65.0) ;
                                ball.Vx = changex-250;
                                float changey = (ball.Px - Pxline + 75) * (300.0/65.0) ;
                                ball.Vy = -changey;
                        }
                        else if(ball.Px > Pxline)
                        {
                           /* if(ball.Vx < 0)
                            {
                                ball.Vx = 70;
                                ball.Vy = -70;
                            }
                            else
                            {
                                ball.Vy = -70;
                            }*/
                            float changex = (ball.Px - Pxline) * (250.0/65.0);
                            ball.Vx = changex;
                            float changey = (ball.Px - Pxline) * (300.0/75.0) ;
                            ball.Vy = -300 + changey;
                        }
                        else if(fabs(ball.Px - Pxline) < 1e-6)
                        {
                           ball.Vx = 0;
                           ball.Vy = -300;
                        }
                    }
                }
                else
                {
                    if(ball.Py+ball.radius >= boardy)
                    {
                            //cout << "YYY";

                        last_health--;

                        if(last_health == 2)
                        {
                            circle(img,Point(85,50),7,Scalar(255,255,255),-1);
                            imshow(WINDOW,img);
                        }
                        else if(last_health == 1)
                        {
                            circle(img,Point(55,50),7,Scalar(255,255,255),-1);
                            imshow(WINDOW,img);
                        }
                        if(last_health == 0)
                        {
                            circle(img,Point(25,50),7,Scalar(255,255,255),-1);
                            putText(img,string("You Lose !"), Point(280,300), 0, 3, Scalar(0,0,0),5);
                            IDT = 0;
                            rectangle(img,Point(800,500),Point(940,560),Scalar(0,0,0),2);
                            putText(img,string("Restart"), Point(810,540), 0, 1, Scalar(0,0,0),2);
                            imshow(WINDOW,img);
                        }
                        idt = 0;
                        ball.Vx = 0;
                        ball.Vy = -300;
                        continue;
                    }
                }

                if(ball.Px - ball.radius <= 95 && ball.Px + ball.radius >= 0 && ball.Py - ball.radius <= 60 && ball.Py + ball.radius >= 0)
                {
                    rectangle(img,Point(0,0),Point(95,60),Scalar(255,255,255),-1);
                    putText(img,string("Health"), Point(5,30), 0, 1, Scalar(0,0,0),2);
                    if(last_health == 3)
                    {
                        circle(img,Point(25,50),7,Scalar(0,0,255),-1);
                        circle(img,Point(55,50),7,Scalar(0,0,255),-1);
                        circle(img,Point(85,50),7,Scalar(0,0,255),-1);
                    }
                    else if(last_health == 2)
                    {
                        circle(img,Point(25,50),7,Scalar(0,0,255),-1);
                        circle(img,Point(55,50),7,Scalar(0,0,255),-1);
                    }
                    else if(last_health == 1)
                    {
                        circle(img,Point(25,50),7,Scalar(0,0,255),-1);
                    }
                    imshow(WINDOW,img);
                }

                // break_blocks();

                for(int i=0;i<12;i++)
                {
                   // cout << " i = " << i  << "->" << last_blocks[i] << " ";
                    if(last_blocks[i])
                    {
                        if ( ( ball.Px >= blocks[i].start[0]) && ( ball.Px <= blocks[i].finish[0]) )
                        {
                           // cout << " { " << i << " } ";
                            if( ball.Py < blocks[i].start[1] && ball.Py + ball.radius >= blocks[i].start[1] )
                            {
                                rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                                ball.Py = blocks[i].start[1]-ball.radius;
                                ball.Vy = -ball.Vy;
                                last_blocks[i] = 0;
                                i = 12;
                            }
                            else if( ball.Py  > blocks[i].finish[1] && ball.Py - ball.radius <= blocks[i].finish[1] )
                            {
                                rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                                ball.Py = blocks[i].finish[1]+ball.radius;
                                ball.Vy = -ball.Vy;
                                last_blocks[i] = 0;
                                i = 12;
                            }
                        }
                        else if( ball.Py >= blocks[i].start[1] && ball.Py <= blocks[i].finish[1] )
                        {
                                           // cout << " { " << i << " } ";
                            if( ball.Px < blocks[i].start[0] && ball.Px + ball.radius >= blocks[i].start[0] )
                            {
                                rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                                ball.Px = blocks[i].start[0]-ball.radius;
                                ball.Vx = -ball.Vx;
                                last_blocks[i] = 0;
                                i = 12;
                            }
                            else if( ball.Px > blocks[i].finish[0] && ball.Px - ball.radius <= blocks[i].finish[0] )
                            {
                                rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                                ball.Px = blocks[i].finish[0]+ball.radius;
                                ball.Vx = -ball.Vx;
                                last_blocks[i] = 0;
                                i = 12;
                            }
                        }
                        else
                        {
                                if( ( ball.Px - ball.radius <= blocks[i].finish[0] && ball.Py - ball.radius <= blocks[i].finish[1] && ball.Px - ball.radius >= blocks[i].start[0] && ball.Py - ball.radius >= blocks[i].start[1] )
                                    || ( ball.Px - ball.radius <= blocks[i].finish[0] && ball.Py + ball.radius >= blocks[i].start[1] && ball.Px - ball.radius >= blocks[i].start[0] && ball.Py + ball.radius <= blocks[i].finish[1] )
                                    || ( ball.Px + ball.radius >= blocks[i].start[0] && ball.Py - ball.radius <= blocks[i].finish[1] && ball.Px + ball.radius <= blocks[i].finish[0] && ball.Py - ball.radius >= blocks[i].start[1] )
                                    || ( ball.Px + ball.radius >= blocks[i].start[0] && ball.Py + ball.radius >= blocks[i].start[1] && ball.Px + ball.radius <= blocks[i].finish[0] && ball.Py + ball.radius <= blocks[i].finish[1] )
                                )
                                {
                                    rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(255,255,255),-1);
                                    ball.Vx = -ball.Vx;
                                    ball.Vy = -ball.Vy;
                                    last_blocks[i] = 0;
                                    i = 12;
                                }
                        }
                    }
                }

                int idtt = 1;
                for(int i=0;i<12;i++)
                {
                    if(last_blocks[i])
                    {
                        idtt = 0;
                        i = 12;
                    }
                }
                if(idtt)
                {
                  putText(img, std::string("VICTORY"), Point(320,300), 0, 3, Scalar(0,0,0),5);
                   idt = 0;

                   continue;
                }

                circle(img,Point(ball.Px,ball.Py),ball.radius,Scalar(255,255,0),-1);

                imshow(WINDOW,img);
                waitKey(1);
            }

        }
    }
    else
    {
        if(event == EVENT_LBUTTONDOWN)
        {
            if(x >= 800 && x <= 940 && y >= 500 && y <= 560)
            {

                rectangle(img,Point(800,500),Point(940,560),Scalar(255,255,0),-1);
                putText(img,string("Restart"), Point(810,540), 0, 1, Scalar(0,0,0),2);
                imshow(WINDOW,img);
                waitKey(60);
                rectangle(img,Point(800,500),Point(940,560),Scalar(255,255,255),-1);
                rectangle(img,Point(800,500),Point(940,560),Scalar(0,0,0),2);
                putText(img,string("Restart"), Point(810,540), 0, 1, Scalar(0,0,0),2);
                imshow(WINDOW,img);
                waitKey(60);

                nextimg.copyTo(img);
                imshow(WINDOW,img);

                int length = 150,width = 50;
                for(int i=0;i<12;i++)
                {
                    if(i < 4)
                    {
                        blocks[i].start[0] = 140+190*i,blocks[i].start[1] = 35;
                        blocks[i].finish[0] = 140+190*i+length,blocks[i].finish[1] = 35+width;

                               // rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
                    }
                    else if(i >= 4 && i <8)
                    {
                        blocks[i].start[0] = 140+190*(i-4),blocks[i].start[1] = 185;
                        blocks[i].finish[0] = 140+190*(i-4)+length,blocks[i].finish[1] = 185+width;
                                //rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
                    }
                    else
                    {
                        blocks[i].start[0] = 140+190*(i-8),blocks[i].start[1] = 335;
                        blocks[i].finish[0] = 140+190*(i-8)+length,blocks[i].finish[1] = 335+width;
                               // rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
                    }
                   // cout << " start = ( " << blocks[i].start[0] << "," << blocks[i].start[1] << " ) finish = ( " << blocks[i].finish[0] << "," << blocks[i].finish[1] << " )\n";
                    rectangle(img,Point(blocks[i].start[0],blocks[i].start[1]),Point(blocks[i].finish[0],blocks[i].finish[1]),Scalar(0,255,255),-1);
                }
                for(int i=0;i<12;i++)
                    last_blocks[i] = 1;

                line(img,Point(435,535),Point(565,535),Scalar(0,0,0),3);
                line_previouspt1 = Point(435,535),line_previouspt2 = Point(565,535);
                circle(img,Point(500,522),10,Scalar(255,255,0),-1);
                cir_pre = Point(500,522);
                ball.radius = 10 , ball.Vx = 0 , ball.Vy = -300 , ball.Px = 500 , ball.Py = 522;

                putText(img,string("Health"), Point(5,30), 0, 1, Scalar(0,0,0),2);
                circle(img,Point(25,50),7,Scalar(0,0,255),-1);
                circle(img,Point(55,50),7,Scalar(0,0,255),-1);
                circle(img,Point(85,50),7,Scalar(0,0,255),-1);

                IDT = 1;
                last_health = 3;
            }
        }
    }

}
