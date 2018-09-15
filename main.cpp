// Pokemon Stadium 2 Randomizer
// Randomizes the moves rental Pokemon know.

#include <iostream>
#include <fstream>

#include "Randomizer.hpp"

// use precompiled headers if available
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

Randomizer *randomizer;

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
    void OnRandomize(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    // create an event table so we can receive mouse and keyboard events
    wxDECLARE_EVENT_TABLE();
};

// Create an enum of events that may be handled.
// These will correspond to menu items and buttons.
// Many built-in events do not need to be defined manually (ex. Exit, Help)
enum {
    ID_Hello = 1,
    ID_Randomize,
    ID_Button
};

// create event table
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello, MyFrame::OnHello)
    EVT_MENU(ID_Randomize, MyFrame::OnRandomize)
    EVT_BUTTON(ID_Button,MyFrame::OnRandomize)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

// define which app will serve as the "main" function
wxIMPLEMENT_APP(MyApp);

// this is the app's OnInit function, which will be used as the
// "main" function (see previous statement)
bool MyApp::OnInit() {
    // create a window frame and display it
    MyFrame *frame = new MyFrame("Pokemon Stadium 2 Randomizer",wxPoint(50,50),wxSize(640,480) );
    frame->Show(true);

    // open the ROM
    // rom.open("rom.z64", ios::in | ios::out | ios::binary);
    // if (!rom.is_open()) {
    //     cout << "Failed to open ROM" << endl;
    //     return 1;
    // }
    randomizer = new Randomizer("rom.z64");

    // open log file
    // logfile.open("log.txt", ios::out);
    // if (!logfile.is_open()) {
    //     cout << "Failed to open log file" << endl;
    //     return 2;
    // }

    return true;
}

// in the frame constructor, we'll create a menu bar and stuff
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
    : wxFrame(NULL,wxID_ANY,title,pos,size) {
    
    // create file menu
    wxMenu *menuFile = new wxMenu;
    // menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
    //     "Help string show in status bar for this menu item");
    // menuFile->Append(ID_Randomize,"&Randomize","Randomize the ROM");
    // menuFile->AppendSeparator();
    menuFile->Append(wxID_EXIT);

    // create help menu
    wxMenu *menuHelp = new wxMenu;
    menuHelp->Append(wxID_ABOUT);

    // create menu bar and add our menu items we just created
    wxMenuBar *menuBar = new wxMenuBar;
    menuBar->Append(menuFile,"&File");
    menuBar->Append(menuHelp,"&Help");

    // show menu bar we just created
    SetMenuBar(menuBar);

    // create a status bar and add default message to it
    CreateStatusBar();
    // SetStatusText("Welcome to wxWidgets");

    // Let's try to add a couple of buttons
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    sizer->Add(new wxButton(this,ID_Button,"Randomize"),0,0,0);
    SetSizer(sizer);
}

void MyFrame::OnExit(wxCommandEvent& event) {
    // close 
    //rom.close();
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Created by LuridSorcerer \nluridsorcerer.com","About",
    wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event) {
    // wxLogMessage("Hello");
}

void MyFrame::OnRandomize(wxCommandEvent& event) {
    randomizer->randomize_rentals(LITTLE_CUP_RENTALS,LITTLE_CUP_COUNT);
    randomizer->dump_rentals(LITTLE_CUP_RENTALS,LITTLE_CUP_COUNT);
}

