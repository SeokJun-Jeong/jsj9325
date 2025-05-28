#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>
#include <opencv2/freetype.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";


Ptr<cv::freetype::FreeType2> rapperFreeTypeCenterSetup(const String &fontpath)
{
    Ptr<cv::freetype::FreeType2> ft2 = freetype::createFreeType2();
    ft2->loadFontData(fontpath, 0);
    return ft2;
}

void rapperFreeTypeCenter(Mat &img, Ptr<cv::freetype::FreeType2> ft2, const String &text, const int &textHeight, const int &thickness, const int &line_type, const Scalar &color, const Point &textOrg)
{
    Size textSize = ft2->getTextSize(text, textHeight, -1, 0);
    Point org((textOrg.x - textSize.width) / 2, (textOrg.y - textSize.height) / 2);
    ft2->putText(img, text, org, textHeight, color, thickness, line_type, true);
}

int main()
{
    Mat img(400, 600, CV_8UC3, white);

    int a=0, b=0, c=0;
    auto ft2 = rapperFreeTypeCenterSetup("/home/seokjun/kubig2025/openCV/data/NanumPenScript-Regular.ttf");

    String text = "씨발";

    while(true)
    {
        img.setTo(white);
        rapperFreeTypeCenter(img, ft2, text, 50,2, LINE_AA, black, Point(600,300));
        rapperFreeTypeCenter(img, ft2, "slal", 50,2, LINE_AA, red, Point(600,400));
        rapperFreeTypeCenter(img, ft2, "병신", 50,2, LINE_AA, green, Point(600,200));
        
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