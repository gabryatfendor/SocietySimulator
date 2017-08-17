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
```bash
  cd SocietySimulator/
  make
```
To run the program once installed
```bash
  ./SocietySimulator.out
```
To clean output files
```bash
  make clean
```
#### TODO:

* The main task at the moment is to implement a smart moving algorithm. The one that I'm using at the moment it's working, but
sometimes get stuck into walls (check [issue #1](https://github.com/gabryatfendor/SocietySimulator/issues/1) for more info);
* Make a readable configuration file, so we don't have to change #define everytime (again, refer to [issue #4](https://github.com/gabryatfendor/SocietySimulator/issues/4));
* Lastly, the application should become graphic. The sooner the better, so we don't have to rewrite a ton of code, since as per now we handle everything like a big console grid.
