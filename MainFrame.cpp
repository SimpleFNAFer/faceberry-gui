#include "MainFrame.h"
#include "opencv-funcs.h"
#include <wx/wx.h>

MainFrame::MainFrame(const wxString &title): wxFrame(nullptr, wxID_ANY, title) {
    auto* panel = new wxPanel(this);
    auto* btnSearchCam = new wxButton(panel, wxID_ANY, "Search Cam", wxPoint(150, 50), wxSize(100, 35));
    auto* btnOpenVid = new wxButton(panel, wxID_ANY, "Select Video", wxPoint(150, 150), wxSize(100, 35));
    auto* btnOpenImg = new wxButton(panel, wxID_ANY, "Select Photo", wxPoint(400, 150), wxSize(100, 35));

    auto image = new wxImage();
    staticBitmap = new wxStaticBitmap(
            panel, wxID_ANY,
            wxBitmap(wxSize(1,1)), wxDefaultPosition,
            FromDIP(wxSize(50, 20)));
    staticBitmap->SetScaleMode(wxStaticBitmap::Scale_None);

    wxArrayString choices;
    choices.Add("Camera 0");
    choices.Add("Camera 1");
    auto* listBox = new wxListBox(panel, wxID_ANY, wxPoint(300, 50), wxSize(100, -1), choices);

    btnSearchCam->Bind(wxEVT_BUTTON, &MainFrame::OnBtnOpenCamClicked, this);
    btnOpenImg->Bind(wxEVT_BUTTON, &MainFrame::OnBtnOpenImgClicked, this);
    btnOpenVid->Bind(wxEVT_BUTTON, &MainFrame::OnBtnOpenVidClicked, this);

    CreateStatusBar();
}

void MainFrame::OnBtnOpenCamClicked(wxCommandEvent &evt) {
    wxLogStatus("Button clicked");
}

void MainFrame::OnBtnOpenImgClicked(wxCommandEvent &evt) {
    wxFileDialog dialog(this,
                        "Select image", "", "",
                        "Image Files (*.png;*.jpg;*.jpeg;*.bmp)|*.png;*.jpg;*.jpeg;*.bmp",
                        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (dialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    if (!this->image.LoadFile(dialog.GetPath()))
    {
        wxMessageBox("Failed to load image file", "Error", wxOK | wxICON_ERROR);
        return;
    }

    wxImage imageFaces = DetectFaceOnImage(image);

    staticBitmap->SetBitmap(wxBitmap(imageFaces));
    this->Layout();
}

void MainFrame::OnBtnOpenVidClicked(wxCommandEvent &evt) {
    wxFileDialog dialog(this,
                        "Select video file", "", "",
                        "Video Files (*.mp4;*.mkv;*.avi;*.webm)|*.mp4;*.mkv;*.avi;*.webm",
                        wxFD_OPEN | wxFD_FILE_MUST_EXIST);
    if (dialog.ShowModal() == wxID_CANCEL)
    {
        return;
    }

    //DetectFaceOnVideo(dialog.GetPath().ToStdString());
}

void MainFrame::OnBtnFaceSaveClicked(wxCommandEvent &evt) {

}
