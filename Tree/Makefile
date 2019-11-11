#!/bin/bash
cc=gcc
DEBUG_DIR=./debug
RELEASE_DIR=./release
FLAG=

all: bsttree

bsttree: main.o tree.o
	$(cc) -o $(DEBUG_DIR)/bsttree main.o tree.o $(FLAG) -g

tree: tree.c
	$(cc) -c tree.c $(FLAG)

main: main.c
	$(cc) -c main.c $(FLAG)

.PHONY: clean release

clean:
	rm *.o $(DEBUG_DIR)/bsttree
	
release:
	cp -f $(DEBUG_DIR)/bsttree $(RELEASE_DIR)/bsttree