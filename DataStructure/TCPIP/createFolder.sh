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
echo "debug folder not exist, creating debug file"
mkdir debug
else
echo "debug exist, you are good to go"
fi

if [ ! -d "./release" ]
then
echo "release folder not exist, creating release file"
mkdir release
else
echo "release exist, you are good to go"
fi

if [ ! -d "./src" ]
then
echo "src folder not exist, creating src file"
mkdir src
else
echo "src exist, you are good to go"
fi