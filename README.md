# wxMP3val

[![Build Status](https://travis-ci.org/cfgnunes/wxmp3val.svg?branch=master)](https://travis-ci.org/cfgnunes/wxmp3val)

wxMP3val is a free front-end for the MP3val.

## Getting Started

### Install from binaries

Link to download the binary files: <https://sourceforge.net/projects/wxmp3val/>

This program has been tested on the following platforms:

* Windows XP, Vista, 7, 8, 10
* Several major Linux distributions

### Install from Personal Package Archives (Ubuntu)

```sh
sudo add-apt-repository -y ppa:cfgnunes/ppa
sudo apt update
sudo apt -y install wxmp3val
```

### Install from sources

This section assumes Ubuntu 14.04 (also tested on Ubuntu 16.04 and Ubuntu 18.04), but the procedure is similar for other Linux distributions. The prerequisites to build the source is to install the following packages:

```sh
sudo apt -y install build-essential cmake
sudo apt -y install libwxgtk3.0-dev
sudo apt -y install mp3val
```

Compile the sources and install with following commands in the terminal:

```sh
mkdir build
cd build
cmake ..
make
sudo make install
```

### Generate Debian package for Linux systems

Install the prerequisites:

```sh
sudo apt -y install devscripts debhelper
```

Run the following command on source directory:

```sh
debuild -us -uc
```

## Built With

Code written completely in C++ using:

* [GCC](https://gcc.gnu.org/) - The GNU Compiler Collection
* [wxWidgets](https://www.wxwidgets.org/) - Open-Source GUI framework
* [wxFormBuilder](https://github.com/wxFormBuilder/) - wxWidgets GUI-builder

Other tools:

* [CMake](https://cmake.org/) - Build, test and package software
* [Inno Setup](http://www.jrsoftware.org/isinfo.php) - Installer for Windows programs

## Contributing

If you spot a bug, or want to improve the code, or even make the content better, you can do the following:

* [Open an issue](https://github.com/cfgnunes/wxlame/issues/new) describing the bug or feature idea;
* Fork the project, make changes, and submit a pull request.

## Versioning

This project uses [SemVer](http://semver.org/) for versioning. For the versions available, see the [tags on this repository](https://github.com/cfgnunes/wxmp3val/tags).

## Authors

* Cristiano Nunes - *Developer*

## License

This program is licensed under the terms of the GNU General Public License version 3. Available online under:
<http://www.gnu.org/licenses/gpl-3.0.html>

## Acknowledgments

* Carlos Sánchez - *Spanish translations*
* Jan Rimmek - *German translations*
* Pavel Fric - *Czech translations*
* Sergey Basalaev - *Russian translations*
