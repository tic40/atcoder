#!/bin/sh
if [ $# = 0 ]; then
  echo '作成するディレクトリ名を指定してください'
  exit 1
fi

mkdir $1
arr=(a b c d e)
for v in ${arr[@]}; do
  mkdir $1/$v
  cp template.cpp $1/$v/main.cpp
done
echo "created a new directory $1"
