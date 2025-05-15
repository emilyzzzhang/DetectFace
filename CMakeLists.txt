cmake_minimum_required(VERSION 3.10)
project(FaceDetection)

# Find OpenCV
find_package(OpenCV REQUIRED)

# Include OpenCV headers
include_directories(${OpenCV_INCLUDE_DIRS})

# Create executable
add_executable(DetectFace main.cpp)

# Link OpenCV libraries
target_link_libraries(DetectFace ${OpenCV_LIBS})
