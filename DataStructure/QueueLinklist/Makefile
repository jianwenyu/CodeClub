#!/bin/bash
cc=gcc
DEBUG_DIR=./debug
RELEASE_DIR=./release
SRC_DIR=./src
OBJ_DIR=./obj
FLAG=
SRC= linklist.c main.c
obj= linklist.o main.o

all: main

# Compile specific target
main:$(OBJ_DIR)/linklist.o $(OBJ_DIR)/main.o
	$(cc) -o $(DEBUG_DIR)/main $(OBJ_DIR)/linklist.o $(OBJ_DIR)/main.o $(FLAG) -I./src


# Compile general source to obj
$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(cc) -c -o $@  $< $(FLAG)


.PHONY: clean release

clean:
	rm $(OBJ_DIR)/*.o $(DEBUG_DIR)/*
	
release:
	cp -f $(DEBUG_DIR)/main $(RELEASE_DIR)/main
