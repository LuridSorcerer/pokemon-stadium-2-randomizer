# Pokemon Stadium 2 Randomizer

This program randomizes the moves known by rental Pokemon in the Nintendo 64 game Pokemon Stadium 2 (USA).

In the future, it will hopefully be able to randomize the Pokemon owned by NPC trainers, as well as the moves, held items, and stats of these Pokemon.

## Building

This program uses wxWidgets for its GUI. wxWidgets 3.0.4 was used while developing this program. The "core" randomization code does not have any external requirements. 

### Linux

1. Set up wxWidgets
    * This link will probably be helpful: https://wiki.codelite.org/pmwiki.php/Main/WxWidgets30Binaries#toc2
    * > $ sudo apt-key adv --fetch-keys http://repos.codelite.org/CodeLite.asc
    * > $ sudo apt-add-repository 'deb http://repos.codelite.org/wx3.0.4/ubuntu/ artful universe'
    * > $ sudo apt update
    * > $ sudo apt install libwxbase3.0-0-unofficial libwxbase3.0-dev libwxgtk3.0-0-unofficial libwxgtk3.0-dev wx3.0-headers wx-common libwxbase3.0-dbg libwxgtk3.0-dbg wx3.0-i18n wx3.0-examples wx3.0-doc

2. Compile 
    * > $ make

3. Run
    * > $ ./ps2rand

### Windows

1. Set up wxWidgets
    * I compiled it with Mingw-w64. The win-builds version did not work, so I used this package from SourceForge: https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe

        I installed with the default options.
    
        Don't forget to add the bin folder to your path!

        This should also work with Visual Studio, but I did not try this and would have no idea how to set it up. Sorry.

    * This YouTube video pointed me in the right direction as far as the compilation goes: https://www.youtube.com/watch?v=vmobZRIlBMU
        * Download the wxWidgets code:
        https://github.com/wxWidgets/wxWidgets/releases/download/v3.0.4/wxWidgets-3.0.4.zip
        * Newer versions may work, this will need to be tested
        * Extract to a convenient directory, such as C:\wxWidgets-3.0.4\
        * In command prompt, browse to the msw build directory
            > \> cd \wxWidgets-3.0.4\build\msw
        * Build wxWidgets
            > \> mingw32-make -f makefile.gcc BUILD=release SHARED=1 MONOLITHIC=1 UNICODE=1 CXXFLAGS=-std=gnu++11 
        * Wait a half an hour or so depending on your PC. May God have mercy on your soul.

2. Compile

    > \> mingw32-make -f Makefile.win

3. Run
    * Copy the wxWidgets DLL we built in step 2 to the current directory
        > \> copy \wxWidgets-3.0.4\lib\gcc_dll\wxmsw30u_gcc_custom.dll .
    * Finally ready to run!
        > \> .\ps2rand.exe


## Usage

* Click the Browse button to select your ROM file.
* Click the Randomize button to have the selected ROM randomized.
* That's it. Load it up in an emulator and check it out. 

I had trouble running Pokemon Stadium 2 in BizHawk 2 releases. BizHawk 1 ran both the original and modified ROMs without any issues, so that's what I'd recommend using. Maybe change the resolution to at least 640x480 and don't forget to configure your controller. Remember that the D-pad is used exclusively, the analog is totally unused in both Pokemon Stadium games.

## FAQ

* Does this work on...?

    Probalby not. It only works with the USA release of Pokemon Stadium 2. (SHA-1: D8343E69A7DC63B869CF6361D87CDE64444281D3). This randomizer relies on the exact locations of particular data. If you feed it another file, it will look for the ROM header and fail if it does not match what is expected. 
    
* Can I undo a randomization?

    No. Please keep a backup copy of your original ROM.

* What are the future plans?

    I want to add the ability to randomize enemy trainer Pokemon, randomize stats (DVs and stat EXP), and held items. 
    
    For this, I'll need to do some independent research on the ROM, its data structures, and data locations. The ROM map I found was inadequate and a good portion of the information in it was incorrect. While this map provided a good starting point, it has lived out its usefulness and development will have to slow down as I do more research. 

    Banning specific moves and Pokemon would probably be a nice feature to have. There's also nothing preventing a Pokemon from knowing the same move multiple times, but I have yet to see that actually happen. 
