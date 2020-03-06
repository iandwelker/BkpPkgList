#!/bin/bash

if ! ls ~/StartupScripts/BkpPkgList/ | grep -q orig.txt; then
	pacman -Q | cut -d" " -f1 > ~/StartupScripts/BkpPkgList/orig.txt
else
	pacman -Q | cut -d" " -f1 | grep -xvf ~/StartupScripts/BkpPkgList/orig.txt > ~/StartupScripts/BkpPkgList/new.txt
	sort -s -m -o ~/StartupScripts/BkpPkgList/tmp.txt ~/StartupScripts/BkpPkgList/orig.txt ~/StartupScripts/BkpPkgList/new.txt
	mv ~/StartupScripts/BkpPkgList/tmp.txt ~/StartupScripts/BkpPkgList/orig.txt && rm ~/StartupScripts/BkpPkgList/new.txt
fi
