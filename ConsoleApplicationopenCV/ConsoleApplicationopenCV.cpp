#include <opencv2/core/core.hpp>
#include <opencv2/highgui/highgui.hpp>
    //#include <opencv2/imgproc/imgproc.hpp>
    //#include "opencv2/imgcodecs.hpp"
#include <iostream>
using namespace cv;
using namespace std;

int main(int argc, char** argv)
{
    Mat image;
    image = imread("biggrin.bmp", IMREAD_REDUCED_COLOR_2); // Read the file
    cv::namedWindow("Display window", WINDOW_AUTOSIZE); // Create a window for display.
        //cv::Mat(image, dst, CV_GAUSSIAN, 3, 3);
    imshow("Display window", image); // Show our image inside it.
    waitKey(0); // Wait for a keystroke in the window
    return 0;
}