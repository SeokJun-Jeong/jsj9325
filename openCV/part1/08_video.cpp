#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

int main()
{
    VideoCapture cap (folderPath + "vtest.avi");
    if (!cap.isOpened())
    {
        cerr << "동영상 파일이 없음" << endl;
        // cerr << "장치가 없음" << endl;
    }
    cout << "frame width : " <<  cvRound(cap.get(CAP_PROP_FRAME_WIDTH)) << endl;
    cout << "frame height : " <<  cvRound(cap.get(CAP_PROP_FRAME_HEIGHT)) << endl;
    auto fps = cap.get(CAP_PROP_FPS);
    cout << "fps : " <<  cvRound(fps) << endl;
    

    Mat frame;
    while (true)
    {
        cap >> frame;
        if(frame.empty())
        {
            break;  //마지막 프레임 처리
        }
        imshow("frame", frame); 
        if (waitKey(1000/fps) == 27) //fps조절 숫자 
        {
            break;
        }
    }
    cap.release();
    destroyAllWindows();
    
    return 0;
}