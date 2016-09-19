
Debian
====================
This directory contains files used to package cowried/cowrie-qt
for Debian-based Linux systems. If you compile cowried/cowrie-qt yourself, there are some useful files here.

## cowrie: URI support ##


cowrie-qt.desktop  (Gnome / Open Desktop)
To install:

	sudo desktop-file-install cowrie-qt.desktop
	sudo update-desktop-database

If you build yourself, you will either need to modify the paths in
the .desktop file or copy or symlink your cowrie-qt binary to `/usr/bin`
and the `../../share/pixmaps/cowrie128.png` to `/usr/share/pixmaps`

cowrie-qt.protocol (KDE)

