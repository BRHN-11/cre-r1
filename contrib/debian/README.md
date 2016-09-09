
Debian
====================
This directory contains files used to package wuzhucoind/wuzhucoin-qt
for Debian-based Linux systems. If you compile wuzhucoind/wuzhucoin-qt yourself, there are some useful files here.

## wuzhucoin: URI support ##


wuzhucoin-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install wuzhucoin-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your wuzhucoin-qt binary to `/usr/bin`
and the `../../share/pixmaps/wuzhucoin128.png` to `/usr/share/pixmaps`

wuzhucoin-qt.protocol (KDE)

