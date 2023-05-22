//
// Created by nasy on 22.05.2023.
//

#ifndef FACEBERRY_GUI_OPENCV_FUNCS_H
#define FACEBERRY_GUI_OPENCV_FUNCS_H
#include <opencv2/opencv.hpp>
#include <opencv2/face.hpp>
#include <wx/wx.h>
#include "opencv-funcs.h"
#include "transition-utils.h"

using namespace cv;
using namespace std;
using namespace cv::face;

Scalar_<double> color_outline{0, 0, 255};
int thickness = 2;

wxImage DetectFaceOnImage (wxImage &image) {
    Mat input = ImgToMat(image);
    Mat inputGrey;
    vector<Rect> results;

    CascadeClassifier faces("/home/nasy/repos/faceberry/faces_default.xml");

    cvtColor(input, inputGrey, COLOR_BGR2GRAY);
    faces.detectMultiScale(inputGrey, results, 3, 4);
    for (Rect r : results) {
        rectangle(input, r, color_outline, thickness, LINE_8, 0);
    }

    wxImage result = MatToImg(input);
    return result;
}

//void DetectFaceOnVideo (string path) {
//    VideoCapture cam;
//    //VideoCapture cam(0);
//    cam.open(path);
//    if (!cam.isOpened()) {
//        return;
//    }
//
//    Mat vid_img;
//    Mat vid_img_grey;
//    vector<Rect> results;
//    CascadeClassifier faces("home/student/faces_default.xml");
//
//    while (true) {
//        cam >> vid_img;
//        if (vid_img.empty()) {
//            break;
//        }
//        cvtColor(vid_img, vid_img_grey, COLOR_BGR2GRAY);
//        faces.detectMultiScale(vid_img_grey, results, 3, 4);
//        for (Rect r : results) {
//            rectangle(vid_img, r, color_outline, thickness, LINE_8, 0);
//        }
//        namedWindow("Cam0", 0);
//        resizeWindow("Cam0", 1080, 720);
//        imshow("Cam0", vid_img);
//        waitKey(10);
//    }
//}

#endif //FACEBERRY_GUI_OPENCV_FUNCS_H
