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
    int w = cvRound(cap.get(CAP_PROP_FRAME_WIDTH));
    int h = cvRound(cap.get(CAP_PROP_FRAME_HEIGHT));
    double fps = cap.get(CAP_PROP_FPS);
    int fourcc = VideoWriter::fourcc('D', 'I', 'V', 'X');

    VideoWriter outputvideo(folderPath + "inverse_vtest.avi", fourcc, fps, Size(w,h));
    if (!outputvideo.isOpened())
    {
        cerr << "파일 생성 실패" << endl;
        return -1;
    }

    Mat frame;
    while (true)
    {
        cap >> frame;
        frame = ~frame; //반전
        if(frame.empty())
        {
            break;  //마지막 프레임 처리
        }
        outputvideo << frame;
        imshow("frame", frame); 
        if (waitKey(1000/fps) == 27) //fps조절 숫자 
        {
            break;
        }
    }
    cap.release();
    outputvideo.release();
    destroyAllWindows();

    return 0;
}