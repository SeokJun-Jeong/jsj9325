#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>
#include <cstdlib>


using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

void on_level_change(int pos, void *data);

int main()
{
    Mat img = Mat::zeros(400,400, CV_8UC3);
    namedWindow("img");
    int pos;

    createTrackbar("level", "img", &pos, 255, on_level_change, (void *)&img);
    int keycode;
    while (true)
    {
        img.setTo(pos);
        imshow("img", img);
        keycode = waitKey(33);
        if(keycode == 27)
        {
            break;
        }
    }
    
    destroyAllWindows();
    return 0;
}

void on_level_change(int pos, void *data)
{
    cout << pos << endl;
    
}


