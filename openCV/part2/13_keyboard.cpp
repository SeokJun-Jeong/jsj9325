#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

int main()
{
    Mat img = imread(folderPath + "lenna.bmp");
    namedWindow("img");
    auto i = getTickCount();
    int keycode;
    while (true)
    {
        keycode = waitKeya(0);
        cout << "keycode : " << keycode << endl;
        cout << "i : " << i << endl;
        cout << "fps : " << getTickFrequency() / (getTickCount() - i) << endl;

        if(keycode == 'v' || keycode == 'V')
        {
            img = ~img; //반전
        }
        if(keycode == 'a' || keycode == 'A')
        {
            img = img + 1;
        }
        if(keycode == 'd' || keycode == 'D')
        {
            img = img - 1;
        }
        if(keycode == 65364)
        {
            cout << "key up array" << endl;
        }
        if(keycode == 65362)
        {
            cout << "key down array" << endl;
        }
        imshow("img", img);
        if(keycode == 27)
        {
            break;
        }
        i = getTickCount();
    }
    
    destroyAllWindows();
    return 0;
}