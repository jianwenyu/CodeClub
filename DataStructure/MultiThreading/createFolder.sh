#!/bin/bash
echo "Checking file structure correction.."

if [ ! -d "./obj" ]
then
echo "obj folder not exist, create obj file"
mkdir obj
else
echo "obj exist, you are good to go"
fi

if [ ! -d "./debug" ]
then
echo "debug folder not exist, create debug file"
mkdir debug
else
echo "debug exist, you are good to go"
fi