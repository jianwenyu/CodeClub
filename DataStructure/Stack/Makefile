#!/bin/bash
cc=gcc
DEBUG_DIR=./debug
RELEASE_DIR=./release
SRC_DIR=./src
OBJ_DIR=./obj
FLAG=
SRC= stack.c
obj= stack.o

all: main

# Compile specific target
main:$(OBJ_DIR)/stack.o
	$(cc) -o $(DEBUG_DIR)/main $(OBJ_DIR)/stack.o $(FLAG) -I./src

# Compile general source to obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(cc) -c -o $@  $< $(FLAG)


.PHONY: clean release

clean:
	rm $(OBJ_DIR)/*.o $(DEBUG_DIR)/*
	
release:
	cp -f $(DEBUG_DIR)/main $(RELEASE_DIR)/main
