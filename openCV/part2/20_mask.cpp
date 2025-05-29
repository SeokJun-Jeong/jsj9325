#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

void on_mouse(int event, int x, int y, int flags, void *data);

int main()
{
    Mat img1 = imread(folderPath + "lenna.bmp");
    Mat img2 = imread(folderPath + "mask_smile.bmp", IMREAD_GRAYSCALE);
    img1.setTo(yellow,img2);
    imshow("img", img1);

    Mat airplane = imread(folderPath + "airplane.bmp");
    Mat maskairplane = imread(folderPath + "mask_plane.bmp",IMREAD_GRAYSCALE);
    Mat sky = imread(folderPath + "field.bmp");

    airplane.copyTo(sky,maskairplane);

    imshow("sky", sky);
    
    waitKey();
    destroyAllWindows();

    return 0;
}