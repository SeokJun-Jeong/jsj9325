#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>
#include <opencv2/freetype.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp");
    namedWindow("img");
    imshow("img", img);
    auto i = getTickCount();
    int keycode;
    while (true)
    {
        keycode = waitKey(10);
        cout << "keycode : " << keycode << endl;
        cout << "i : " << i << endl;
        cout << "fps : " << getTickFrequency() / (getTickCount() - i) << endl;

        if(keycode == 'v' || keycode == 'b')
        {
            img = ~img; //반전
            imshow("img", img);
        }
        if(keycode == 27)
        {
            break;
        }
        i = getTickCount();
    }
    
    destroyAllWindows();
    return 0;
}