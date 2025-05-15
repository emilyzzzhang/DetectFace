#include <opencv2/opencv.hpp>
#include <iostream>

int main() {
    // Load the Haar Cascade Classifier
    cv::CascadeClassifier face_cascade;
    if (!face_cascade.load("haarcascade_frontalface_default.xml")) {
        std::cerr << "Error loading face cascade\n";
        return -1;
    }

    // Open webcam (0 = default camera)
    cv::VideoCapture cap(0);
    if (!cap.isOpened()) {
        std::cerr << "Error opening webcam\n";
        return -1;
    }

    cv::Mat frame, gray;
    std::vector<cv::Rect> faces;

    while (true) {
        cap >> frame; // Capture a frame
        if (frame.empty()) break;

        cv::cvtColor(frame, gray, cv::COLOR_BGR2GRAY); // Convert to grayscale
        cv::equalizeHist(gray, gray); // Improve contrast

        face_cascade.detectMultiScale(gray, faces); // Detect faces

        // Draw rectangles around detected faces
        for (const auto& face : faces) {
            cv::rectangle(frame, face, cv::Scalar(255, 0, 0), 2);
        }

        cv::imshow("Face Detection", frame);

        if (cv::waitKey(10) == 27) break; // Press 'ESC' to quit
    }

    cap.release();
    cv::destroyAllWindows();
    return 0;
}
