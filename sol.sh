#!/usr/bin/env bash

set -euo pipefail

src="${1:-}"

if [[ -z "$src" ]]; then
    shopt -s nullglob
    cpp_files=( *.cpp )
    if (( ${#cpp_files[@]} == 0 )); then
        echo ".cpp file no found please check the file once."
        exit 1
    fi
    src="${cpp_files[0]}"
fi

if [[ ! -f "$src" ]]; then
    echo "Source file '$src' does not exist."
    exit 1
fi

infile="in.txt"
outfile="out.txt"

bin="${src%.*}"
#bin="${src%.*}.exe" # if u use window 

echo "Compiling $src -> $bin ..."
g++ -std=c++20 -O2 -Wall -Wextra -DLOCAL "$src" -o "$bin"

echo "Running ./$bin < $infile > $outfile ..."
./"$bin" < "$infile" > "$outfile"

echo "Executed check  $outfile for output"
