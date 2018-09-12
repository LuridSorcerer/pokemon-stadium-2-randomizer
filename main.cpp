// wxWidgets hello test program
// build with:
// g++ hello.cpp `wx-config --cxxflags` `wx-config --libs`

#include <iostream>
#include <fstream>
#include <time.h>

#include "PokemonNames.hpp"
#include "Moves.hpp"
#include "Constants.hpp" 

// use precompiled headers if available
#include <wx/wxprec.h>
#ifndef WX_PRECOMP
    #include <wx/wx.h>
#endif

using namespace std;

fstream rom;
fstream logfile;

void randomize_little_cup_rentals();
void dump_little_cup_rentals();

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
// These will correspond to menu items.
// Many built-in events do not need to be defined manually (ex. Exit, Help)
enum {
    ID_Hello = 1,
    ID_Randomize
};

// create event table
wxBEGIN_EVENT_TABLE(MyFrame, wxFrame)
    EVT_MENU(ID_Hello, MyFrame::OnHello)
    EVT_MENU(ID_Randomize, MyFrame::OnRandomize)
    EVT_MENU(wxID_EXIT, MyFrame::OnExit)
    EVT_MENU(wxID_ABOUT, MyFrame::OnAbout)
wxEND_EVENT_TABLE()

// define which app will serve as the "main" function
wxIMPLEMENT_APP(MyApp);

// this is the app's OnInit function, which will be used as the
// "main" function (see previous statement)
bool MyApp::OnInit() {
    // create a window frame and display it
    MyFrame *frame = new MyFrame("Test Program",wxPoint(50,50),wxSize(640,480) );
    frame->Show(true);

    // open the ROM
    rom.open("rom.z64", ios::in | ios::out | ios::binary);
    if (!rom.is_open()) {
        cout << "Failed to open ROM" << endl;
        return 1;
    }

    // open log file
    logfile.open("log.txt", ios::out);
    if (!logfile.is_open()) {
        cout << "Failed to open log file" << endl;
        return 2;
    }

    return true;
}

// in the frame constructor, we'll create a menu bar and stuff
MyFrame::MyFrame(const wxString& title, const wxPoint& pos, const wxSize& size) 
    : wxFrame(NULL,wxID_ANY,title,pos,size) {
    
    // create file menu
    wxMenu *menuFile = new wxMenu;
    menuFile->Append(ID_Hello, "&Hello...\tCtrl-H",
        "Help string show in status bar for this menu item");
    menuFile->Append(ID_Randomize,"&Randomize","Randomize the ROM");
    menuFile->AppendSeparator();
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
    SetStatusText("Welcome to wxWidgets");
}

void MyFrame::OnExit(wxCommandEvent& event) {
    // close 
    rom.close();
    Close(true);
}

void MyFrame::OnAbout(wxCommandEvent& event) {
    wxMessageBox("I have no idea what I'm doing.","HELP ME",
    wxOK | wxICON_INFORMATION);
}

void MyFrame::OnHello(wxCommandEvent& event) {
    wxLogMessage("Hello");
}

void MyFrame::OnRandomize(wxCommandEvent& event) {
    randomize_little_cup_rentals();
    dump_little_cup_rentals();
}

void randomize_little_cup_rentals() {

    // seed the random number generator
    srand(time(NULL));

    for (int j = 0; j < LITTLE_CUP_COUNT; j++ ) { 

        // go to pokemon
        rom.seekg(LITTLE_CUP_RENTALS + (SIZE_OF_POKEMON*j) + MOVE1);

        // for each move
        for (int i = 0; i < 4; i++) { 

            // randomly pick a move and insert it
            uint8_t move = (rand() % MOVES_COUNT) + 1;
            //rom << move;
            rom.write((char*)&move,sizeof(move));
        }

    }
}

void dump_little_cup_rentals() {
    // read and print level and species
    uint8_t level = 0;
    uint8_t species = 0;

    logfile << "LITTLE CUP RENTALS" << endl
        << "------------------" << endl;

    // go to first LittleCup Pokemon
    // rom.seekg(LITTLE_CUP_RENTALS);
    for (int i = 0; i < LITTLE_CUP_COUNT;  i++) {

        // seek to pokemon
        rom.seekg(LITTLE_CUP_RENTALS + (SIZE_OF_POKEMON * i));

        // read level and species
        //rom >> level;
        //rom >> species;
        rom.read((char*)&level,sizeof(level));
        rom.read((char*)&species,sizeof(species));

        // write level and name
        logfile << "Level " << (int)level << " " 
            << (int)species << ":" << PokemonNames[species] <<  endl;
        
        // write out moveset
        rom.seekg(LITTLE_CUP_RENTALS + (SIZE_OF_POKEMON * i) + MOVE1);
        logfile << "\t";
        for (int j = 0; j < 4; j++) {
            uint8_t move = 0;
            //rom >> move;
            rom.read((char*)&move,sizeof(move));
            logfile << Moves[move];
            if (j < 3) { logfile << " / "; }
        }
        logfile << endl;
    }
}