# Pokemon Stadium 2 Randomizer

This program randomizes the moves known by rental Pokemon in the Nintendo 64 game Pokemon Stadium 2 (USA).

In the future, it will hopefully be able to randomize the Pokemon owned by all NPC trainers, as well as the moves, held items, and stats of these Pokemon.

## Building

This program uses wxWidgets for its GUI. wxWidgets 3.0.4 was used while developing this program. The randomization code itself does not have any external requirements.

### Command line

I have not yet written Makefiles for the command line version, as it is currently just an experiment. You should be able to simply build it with g++. 

Make sure your ROM is in the same folder as the executable and named "ps2.z64".

`g++ src\main-cli.cpp -o bin\ps2rand.exe`

### Linux

Currently unable to build on my laptop, something broke with the dependency packages.
I might either reinstall the OS on here and start over, or change to a newer version of wxWidgets.
Regardless, I want to do a command-line rewrite first to get the complete logic finished first.

1. [Set up wxWidgets](https://wiki.codelite.org/pmwiki.php/Main/WxWidgets30Binaries#toc2)
    * `sudo apt-key adv --fetch-keys http://repos.codelite.org/CodeLite.asc`
    * `sudo apt-add-repository 'deb http://repos.codelite.org/wx3.0.4/ubuntu/ artful universe'`
    * `sudo apt update`
    * `sudo apt install libwxbase3.0-0-unofficial libwxbase3.0-dev libwxgtk3.0-0-unofficial libwxgtk3.0-dev wx3.0-headers wx-common libwxbase3.0-dbg libwxgtk3.0-dbg wx3.0-i18n wx3.0-examples wx3.0-doc`

2. Compile
    * `make`

3. Run
    * `./ps2rand`

### Windows

1. Set up wxWidgets
    * I compiled it with Mingw-w64. The win-builds version did not work, so I used [this package from SourceForge](https://sourceforge.net/projects/mingw-w64/files/Toolchains%20targetting%20Win32/Personal%20Builds/mingw-builds/installer/mingw-w64-install.exe)

        I installed with the default options.

        Don't forget to add the bin folder to your path!

        This should also work with Visual Studio, but I did not try this and would have no idea how to set it up. Sorry.

    * [This YouTube video](https://www.youtube.com/watch?v=vmobZRIlBMU) pointed me in the right direction as far as the compilation goes.
        * Download the [wxWidgets code](https://github.com/wxWidgets/wxWidgets/releases/download/v3.0.4/wxWidgets-3.0.4.zip). Newer versions may work, this will need to be tested.
        * Extract to a convenient directory, such as C:\wxWidgets-3.0.4\
        * In command prompt, browse to the msw build directory

            `cd \wxWidgets-3.0.4\build\msw`
        * Build wxWidgets

            `mingw32-make -f makefile.gcc BUILD=release SHARED=1 MONOLITHIC=1 UNICODE=1 CXXFLAGS=-std=gnu++11`
        * Wait a half an hour or so depending on your PC. May God have mercy on your soul.

2. Compile

    `mingw32-make -f Makefile.win`

3. Run
    * Copy the wxWidgets DLL we built in step 2 to the current directory

        `copy \wxWidgets-3.0.4\lib\gcc_dll\wxmsw30u_gcc_custom.dll .`
    * Finally ready to run!

        `.\ps2rand.exe`

## Usage

1. Click the Browse button to select your ROM file.
1. Click the Randomize button to have the selected ROM randomized.
1. Load it up in an emulator and check it out.

I tested using BizHawk 1.13.2. Other emulators should work but I have not tested them, please let me know if you run into issues. The Pokemon Stadium games are [incompatible with BizHawk versions 2.3 and up](https://github.com/TASVideos/BizHawk/issues/1535).

## FAQ

* Does this work on...?

    This randomizer is designed for one specific ROM: the US release of Pokemon Stadium 2, in z64 format. ROMs in n64 or v64 format will not work, as their data is in a different order. Converters between the formats should help. The ROM's SHA-1 hash should be D8343E69A7DC63B869CF6361D87CDE64444281D3 before randomization.

* Can I undo a randomization?

    Not at this time. Please keep a backup copy of your original ROM.

* What's next?

  * Read Pokemon, move, and items names from ROM instead of header files
  * Dump wxWidgets and do a CLI version, reintegrate GUI after it's done
  * Write randomized ROM to new file in order to preserve the original
  * Randomize remaining leagues and second rounds.
  * Randomize held items
  * Randomize Pokemon nicknames
  * Converter for n64 and v64 formats
