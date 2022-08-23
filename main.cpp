#include <iostream>
#include <opencv2/opencv.hpp>
#include <opencv2/highgui.hpp>

using namespace std;
using namespace cv;

int main(int argc, char** argv) {
    if (argc != 2) {
        cout << "Expecting a image file to be passed to program" << endl;
        return -1;
    }
    
    cv::Mat img = cv::imread(argv[1]);
    
    if (img.empty()) {
        cout << "Not a valid image file" << endl;
        return -1;
    }
    
    cv::namedWindow("Simple Demo", cv::WINDOW_AUTOSIZE);
    cv::imshow("Simple Demo", img);

    Vec3b intensity = img.at<Vec3b>(10, 10);
    cout << "BRG" << intensity << "\n";

    cv::Mat rgbchannel[3];
    cv::split(img, rgbchannel);
    cv::Mat bwimg;
    cv::cvtColor(img, bwimg, cv::COLOR_BGR2GRAY);

    cv::namedWindow("Demo2", cv::WINDOW_AUTOSIZE);
    cv::imshow("Demo2", bwimg);
    
    cv::waitKey(0);
    cv::destroyAllWindows();

    return 0;
}
