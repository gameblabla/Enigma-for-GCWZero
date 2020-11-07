#!/bin/sh
ENIGMA=./enigma.elf
if test -e $ENIGMA; then
    $ENIGMA --data $(pwd)/data $*
else
    echo "Please run './configure' and 'make' to build Enigma."
fi
