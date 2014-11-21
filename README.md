These are the files that will help bootstrap the usage of the TI Tiva C 123 launchpad.

# Setting up the toolchain

1. Download the GCC ARM Embedded toolchain:
 * [Windows] (https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q2-update/+download/gcc-arm-none-eabi-4_8-2014q2-20140609-win32.exe). Install, and select the options to add to the PATH.
 * [Linux] (https://launchpad.net/gcc-arm-embedded/4.8/4.8-2014-q2-update/+download/gcc-arm-none-eabi-4_8-2014q2-20140609-linux.tar.bz2) (or your package manager, look for gcc-arm-none-eabi).
2. Build tools - this project relies heavily on makefiles.
	* Windows
		1. Download and install a minGW-compatible shell. The easiest way to get that is to install [msysgit](http://msysgit.github.io/).
		2. Install [msys](http://downloads.sourceforge.net/project/mingw/MSYS/Base/msys-core/msys-1.0.11/MSYS-1.0.11.exe). Add the msys/bin path to your PATH; i.e: append C:\msys\1.0\bin to your PATH variable.
	* Linux is easy. Install `build-essential` from your distro repositories.
3. Test by running `arm-none-eabi-gcc -v` and `make` from a shell. If they run, you're good to go.
4. Install Stellaris drivers for [Windows]( http://www.ti.com/lit/sw/slac632/slac632.zip). Linux can use lm4flash as it just uses libusbxx.
