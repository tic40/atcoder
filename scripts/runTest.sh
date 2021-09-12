#!/bin/sh
filePattern=${1:-test*}

echo "===start runTest.sh==="

if [ -e a.out ]; then
  rm a.out
fi

# compile
g++ -std=gnu++17 -Wall -Wextra -O2 main.cpp

if [ ! -e a.out ]; then
  echo "Error: Compile error."
  exit 1
fi

# get test files
res=(`find . -type f -name "$filePattern" | sort`)
cnt=${#res[@]}

if [ $cnt = 0 ]; then
  echo "Error: cannot find test file. filePattern: $filePattern"
  exit 1
fi

echo "===start test==="
for fname in "${res[@]}"; do
  echo "\n[input $fname]"
  ./a.out < $fname
done
echo "\n===end: run $cnt tests.==="
