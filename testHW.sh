#!/usr/bin/env bash

fullPath=$1

path="${fullPath%.*}"


# compile it
gcc -std=c11 $fullPath -o $path -lm -w -g

# diff
inFile="${path}-in.txt"
outFile="${path}-out.txt"

out=$(diff -w --color <($path < $inFile) $outFile)

if [ $? -eq 0 ]
then 
    echo "Success"
else
    echo "Fail"
    echo "diff"
    echo $out
fi