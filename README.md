FindIt Plugin for OpenCPN
=======================================

This is FindIt originally developed by Konnibe.  I have forked this from his
git repository and I am continuing development.  Konnibe has been unable to continue
development on this logbook due to ill health.

This plugin can work together with the LogbookKonni plugin.
If there are items ready for buying and the Buy It button is pushed, the item(s) 
will be transferred to the Maintenance/BuyParts page on the Logbook plugin.

Del   
SV Chiara Stella   
http://sailchiarastella.blogspot.com/

Binary Distribution
===================

Stand by, we're working on it.

Compiling
=========

This plugin now builds out of the OpenCPN source tree.  You do not need to build
the entire of OpenCPN or even clone it from git just to build this plugin.  It
should, however, also successfully build from inside the OpenCPN source tree along
with the rest of OpenCPN if you clone it into the OpenCPN/plugins directory.

If you need instructions as to how to build OpenCPN then see the developers
manual at http://opencpn.org/ocpn/developers_manual

You need to have all of the dependencies required to compile OpenCPN installed in
order to be able to build this plugin.  Those might vary depending on your system.

###Clone this repository from github

You might choose to fork this repository on github so you might
use your own git: URL instead of the one below.

```
git clone https://github.com/delatbabel/FindIt_pi
```

or, from your own fork, a command similar to this (replace delatbabel with
your own git user name):

```
git clone git@github.com:delatbabel/FindIt_pi.git FindIt_pi
```

###Build on Linux

Note that you will need to have all of the development tools installed that
are required to build OpenCPN.  If you have any doubts then run the cmake ..
command and it will complain about missing dependencies.  At the very least
you will need the g++ compiler and development libraries, cmake, gettext, so
install those first and see how far you get.

```
mkdir FindIt_pi/build
cd FindIt_pi/build
cmake ..
cmake --build .
```

###Build on Mac OS X

Tools: Can be installed either manually or from Homebrew (http://brew.sh)

```
#brew install git #If I remember well, it is already available on the system
brew install cmake
brew install gettext
ln -s /usr/local/Cellar/gettext/0.19.2/bin/msgmerge /usr/local/bin/msgmerge
ln -s /usr/local/Cellar/gettext/0.19.2/bin/msgfmt /usr/local/bin/msgfmt
```

To target older OS X versions than the one you are running, you need the respective SDKs installed. The easiest way to achieve that is using https://github.com/devernay/xcodelegacy

####Building wxWidgets
(do not use wxmac from Homebrew, it is not compatible with OpenCPN)
Get wxWidgets 3.0.x source from http://wxwidgets.org
Configure, build and install
```
cd wxWidgets-3.0.2
./configure --enable-unicode --with-osx-cocoa --with-macosx-sdk=/Applications/Xcode.app/Contents/Developer/Platforms/MacOSX.platform/Developer/SDKs/MacOSX10.7.sdk/ --with-macosx-version-min=10.7 --enable-aui --disable-debug --enable-opengl
make
sudo make install
```

####Building the plugin
Before running cmake, you must set the deployment target to OS X 10.7 to be compatible with the libraries used by core OpenCPN
```
export MACOSX_DEPLOYMENT_TARGET=10.7

mkdir FindIt_pi/build
cd FindIt_pi/build
cmake ..
cmake --build .
```

Packaging
=========

From inside the build directory, the following command will make packages for your
current platform against the as-built code:

```
make package
```

Note that you will need to have the packaging tools installed for your platform and
any other platforms that you build packages for.  e.g. on Ubuntu you will need the
development tools required to build deb file as well as the rpm package required to
build RPM files.

To check the contents of the Debian/Ubuntu package, use this command:

```
dpkg -c FindIt_pi_1.01-1_amd64.deb
```

###Packaging on OS X
Get and install the Packages application from http://s.sudre.free.fr/Software/Packages/about.html
After installing Packages create the Plugin package.
```
make create-pkg
```
This will create the FindIt-Plugin_1.0.pkg file in the build directory.
Executing this file will install the plugin.

Building zip files
==================

I can't find any way to successfully build a zip file with cmake, all of
the online documentation about how to do this appears to be incorrect.

On Linux you can use the makezip.sh script to make the required zip files.
They can be installed using the instructions in the "Install Additional Files"
section below.

These zip files will be distributed with the plugin when we make a release.

The language files are included with the packages, the layouts and the help
files are not and will need to be separately installed.

Enable the Plugin
=================

* Start OpenCPN
* Select Options from the toolbar (spanner icon) and go to the Plugins tab.
* Select the Logbook plugin and click Enable to enable the plugin.


License
=======
The plugin code is licensed under the terms of the GPL v2 or, at your will, later. 
