#!/bin/bash
cc=gcc
DEBUG_DIR=./debug
RELEASE_DIR=./release
SRC_DIR=./src
OBJ_DIR=./obj
FLAG= 
SRC= tcpServer.c tcpClient.c
obj= tcpServer.o tcpClient.o

all: tcpServer tcpClient

tcpServer:$(OBJ_DIR)/tcpServer.o
	$(cc) -o $(DEBUG_DIR)/tcpServer $(OBJ_DIR)/tcpServer.o $(FLAG)

tcpClient:$(OBJ_DIR)/tcpClient.o
	$(cc) -o $(DEBUG_DIR)/tcpClient $(OBJ_DIR)/tcpClient.o $(FLAG)


$(OBJ_DIR)/%.o: $(SRC_DIR)/%.c
	$(cc) -c -o $@  $< $(FLAG)

.PHONY: clean release folder

clean:
	rm $(OBJ_DIR)/*.o $(DEBUG_DIR)/*
	
release:
	cp -f $(DEBUG_DIR)/tcpServer $(RELEASE_DIR)/tcpServer
	cp -f $(DEBUG_DIR)/tcpClient $(RELEASE_DIR)/tcpClient

folder:
	bash createFolder.sh