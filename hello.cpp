// wxWidgets hello test program
// build with:
// g++ hello.cpp `wx-config --cxxflags` `wx-config --libs`

// use precompiled headers if available
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

// create our app, based on wxApp
class MyApp : public wxApp {
public:
    virtual bool OnInit();
};

// create a main window by derriving from wxFrame.
class MyFrame : public wxFrame {

public:
    MyFrame (const wxString& title, const wxPoint& pos, const wxSize& size);

private:
    // handle menu command events
    void OnHello(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    // create an event table so we can receive mouse and keyboard events
    wxDECLARE_EVENT_TABLE();
};

enum {
    ID_Hello = 1
};

// create event table
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello, MyFrame::OnHello)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

// define which app will serve as the "main" function
wxIMPLEMENT_APP(MyApp);

// this is the app's OnInit function, which will be used as the
// "main" function (see previous statement)
bool MyApp::OnInit() {
    MyFrame *frame = new MyFrame("Test Program",wxPoint(50,50),wxSize(640,480) );
    frame->Show(true);
    return true;
}

// in the frame constructor, we'll create a menu bar and stuff
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
    : wxFrame(NULL,wxID_ANY,title,pos,size) {
    
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string show in status bar for this menu item");
    menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile,"&File");
    menuBar->Append(menuHelp,"&Help");

    SetMenuBar(menuBar);

    CreateStatusBar();
    SetStatusText("Welcome to wxWidgets");
}

void MyFrame::OnExit(wxCommandEvent& event) {
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("I have no idea what I'm doing.","HELP ME",
    wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Hello");
}