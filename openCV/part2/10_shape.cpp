#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";


int main()
{
    Mat img(400, 600, CV_8UC3, white);
    
    int a=0,b=0,c=9;

    while(true)
    {
        img.setTo(white);  //배경
        line(img, Point(50,50), Point(200+a,100+a), blue, 3, LINE_AA);
        line(img, Point(70,70), Point(220,120), blue, 3, LINE_4);
        line(img, Point(90,90), Point(240,140), blue, 3, LINE_8);
        
        arrowedLine(img, Point(110,110), Point(260,160), green, 3, LINE_8);
        arrowedLine(img, Point(130,130), Point(280,180), green, 3, LINE_8, 0, 0.05);
        
        drawMarker(img, Point(50+a, 200+b), cyan, MARKER_CROSS);
        drawMarker(img, Point(50,220), black, MARKER_DIAMOND);
        drawMarker(img, Point(50,240), pink, MARKER_STAR);

        rectangle(img, Rect(50, 250, 50+c , 50+c), red, 2, LINE_AA); //2 = 안이 빔
        rectangle(img, Rect(50, 300, 50, 50), black, -1, LINE_AA); //1 = 안이 꽉참
        
        circle(img, Point(150, 300), 50, cyan, -1, LINE_AA);  //덮여 있을 경우 늦게 들어온것이 위로 가있음
        circle(img, Point(150, 250), 50, yellow, 2, LINE_AA); 
        
        ellipse(img, Point(400, 50), Size(60,30), 20, 0, 0+c, blue, FILLED, LINE_AA);
    
        imshow("img", img);
        if(waitKey(33) == 27)
        {
            break;
        }
        a += 1;
        b -= 1;
        c += 3;
    }

    destroyAllWindows();
    return 0;
}