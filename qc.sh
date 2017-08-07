#!/bin/bash

log=modify

if [ -n "$1" ]; then
	log=$1
fi

#find . -name "*.sh" | xargs dos2unix
#find . -name "*.sh" | xargs chmod 755

git pull
git add -A
git commit -am "$log"
