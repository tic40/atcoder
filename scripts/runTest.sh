#!/bin/sh
filePattern=${1:-test*}

echo "===start runTest.sh==="

g++ -std=gnu++1y -o a.out main.cpp

res=(`find . -type f -name "$filePattern" | sort`)
cnt=${#res[@]}

if [ $cnt = 0 ]; then
  echo "test file not found. filePattern: $filePattern"
  exit
fi

echo "===start test==="
echo "run $cnt tests: ${res[@]}"

for fname in "${res[@]}"
do
  echo "[run $fname]"
  ./a.out < $fname
done

echo "===end test==="
