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

# Advanced Setup
This isn't essential to build code for the Tiva C, but advanced users might find this section helpful.


## Debugging
Real-time debugging the Tiva C through (arm-none-eabi)GDB requires openocd version 0.8 or greater. The `-g` must be added to `CFLAGS` if it doesn't exist already.


1. Install `arm-none-eabi-gdb`. This is included in the Windows package automatically, but Linux users must download and install the package separately.
2. Install openocd version 0.8 or greater. 
3. Locate the openocd binary, and find the `scripts/board/ek-lm4f120xl.cfg` file. It should be under `/usr/share` or `/usr/local/share` on Linux.
4. Start openocd with the path to the config file. 
	* on Linux, this would be 
	```bash
	openocd -f /usr/share/openocd/scripts/board/ek-lm4f120xl.cfg
	```
5. In your project directory, start gdb with the path to the payload.bin file. 

	```
	arm-none-eabi-gdb payload.bin
	```
6. Tell gdb to connect to openocd:

	```
	target extended-remote :3333
	```
7. To reset the microcontroller:

	```
	monitor reset init
	```
