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

    // Mat img = imread(folderPath + "kids.png", IMREAD_GRAYSCALE);
    // vector<Mat> images;
    // images.push_back(img);
    // images.emplace_back(img.clone());

    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "동영상 파일이 없습니다!" << endl;
        return -1;
    }

    
    
    CascadeClassifier classifier(folderPath + "haarcascade_frontalface_default.xml");
    
    vector<Rect> faces;
    Mat img;
    while (true)
    {
        cap >> img;
        classifier.detectMultiScale(img,faces);

        for (auto &rect : faces)
        {
            rectangle(img,rect,red,2);
        }
        // vector img show 코드
        int i = 1;
        imshow("img",img);
        if (waitKey(33) == 27)
        {
            break;
        }
        
    }

    destroyAllWindows();
    return 0;
}