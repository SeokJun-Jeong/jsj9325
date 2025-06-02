// 카메라 켜서 frame 확보
// 양방향 필터 처리
// inrange -> 색종이를 인식
// morph 함수 -> 이진화 Mat정리
// labeling 
// 화면에 rectangle로 표시
// putText, ft2로 색종이 or color-paper표시
// 사각형과 폰트는 색종이를 따라다녀야 함

#include <iostream>
#include <opencv2/opencv.hpp>
#include </home/seokjun/kubig2025/openCV/part2/color.hpp>
#include <chrono>
#include <thread>
#include <vector>
#include <opencv2/freetype.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

int main()
{
    VideoCapture cap(0);
    if (!cap.isOpened())
    {
        cerr << "동영상 파일이 없습니다!" << endl;
        return -1;
    }


    Mat frame, blurred, hsv, mask, morph, labels, stats, centroids;
    Mat kernel = getStructuringElement(MORPH_RECT, Size(5, 5));

    // HSV에서 찾고자 하는 색 범위 (예: 파란색)
    Scalar lower_color(100, 100, 100);
    Scalar upper_color(140, 255, 255);

    while (true) {
        cap >> frame;
        if (frame.empty()) break;

        // 양방향 필터
        bilateralFilter(frame, blurred, 9, 75, 75);

        // HSV 변환 및 마스크
        cvtColor(blurred, hsv, COLOR_BGR2HSV);
        inRange(hsv, lower_color, upper_color, mask);

        // 모폴로지 (노이즈 제거)
        morphologyEx(mask, morph, MORPH_OPEN, kernel);

        // 라벨링
        int nLabels = connectedComponentsWithStats(morph, labels, stats, centroids);

        for (int i = 1; i < nLabels; ++i) {
            int area = stats.at<int>(i, CC_STAT_AREA);
            if (area < 500) continue;

            int left = stats.at<int>(i, CC_STAT_LEFT);
            int top = stats.at<int>(i, CC_STAT_TOP);
            int width = stats.at<int>(i, CC_STAT_WIDTH);
            int height = stats.at<int>(i, CC_STAT_HEIGHT);
            Point center(centroids.at<double>(i, 0), centroids.at<double>(i, 1));

            // 사각형 및 텍스트 표시
            rectangle(frame, Rect(left, top, width, height), Scalar(0, 0, 255), 2);
            putText(frame, "color-paper", Point(left, top - 10), FONT_HERSHEY_SIMPLEX, 0.7, Scalar(0, 255, 0), 2, LINE_AA);
        }

        imshow("Detected", frame);
        imshow("Mask", morph);

        if (waitKey(30) == 27) break; // ESC 키
    }

    cap.release();
    destroyAllWindows();
    return 0;
}