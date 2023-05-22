//
// Created by nasy on 22.05.2023.
//

#ifndef FACEBERRY_GUI_TRANSITION_UTILS_H
#define FACEBERRY_GUI_TRANSITION_UTILS_H
#include <wx/wx.h>
#include <opencv2/opencv.hpp>

using namespace cv;

wxImage MatToImg(Mat &img) {
    Mat im2;
    if(img.channels()==1){cvtColor(img,im2,COLOR_GRAY2RGB);}
    else if (img.channels() == 4) { cvtColor(img, im2, COLOR_BGRA2RGB);}
    else {cvtColor(img,im2,COLOR_BGR2RGB);}
    long imgSize = im2.rows * im2.cols * im2.channels();
    wxImage wx(im2.cols, im2.rows, (unsigned char*)malloc(imgSize), false);
    unsigned char* s=im2.data;
    unsigned char* d=wx.GetData();
    for (long i = 0; i < imgSize; i++) { d[i] = s[i];}
    return wx;
}
Mat ImgToMat(wxImage &wx) {
    Mat im2(Size(wx.GetWidth(),wx.GetHeight()),CV_8UC3,wx.GetData());
    cvtColor(im2,im2,COLOR_RGB2BGR);
    return im2;
}

#endif //FACEBERRY_GUI_TRANSITION_UTILS_H
