#!/usr/bin/env bash

echo -n "1000"
for _ in {0..999};
do
    echo -n " 9"
done
echo ""

echo -n "1000"
for i in {1..1000};
do
    echo -n " $i"
done
echo ""

echo -n "1000"
for i in {1000..1};
do
    echo -n " $i"
done
echo ""

