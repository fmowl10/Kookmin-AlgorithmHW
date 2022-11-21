#!/usr/bin/env bash


nth=$1
folderName="hw-${nth}"

name=$2

if [ ! -d "$folderName" ]; then
    mkdir "${folderName}" 2> /dev/null
fi
filelist=( ".c" "-in.txt" "-out.txt" )
for i in ${filelist[@]};
do
    if [ ! -f "${folderName}/HW-${nth}-${name}${i}" ]; then
        touch "${folderName}/HW-${nth}-${name}${i}"
    fi
done