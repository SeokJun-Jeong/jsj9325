#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>
#include <chrono>
#include <thread>
#include <vector>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

int main()
{
    VideoCapture cap(0);
    // Mat img = imread(folderPath + "lenna.bmp",IMREAD_GRAYSCALE); 
    Mat img, edge;
    int low_v, high_v;
    namedWindow("img1");
    
    createTrackbar("lowedge", "img1", &low_v, 255);
    createTrackbar("highedge", "img1", &high_v, 255);


    //vector img show 
    while (true)
    {
        cap >> img;
        Canny(img, edge, low_v,high_v);
        imshow("img", edge);
        waitKey(33);  
    }

        destroyAllWindows();
        
        return 0;
    }