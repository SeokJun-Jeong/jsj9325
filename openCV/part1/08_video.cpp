#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

int main()
{
    VideoCapture cap (folderPath + "vtest.avi");
    Mat frame;
    while (true)
    {
        cap >> frame;
        imshow("frame", frame);
        if (waitKey(33) == 27) //fps조절 숫자 (esc)
        {
            break;
        }
        
    }
    
    return 0;
}