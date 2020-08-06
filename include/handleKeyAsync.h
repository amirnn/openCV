#pragma once
#include <opencv2/opencv.hpp>
#include <future>
// Handle key press
namespace keyHandler
{
    std::promise<uint> promise;
    auto handleKeyPressAsync = [](std::promise<uint>&& promise) {
        std::cout << "Press ESC to exit." << std::endl;
        while (true)
        {
            uint pressedBtn = cv::waitKey(0);
            if (pressedBtn == 27)
            {
                promise.set_value(27);
            }
        }
    };
} // namespace keyHandler
