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


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(cc) -c -o $@  $< $(FLAG)

.PHONY: clean release folder

clean:
	rm $(OBJ_DIR)/*.o $(DEBUG_DIR)/*
	
release:
	cp -f $(DEBUG_DIR)/thread $(RELEASE_DIR)/thread
	cp -f $(DEBUG_DIR)/thread2 $(RELEASE_DIR)/thread2

folder:
	bash createFolder.sh