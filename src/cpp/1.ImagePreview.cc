#include <opencv2/opencv.hpp>
#include <iostream>
using namespace std;
using namespace cv;
using cv::Mat;

int main( int argc, const char** argv )
{
    if (argc == 1){
        std::cout << "Please provide the file name" << std::endl;
        return EXIT_FAILURE;
    }

    Mat image = cv::imread(argv[1]); 
    Mat blurredImage;
    cv::namedWindow("input image");
    cv::namedWindow("output image");

    cv::imshow("input image", image);
    cv::GaussianBlur(image,blurredImage,cv::Size(5,5),3,3);
    cv::imshow("output image", blurredImage);
    while(true){
        // if escape button pressed
        // Waits forever and if a key is pressed it proceeds.
        std::cout << "Press ESC to exit." << std::endl;
        int pressedBtn = cv::waitKey(0);
        if (pressedBtn == 27){
            cv::destroyAllWindows();
            return EXIT_SUCCESS;
        }
    }
}