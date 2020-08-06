message("Running on an Apple platform.")

# 1. Imge Blurring
add_executable(imageBlurring.out src/cpp/1.ImagePreview.cc)
target_link_libraries(imageBlurring.out ${OpenCV_LIBRARIES})
# 2. Video Previw
add_executable(videoBlurring-threading.out src/cpp/2.VideoPreview-threading.cc include/handleKeyAsync.h)
target_link_libraries(videoBlurring-threading.out ${OpenCV_LIBRARIES})
# Read this link: https://stackoverflow.com/questions/53129648/how-to-have-info-plist-bundled-in-a-macosx-application-with-cmake
# And this link: https://stackoverflow.com/questions/55518922/missing-info-plist-file-for-c-command-line-tool-application-within-xcode
set_target_properties(videoBlurring-threading.out PROPERTIES 
MACOSX_BUNDLE TRUE
MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/CMakeModules/Info.plist)

# 2. Video Bluring without threading
add_executable(videoBlurring.out src/cpp/2.VideoPreview.cc)
target_link_libraries(videoBlurring.out ${OpenCV_LIBRARIES})
set_target_properties(videoBlurring.out PROPERTIES 
MACOSX_BUNDLE TRUE
MACOSX_BUNDLE_INFO_PLIST ${PROJECT_SOURCE_DIR}/CMakeModules/Info.plist)
