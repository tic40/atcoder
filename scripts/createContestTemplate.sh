#!/bin/bash
set -euo pipefail

usage() {
  echo "Usage: $0 <contest> [problems...]  e.g. $0 abc440 / $0 arc200 a b c d" >&2
  exit 1
}
[ $# -ge 1 ] || usage

root=$(cd "$(dirname "$0")/.." && pwd)
name=$1
shift
if [ $# -eq 0 ]; then problems=(a b c d e f g); else problems=("$@"); fi

category=${name%%[0-9]*}
dest="$root/$category/$name"

if [ -e "$dest" ]; then
  echo "Error: $dest already exists." >&2
  exit 1
fi

for p in "${problems[@]}"; do
  mkdir -p "$dest/$p"
  cp "$root/template.cpp" "$dest/$p/main.cpp"
done
echo "created $category/$name (${problems[*]})"
