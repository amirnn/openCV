#include <opencv2/opencv.hpp>
using cv::Mat;

int main(int argc, char const *argv[])
{
    if (argc == 1)
    {
        std::cout << "Please provide [1] the video file name, or use webcam and then [2] id" << std::endl;
        return EXIT_FAILURE;
    }

    cv::VideoCapture video;
    if (std::string(argv[1]) == std::string("webcam"))
    {
        uint webCamid = std::stoi(argv[2]);
        std::cout << "Initilzing webcam id: " << webCamid << std::endl;
        video.open((int)webCamid);
    }
    // it is a video file
    else
    {
        video.open(std::string(argv[1]));
    }
    if (!video.isOpened())
    {
        std::cout << "Could not open the video capture." << std::endl;
        return EXIT_FAILURE;
    }
    cv::namedWindow("video-canvas",cv::WINDOW_AUTOSIZE);
    int frameRate = video.get(cv::CAP_PROP_FPS);
    uint frameLength = (uint) (1000.0 / frameRate);
    std::cout << "Frame rate: " << frameRate << "Each frame length is: " << frameLength << "ms" << std::endl;
    
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
        if(cv::waitKey(frameLength) == 27) break;
    }
    cv::destroyAllWindows();
    return EXIT_SUCCESS;
}
