#!/bin/sh
filePattern=${1:-test*}
self_dir=$(cd $(dirname $0); pwd)

echo "===start runTest.sh==="

if [ -e a.out ]; then
  rm a.out
fi

# compile with ac-library
g++ -std=gnu++2b -O2 -Wall -Wextra -ld_classic -I ${self_dir}/../libraries/ac-library main.cpp

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

rm ./a.out
echo "\n===end: run $cnt tests.==="
