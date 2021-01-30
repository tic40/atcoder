#!/bin/sh
filePattern=${1:-test*}

echo "===start runTest.sh==="
# compile
g++ -std=gnu++1y -o a.out main.cpp

# get test files
res=(`find . -type f -name "$filePattern" | sort`)
cnt=${#res[@]}

if [ $cnt = 0 ]; then
  echo "Error: cannot find test file. filePattern: $filePattern"
  exit 1
fi

echo "===start test==="
echo "run $cnt tests: ${res[@]}"
for fname in "${res[@]}"; do
  echo "[run $fname]"
  ./a.out < $fname
done
echo "===end test==="
