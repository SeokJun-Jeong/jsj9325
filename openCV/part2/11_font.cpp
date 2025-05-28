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
        img.setTo(white);
        putText(img, "test Text1", Point(20+a, 50), FONT_HERSHEY_SIMPLEX, 1, red); // putText한글 안됨
        putText(img, "test Text2", Point(20+a, 100), FONT_ITALIC, 2, blue);
        putText(img, "test Text3", Point(20+a, 150), FONT_HERSHEY_DUPLEX, 3, black);
        putText(img, "test Text4", Point(20+a, 200), FONT_HERSHEY_PLAIN, 4, green);


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