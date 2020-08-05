cmake_minimum_required(VERSION 3.18)
project(opencv)
# Set C++ version
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)

# include dir
include_directories(include)

find_package(OpenCV REQUIRED)
include_directories(${OPENCV_INCLUDE_DIRS})
set(OpenCV_SHARED OFF)
set(OpenCV_STATIC ON)

# To find variables
# include(CMakeModules/printVariables.cmake)

if (WIN32)
    include(CMakeModules/windows.cmake)

elseif(UNIX AND NOT APPLE)
    include(CMakeModules/linux.cmake)

elseif(APPLE)
    include(CMakeModules/macos.cmake)

endif()

