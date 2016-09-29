# GUI-Template-for-3DS-homebrews
Template for basic homebrews using sf2d, sftd and sfil

![example](http://i.imgur.com/956NLCI.png)

---

# Usage

You can use this template to make basic GUI to your homebrews. This code provides a simple template that sets up the basic infrastructure for your 3DS homebrew application, and has a bit of functions that allows you to print menu entries in the screen.

**This is meant as a base**, you can modify it as you wish. Default location for UI assets is in **romfs**, that is automatically loaded by the application.

---

# Compiling

You should have [portlibs](https://github.com/xerpi/3ds_portlibs) (including [sf2d](https://github.com/xerpi/sf2dlib), [sftd ](https://github.com/xerpi/sftdlib) and [sfil](https://github.com/xerpi/sfillib)) already installed to be able to compile this, [ctrulib](https://github.com/smealum/ctrulib) and [devKitPro](https://devkitpro.org/). Just run **make** and .3dsx build will come. If you want to compile a .cia, just provide needed files by yourself and uncomment cia related lines into the makefile.

---

# Credits

* everyone who collaborated to ctrulib
* xerpi for sf2d, sftd and sfil
