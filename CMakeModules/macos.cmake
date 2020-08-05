message("Running on an Apple platform.")

# 1. main GLFW window.
add_executable(main src/cpp/1.main.cc)
target_link_libraries(main ${OpenCV_LIBRARIES})