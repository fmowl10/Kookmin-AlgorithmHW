#!/usr/bin/env bash

fullPath=$1

path="${fullPath%.*}"


# compile it
gcc $fullPath -o $path -lm -g

# diff
inFile="${path}-in.txt"
outFile="${path}-out.txt"

diff -w <($path < $inFile) $outFile > /dev/null

if [ $? -eq 0 ]
then 
    echo "Success"
else
    echo "Fail"
fi