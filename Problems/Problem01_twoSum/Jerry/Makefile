#!/bin/bash

all: main

main: main.o
	gcc -o main main.o

main.o: main.c
	gcc -c main.c

.PHONY: clean

clean:
	rm *.o main
