#include <iostream>
#include <string>
#include <vector>
#include <opencv2/opencv.hpp>
#include <opencv2/objdetect.hpp>

int main(int argc, char** argv) {
  cv::Mat sourceImage;
  sourceImage = cv::imread(argv[1], cv::COLOR_BGR2RGB);

  if (!sourceImage.data) {
    std::cerr << "No Image Data! Please check if the file exists!" << std::endl;
    return -1;
  }

  const std::string faceCascadeFile = "./haarcascade_frontalface_default.xml";
  cv::CascadeClassifier faceCascade;

  if (!faceCascade.load(faceCascadeFile)) {
    std::cerr << "Unable to load cascade file!" << std::endl;
    return -1;
  }

  std::vector<cv::Rect> faces;
  faceCascade.detectMultiScale(sourceImage, faces);

  for (size_t i = 0; i < faces.size(); i++) {
    std::cout << "Face detected! Face: " << (i + 1) << std::endl;
    cv::Scalar color(0, 255, 0);
    cv::rectangle(sourceImage, faces[i], color, 1);
  }

  if (faces.size() > 0) {
    cv::namedWindow("Faces Detected", cv::WINDOW_AUTOSIZE);
    cv::imshow("Faces Detected", sourceImage);
    cv::waitKey(0);
  } else {
    std::cout << "No faces detected!" << std::endl;
  }

  return 0;
}
