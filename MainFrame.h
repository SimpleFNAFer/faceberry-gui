#ifndef FACEBERRY_GUI_MAINFRAME_H
#define FACEBERRY_GUI_MAINFRAME_H
#include <wx/wx.h>


class MainFrame : public wxFrame {
public:
    explicit MainFrame(const wxString& title);
private:
    void OnBtnOpenCamClicked(wxCommandEvent& evt);
    void OnBtnOpenImgClicked(wxCommandEvent& evt);
    void OnBtnOpenVidClicked(wxCommandEvent& evt);
    void OnBtnFaceSaveClicked(wxCommandEvent& evt);

    wxImage image;
    wxStaticBitmap* staticBitmap;
};


#endif //FACEBERRY_GUI_MAINFRAME_H
