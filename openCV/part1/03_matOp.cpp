#include <iostream>
#include <opencv2/opencv.hpp>

using namespace std;
using namespace cv;

String folderPath = "/home/seokjun/kubig2025/openCV/data/";

int main()
{
    Mat img;
    Mat img2(100,200,CV_8UC1); //검정
    Mat img3(100,200,CV_8UC3,Scalar(0,0,255)); //빨간색  -> rgb가아닌 bgr이다
    Mat img4(Size(600,800), CV_8UC3);
    img4.setTo(Scalar(0,255,0));
    
    // 데이터를 다뤄 행렬 연산 시
    Mat mat1 = Mat::zeros(3,3,CV_32SC1); //모두 0
    Mat mat2 = Mat::ones(3,3,CV_32FC1); //모두 1
    Mat mat3 = Mat:: eye(3,3,CV_32FC1); //대각

    cout << "mat1 : " << mat1 << endl;
    cout << "mat2 : " << mat2 << endl;
    cout << "mat3 : " << mat3 << endl;
    
    //외부 메모리 사용
    float data[] = {1,2,3,4,5,6,7,8,9,10};
    Mat mat4(2,5,CV_32FC1,data);

    cout << "mat4 : " << mat4 << endl;

    // imshow("img", img);
    imshow("img2", img2);
    imshow("img3", img3);
    imshow("img4", img4);
    waitKey();
    
    return 0;
}