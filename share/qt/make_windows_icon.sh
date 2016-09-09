#!/bin/bash
# create multiresolution windows icon
ICON_SRC=../../src/qt/res/icons/wuzhucoin.png
ICON_DST=../../src/qt/res/icons/wuzhucoin.ico
convert ${ICON_SRC} -resize 16x16 wuzhucoin-16.png
convert ${ICON_SRC} -resize 32x32 wuzhucoin-32.png
convert ${ICON_SRC} -resize 48x48 wuzhucoin-48.png
convert wuzhucoin-16.png wuzhucoin-32.png wuzhucoin-48.png ${ICON_DST}

