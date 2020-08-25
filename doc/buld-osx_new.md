Make sure you have Homebrew installed and all the packages installed by it up to date.

1. Let’s install all the dependencies for Cowrie hacking.

brew install autoconf automake berkeley-db4 boost miniupnpc openssl pkg-config protobuf qt libtool

2. Make sure you have the right OpenSSL version installed. Type the following on your terminal:

openssl version

you should see “OpenSSL 1.0.1f 6 Jan 2014.”

if you see an older version, do

brew update
brew upgrade

OpenSSL should be upgraded, you may or may not have to issue a “brew link openssl” or even a “brew link --overwrite openssl” if it’s giving you trouble.

3. Now, let’s configure, and make. I strongly suggest you add the boost library path when configuring, otherwise you may get nasty “Undefined symbols for architecture x86_64” compilation errors. During the time I wrote this, homebrew had installed boost 1.55 in my system, and the boost lib path was /usr/local/Cellar/boost/1.55.0/lib so I invoked the following:

./configure --with-boost-libdir=/usr/local/Cellar/boost/1.55.0/lib

After that I just issued a

make

And I was done.

If you want to hack the cowrie-qt client like me, head to src/qt/, there should be a cowrie-qt executable there now.

Enjoy
