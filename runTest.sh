#!/bin/sh
filePattern=${1:-test*}

g++ -std=gnu++1y -o a.out main.cpp
find . -type f -name "$filePattern" | sort | while read -r fname
do
  echo "[run $fname]"
  ./a.out < $fname
done