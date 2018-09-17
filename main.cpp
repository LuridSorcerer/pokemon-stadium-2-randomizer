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
#include <wx/filepicker.h>

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
    void OnRandomize(wxCommandEvent& event);
    void OnExit(wxCommandEvent& event);
    void OnAbout(wxCommandEvent& event);

    wxFilePickerCtrl *filepicker;

    // create an event table so we can receive mouse and keyboard events
    wxDECLARE_EVENT_TABLE();
};

// Create an enum of events that may be handled.
// These will correspond to menu items and buttons.
// Many built-in events do not need to be defined manually (ex. Exit, Help)
enum {
    ID_Randomize = 1,
    ID_Button,
    ID_FilePickerCtrl
};

// create event table
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
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

    // seed random number generator
    srand(time(NULL));

    return true;
}

// in the frame constructor, we'll create a menu bar and stuff
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
    : wxFrame(NULL,wxID_ANY,title,pos,size) {
    
    // create file menu
    wxMenu *menuFile = new wxMenu;
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
    SetStatusText("http://luridsorcerer.com");

    // Let's try to add a couple of buttons
    wxBoxSizer *sizer = new wxBoxSizer(wxVERTICAL);
    filepicker = new wxFilePickerCtrl(this,ID_FilePickerCtrl);
    sizer->Add(filepicker, 0,wxEXPAND,0);
    sizer->Add(new wxButton(this,ID_Button,"Randomize"),1,wxEXPAND | wxALL, 10);
    SetSizer(sizer);
}

void MyFrame::OnExit(wxCommandEvent& event) {
    // close 
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("Created by LuridSorcerer \nluridsorcerer.com","About",
    wxOK | wxICON_INFORMATION);
}

void MyFrame::OnRandomize(wxCommandEvent& event) {

    // create Randomizer
    wxString path = filepicker->GetPath();
    randomizer = new Randomizer( path.ToStdString() );

    // randomize Little Cup rentals 
    randomizer->randomize_rentals(LITTLE_CUP_RENTALS,LITTLE_CUP_COUNT);
    randomizer->dump_rentals(LITTLE_CUP_RENTALS,LITTLE_CUP_COUNT);

    // randomize Poke Cup rentals
    randomizer->randomize_rentals(POKE_CUP_RENTALS,POKE_CUP_COUNT);
    randomizer->dump_rentals(POKE_CUP_RENTALS,POKE_CUP_COUNT);

    // randomize Prime Cup rentals
    randomizer->randomize_rentals(PRIME_CUP_RENTALS,PRIME_CUP_COUNT);
    randomizer->dump_rentals(PRIME_CUP_RENTALS,PRIME_CUP_COUNT);

    // Bernie
    randomizer->randomize_rentals(LITTLE_CUP_BERNIE,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_BERNIE,PARTY_SIZE);

    // Stacy
    randomizer->randomize_rentals(LITTLE_CUP_STACY,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_STACY,PARTY_SIZE);

    // Grant
    randomizer->randomize_rentals(LITTLE_CUP_GRANT,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_GRANT,PARTY_SIZE);

    // Janet
    randomizer->randomize_rentals(LITTLE_CUP_JANET,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_JANET,PARTY_SIZE);

    // Clark
    randomizer->randomize_rentals(LITTLE_CUP_CLARK,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_CLARK,PARTY_SIZE);

    // Cora
    randomizer->randomize_rentals(LITTLE_CUP_CORA,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_CORA,PARTY_SIZE);

    // Tina
    randomizer->randomize_rentals(LITTLE_CUP_TINA,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_TINA,PARTY_SIZE);

    // Rex
    randomizer->randomize_rentals(LITTLE_CUP_REX,PARTY_SIZE,true);
    randomizer->dump_rentals(LITTLE_CUP_REX,PARTY_SIZE);

}

