#!/bin/sh

source make_env.sh

CUR_DIR = $PWD

cd $DEVKITARM
# libnds
cd libnds
make
cd ..
# dswifi
cd dswifi
make install-nds
cd ..
# maxmod
cd maxmod
make install-nds
cd ..
# default_arm7
cd default_arm7
make install
cd $CUR_DIR

