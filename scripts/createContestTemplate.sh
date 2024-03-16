#!/bin/sh
if [ $# = 0 ]; then
  echo 'Argument error: Please specify directory name to be created.'
  exit 1
fi

mkdir $1
arr=(a b c d e f g)
for v in ${arr[@]}; do
  mkdir $1/$v
  cp template.cpp $1/$v/main.cpp
done
mv $1 abc/$1
echo "created a new directory abc/$1"
