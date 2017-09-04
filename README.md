# SocietySimulator

The intention is to recreate many social behaviour (starting from very basic like work and walk) and recreate interaction between
various societies sharing the same territory, everything automated by a very basic AI.

#### Installation

Installation is very simple, at the moment the program is working correctly on Linux and MacOSX. Windows doesn't support colors in
terminal, making the application very hard to understand. As soon as I'll release a graphical version, I will make sure is supported
by all main operating system!

Simply clone the repo
```bash
  git clone https://www.github.com/gabryatfendor/SocietySimulator
```
Change directory into it and make

For MacOS use the special recipe provided by the Makefile to use the correct libraries
```bash
  cd SocietySimulator/
  make macos
```
Otherwise, for Linux and Windows, simply make
```bash
  cd SocietySimulator/
  make all
```

To run the program once installed
```bash
  ./SocietySimulator.out
```
To clean output files
```bash
  make clean
```

##### Debug
To build in debug mode simply
```bash
  make debug
```
In this way gdb will be available.

On mac use the special provided recipe
```bash
  make macos-debug
```

#### CONFIG:

Don't add any configuration except from the current one; you can
still modify the current variables. The format must remain
*variable* = *value*.

#### DOCUMENTATION
A Doxyfile for [Doxygen](http://www.stack.nl/~dimitri/doxygen/index.html) documentation is available. To build it check that Doxygen is installed on your system and the documentation for yuor OS. On UNIX-like system, for example, it's enough to launch the command
```bash
  doxygen Doxyfile
```
while in the root folder. Documentation will be available in a new created folder doc. The default it's to build it only in HTML format, but you can modify the configuration as you wish.
