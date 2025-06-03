# Pokemon Stadium 2 Randomizer

This program randomizes the moves known by rental Pokemon in the Nintendo 64 game Pokemon Stadium 2 (USA).

In the future, it will hopefully be able to randomize the Pokemon owned by all NPC trainers, as well as the moves, held items, and stats of these Pokemon.

## Building

This program uses wxWidgets for its GUI. wxWidgets 3.2.8.1 is the latest version tested for this program. The randomization code itself does not have any external requirements.

[//]: # "TODO: Update Linux build instructions"
### Linux 

1. Install wxWidgets
    * `$ sudo apt install libwxbase3.0-0-unofficial libwxbase3.0-dev libwxgtk3.0-0-unofficial libwxgtk3.0-dev wx3.0-headers wx-common libwxbase3.0-dbg libwxgtk3.0-dbg wx3.0-i18n wx3.0-examples wx3.0-doc`
    
2. Compile
    * `$ make`

3. Run
    * `$ bin/ps2rand`

### Windows

1. Install compiler mingw32. 

    * Download the release package from https://github.com/niXman/mingw-builds-binaries/releases .

    * Extract and place the mingw32 folder somewhere convenient, such as the root of the C: drive. 

    * Add the bin subfolder to your path (eg. C:\mingw32\bin). 

1. Compile wxWidgets. 

    * Download from https://github.com/wxWidgets/wxWidgets/releases/download/v3.2.8.1/wxWidgets-3.2.8.1.zip . 

    * Create a folder somewhere convenient (such as C:\wxWidgets-3.2.8.1) and extract the zip's contents there.

        **Note: If you place this folder elsewhere or use a different wxWidgets version, please update the Makefile.win file to reflect this. Update the CXXFLAGS and LIBS variables accordingly.**

    * In a comamnd line window, navigate to the build directory for Windows. 

        `> cd C:\wxWidgets-3.2.8.1\build\msw\`

    * Begin the build.

        `> mingw32-make -f makefile.gcc BUILD=release SHARED=1 MONOLITHIC=1 UNICODE=1 CXXFLAGS=-std=gnu++11`

    * When complete, copy wxWidgets-3.2.8.1\lib\gcc_dll\wxmsw32u_gcc_custom.dll to this project's bin folder. 

1. Compile the randomizer. Navigate to this project's folder in the command line interface, then run the make command.

    `> mingw32-make -f Makefile.win`

1. Run the resulting executable file 
    
    `> cd bin`

    `> ps2rand.exe`

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
