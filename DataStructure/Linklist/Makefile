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


main:$(OBJ_DIR)/linklist.o $(OBJ_DIR)/main.o
	$(cc) -o $(DEBUG_DIR)/main $(OBJ_DIR)/linklist.o $(OBJ_DIR)/main.o $(FLAG) -I./src


$(OBJ_DIR)/linklist.o: $(SRC_DIR)/linklist.c
	$(cc) -o $(OBJ_DIR)/linklist.o -c $(SRC_DIR)/linklist.c  

$(OBJ_DIR)/main.o: main.c
	$(cc) -o $(OBJ_DIR)/main.o -c main.c  -I./src

.PHONY: clean release

clean:
	rm $(OBJ_DIR)/*.o $(DEBUG_DIR)/*
	
release:
	cp -f $(DEBUG_DIR)/main $(RELEASE_DIR)/thread
