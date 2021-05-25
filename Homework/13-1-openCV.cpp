
#include <cstdio>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc/imgproc.hpp>

using namespace cv;

int main(){

    //�Ыصe�O���e���]480*720�^    scalar�C��BGR�]255,255,255�^��
    Mat img(480, 720, CV_8UC3, Scalar(255,255,255));


    //�e�O���W���y�Ь�(0,0)


    //�⪽�u��X��e�O�W
    //���I����m[point(20,40), point(120.140)]
    //const scalar(255,0,0) �Ŧ�
    //thickness = 3   �u���e�ס]���o��0�^
    line(img, Point(20,40), Point(120,140), Scalar(255,0,0), 3);


    //�����ο�X��e�O�W
    //����ӹ﨤�I
    //const scalar�]0,0,255�^ ����
    //int thickness = -1�]�u���e�סA�t�ƪ�ܶ񺡹ϧ�)
    rectangle(img, Point(150,40), Point(250,140), Scalar(0,0,255), -1);


    //���ο�X��e�O�W
    //����� point(330,90)
    //int radius�b�| = 50
    //const scalar�]0,255,0�^ ���
    //int thickness = -1�]�u���e�סA�t�ƪ�ܶ񺡹ϧ�)
    circle(img, Point(330,90), 50, Scalar(0,255,0), -1);


    //����ο�X��e�O�W
    //Point����� Point(80,280)
    //Size���b���ؤo Size�]60,40�^
    //double angle���ਤ�� = 45 ��
    //double startAngle = 0 ��꩷�_�l����
    //double endAngle = 360 ��꩷��������
    //const scalar�]255,255,0�^ ���Ŧ�
    //int thickness = 2�]�u���e�סA�t�ƪ�ܶ񺡹ϧ�)
    ellipse(img, Point(80,280), Size(60,40), 45, 0, 360, Scalar(255,255,0), 2);


    //��h��u�q��X��e�O�W
    //const points** ppt �h��Φ��u��array
    //const int* npt �h��γ��I�ƥت�array
    //int ncontours = 1 �h��Ϊ��ƥء]�]���O�]�@���}�C�ҥH�u�|�e�X�@�Ӧh��έ�n���i�H�en�ӡ^
    //bool isclosed = 1 �O�_���ʳ����h�䫬�]�]��0���ܧ��Y�����|�۳s�^
    //scalar�]280,280,0�^ ����
    //int thickness = 5 (�u���e�סA�t�ƪ�ܶ񺡹ϧ�)
    Point points[1][5];
    points[0][0] = Point(150, 270);
    points[0][1] = Point(190, 220);
    points[0][2] = Point(260, 255);
    points[0][3] = Point(224, 296);
    points[0][4] = Point(178, 316);
    const Point* ppt[1] = {points[0]};
    int npt[] = {5};
    polylines(img, ppt, npt, 1, 1, Scalar(0,255,255),5);


    //���r��X��e�O�W
    //std::string �Q�n��X����r
    //Point ��r��m�_�I�]�ѥ��U���X�o�^
    //font
    //fontFace
    //scalar (0,0,0) �¦�
    //int thickness = 3 (�u���e�סA�t�ƪ�ܶ񺡹ϧ�)
    putText(img, std::string("OpenCV"), Point(280,280), 0, 1, Scalar(0,0,0),3);

    imshow("window", img);
    waitKey(0);

    return 0;
}
