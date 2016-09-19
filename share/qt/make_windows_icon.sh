#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/cowrie.png
ICON_DST=../../src/qt/res/icons/cowrie.ico
convert ${ICON_SRC} -resize 16x16 cowrie-16.png
convert ${ICON_SRC} -resize 32x32 cowrie-32.png
convert ${ICON_SRC} -resize 48x48 cowrie-48.png
convert cowrie-16.png cowrie-32.png cowrie-48.png ${ICON_DST}

