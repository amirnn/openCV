#include <opencv2/opencv.hpp>
#include <iostream>
#include <string>
#include <thread>
#include <future>
#include "handleKeyAsync.h"
using cv::Mat;

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        std::cout << "Please provide [1] the video file name, or use webcam and then [2] id" << std::endl;
        return EXIT_FAILURE;
    }
    // Handle threading
    std::future<uint> future = keyHandler::promise.get_future();
    std::thread keyHandlerThread(keyHandler::handleKeyPressAsync, std::move(keyHandler::promise));

    cv::VideoCapture video;
    if (std::string(argv[1]) == std::string("webcam"))
    {
        uint webCamid = std::stoi(argv[2]);
        std::cout << "Initilzing webcam id: " << webCamid << std::endl;
        video.open(webCamid);
    }
    // it is a video file
    else
    {
        video.open(argv[1]);
    }
    if (!video.isOpened())
    {
        std::cout << "Could not open the video capture." << std::endl;
        return EXIT_FAILURE;
    }
    cv::namedWindow("video-canvas");
    Mat frame;
    while (true)
    {
        video >> frame;
        if (frame.empty())
        {
            std::cout << "end of video stream" << std::endl;
            break;
        }
        cv::imshow("video-canvas", frame);
        // Check and see if the shared state of the promise
        if (future.valid())
        {
            uint key = future.get();
            if (key == 27)
            {
                cv::destroyAllWindows();
                return EXIT_SUCCESS;
            }
        }
    }
    keyHandlerThread.join();
}
