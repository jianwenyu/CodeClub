#!/bin/bash
cc=gcc
DEBUG_DIR=./debug
RELEASE_DIR=./release
SRC_DIR=./src
OBJ_DIR=./obj
FLAG= -pthread
SRC= thread.c thread2.c
obj= thread.o thread.o

all: thread thread2

thread2:$(OBJ_DIR)/thread2.o
	$(cc) -o $(DEBUG_DIR)/thread2 $(OBJ_DIR)/thread2.o $(FLAG)

thread:$(OBJ_DIR)/thread.o
	$(cc) -o $(DEBUG_DIR)/thread $(OBJ_DIR)/thread.o $(FLAG)


$(OBJ_DIR)/thread2.o: $(SRC_DIR)/thread2.c
	$(cc) -o $(OBJ_DIR)/thread2.o -c $(SRC_DIR)/thread2.c  

$(OBJ_DIR)/thread.o: $(SRC_DIR)/thread.c
	$(cc) -o $(OBJ_DIR)/thread.o -c $(SRC_DIR)/thread.c  

.PHONY: clean release

clean:
	rm $(OBJ_DIR)/*.o $(DEBUG_DIR)/*
	
release:
	cp -f $(DEBUG_DIR)/thread $(RELEASE_DIR)/thread
	cp -f $(DEBUG_DIR)/thread2 $(RELEASE_DIR)/thread2