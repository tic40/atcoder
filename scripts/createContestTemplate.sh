#!/bin/sh
if [ $# = 0 ]; then
  echo 'Argument error: Please specify directory name to be created.'
  exit 1
fi

mkdir $1
arr=(a b c d e f)
for v in ${arr[@]}; do
  mkdir $1/$v
  cp template_simple.cpp $1/$v/main.cpp
done
echo "created a new directory $1"
