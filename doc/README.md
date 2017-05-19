Cowrie Core 0.10.4
=====================

Setup
---------------------
[Cowrie Core](http://cowrie.org/en/download) is the original Cowrie client and it builds the backbone of the network. However, it downloads and stores the entire history of Cowrie transactions (which is currently several GBs); depending on the speed of your computer and network connection, the synchronization process can take anywhere from a few hours to a day or more. Thankfully you only have to do this once. If you would like the process to go faster you can [download the blockchain directly](bootstrap.md).

Running
---------------------
The following are some helpful notes on how to run Cowrie on your native platform.

### Unix

You need the Qt4 run-time libraries to run Cowrie-Qt. On Debian or Ubuntu:

	sudo apt-get install libqtgui4

Unpack the files into a directory and run:

- bin/32/cowrie-qt (GUI, 32-bit) or bin/32/cowried (headless, 32-bit)
- bin/64/cowrie-qt (GUI, 64-bit) or bin/64/cowried (headless, 64-bit)



### Windows

Unpack the files into a directory, and then run cowrie-qt.exe.

### OS X

Drag Cowrie-Qt to your applications folder, and then run Cowrie-Qt.

### Need Help?

* See the documentation at the [Cowrie Wiki](https://en.cowrie.it/wiki/Main_Page)
for help and more information.
* Ask for help on [#cowrie](http://webchat.freenode.net?channels=cowrie) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net?channels=cowrie).
* Ask for help on the [CowrieTalk](https://cowrietalk.org/) forums, in the [Technical Support board](https://cowrietalk.org/index.php?board=4.0).

Building
---------------------
The following are developer notes on how to build Cowrie on your native platform. They are not complete guides, but include notes on the necessary libraries, compile flags, etc.

- [OS X Build Notes](build-osx.md)
- [Unix Build Notes](build-unix.md)

Development
---------------------
The Cowrie repo's [root README](https://github.com/cowrie/cowrie/blob/master/README.md) contains relevant information on the development process and automated testing.

- [Coding Guidelines](coding.md)
- [Multiwallet Qt Development](multiwallet-qt.md)
- [Release Notes](release-notes.md)
- [Release Process](release-process.md)
- [Source Code Documentation (External Link)](https://dev.visucore.com/cowrie/doxygen/)
- [Translation Process](translation_process.md)
- [Unit Tests](unit-tests.md)

### Resources
* Discuss on the [CowrieTalk](https://cowrietalk.org/) forums, in the [Development & Technical Discussion board](https://cowrietalk.org/index.php?board=6.0).
* Discuss on [#cowrie-dev](http://webchat.freenode.net/?channels=cowrie) on Freenode. If you don't have an IRC client use [webchat here](http://webchat.freenode.net/?channels=cowrie-dev).

### Miscellaneous
- [Assets Attribution](assets-attribution.md)
- [Files](files.md)
- [Tor Support](tor.md)
- [Init Scripts (systemd/upstart/openrc)](init.md)

License
---------------------
Distributed under the [MIT/X11 software license](http://www.opensource.org/licenses/mit-license.php).
This product includes software developed by the OpenSSL Project for use in the [OpenSSL Toolkit](https://www.openssl.org/). This product includes
cryptographic software written by Eric Young ([eay@cryptsoft.com](mailto:eay@cryptsoft.com)), and UPnP software written by Thomas Bernard.
