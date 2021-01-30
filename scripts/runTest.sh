#!/bin/sh
filePattern=${1:-test*}

echo "===start runTest.sh==="

g++ -std=gnu++1y -o a.out main.cpp

echo "===start test==="
find . -type f -name "$filePattern" | sort | while read -r fname
do
  echo "[run $fname]"
  ./a.out < $fname
done
echo "===end test==="
