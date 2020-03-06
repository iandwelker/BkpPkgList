#!/bin/bash

export DIR="$HOME/StartupScripts/BkpPkgList"

if ! ls $DIR/ | grep -q orig.txt; then
	pacman -Q | cut -d" " -f1 > $DIR/orig.txt
else
	pacman -Q | cut -d" " -f1 | grep -xvf $DIR/orig.txt > $DIR/new.txt
	sort -s -m -o $DIR/tmp.txt $DIR/orig.txt $DIR/new.txt
	mv $DIR/tmp.txt $DIR/orig.txt && rm $DIR/new.txt
fi
