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
    Mat img, edge;
    int low_v, high_v, h_threshold;
    namedWindow("img1");
    createTrackbar("lowedge", "img1", &low_v, 255);
    createTrackbar("highedge", "img1", &high_v, 255);
    createTrackbar("h_threshold", "img1", &h_threshold, 255);
    // vector<Vec2f> lines;
    vector<Vec4i> lines;
    Point pt1, pt2;
    float rho, cos_t, sin_t, y0, x0, alpha, theta;

    //vector img show 
    while (true)
        {
            cap >> img;
            Canny(img, edge, low_v,high_v);
            HoughLinesP(edge, lines, 1, CV_PI / 180, h_threshold, 50, 5);
            // HoughLines(edge, lines, 1, CV_PI/180, h_threshold);
            // // 극좌표 -> 작교좌표
            // for (size_t i = 0; i < lines.size(); ++i)
            // {
            //     rho = lines[i][0];
            //     theta = lines[i][1];
            //     cos_t = cos(theta);
            //     sin_t = sin(theta);
            //     x0 = rho * cos_t;
            //     y0 = rho * sin_t;
            //     alpha = 1000;
            //     pt1.x = cvRound(x0 - alpha * sin_t);
            //     pt1.y = cvRound(y0 + alpha * cos_t);
            //     pt2.x = cvRound(x0 + alpha * sin_t);
            //     pt2.y = cvRound(y0 - alpha * cos_t);
            //     line(img, pt1, pt2, red, 2, LINE_AA);
            // }
            for (auto l : lines)
            {
                line(img, Point(l[0], l[1]), Point(l[2], l[4]), red, 2, LINE_AA);
            }
            // line(img, Point(lines[0]), pt2, red, 2, LINE_AA);
            imshow("img1", edge);
            imshow("img", img);
            if (waitKey(33) == 27)
            {
                break;
            }
            
        }
        destroyAllWindows();   
        return 0;
    }