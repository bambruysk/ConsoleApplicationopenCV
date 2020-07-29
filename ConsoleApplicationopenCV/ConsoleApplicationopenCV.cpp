#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
#include <opencv2/imgproc.hpp>
    //#include <opencv2/imgproc/imgproc.hpp>
    //#include "opencv2/imgcodecs.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat image, dst_blur, dst_gauss;
    image = imread("cat2.jpg", IMREAD_GRAYSCALE); // Read the file

    dst_blur = image.clone();
    dst_gauss = image.clone();
    Mat dst_my = image.clone();
    Size size = image.size();

    /**
    -1 -1 -1
    -1  1  1 * 1/3
    -1  1  -1 
    
    RGBRGBRGB
    */ 


    for (int i = 1; i < size.height-1; i++) {
        for (int j = 1; j <size.width-1; j++) {
            dst_my.ptr(i)[j] = (
                image.ptr(i)[j] + 
                image.ptr(i - 1)[j - 1] +
                image.ptr(i - 1)[j] +
                image.ptr(i - 1)[j + 1] +
                image.ptr(i)[j - 1] +
                image.ptr(i)[j + 1] +
                image.ptr(i + 1)[j - 1] +
                image.ptr(i + 1)[j] +
                image.ptr(i + 1)[j + 1]
            ) * 1.0 / 9;
        }
    }
    
    Canny(image, dst_blur, 1 ,3);
    for (int i = 1; i < size.height - 1; i++) {
        for (int j = 1; j < size.width - 1; j++) {
            dst_my.ptr(i)[j] = image.ptr(i)[j] + dst_blur.ptr(i)[j];
        }
    }

    cv::GaussianBlur(image, dst_gauss, Size(11, 11), 0, 0);
    //cv::Mat(image, dst, CV_GAUSSIAN, 3, 3);
    imshow("Исходное изображение", image); // Show our image inside it.
    imshow("Обработанное изображение blur", dst_blur); // Show our image inside it.
    //imshow("Обработанное изображение gauss", dst_gauss); // Show our image inside it.
    imshow("Новое", dst_my); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}