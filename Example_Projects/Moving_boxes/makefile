#Compiler to be used:
CC=gcc
SHELL := /bin/zsh
#Project Specific

Project_output    := main.o
SDL_Hub_Directory := ../../SDL_Hub/


Project_C_Files  := ./**/*.c
Project_Directories := $(shell echo ./**/)
Project_Header_Search_Directories := $(foreach directory, $(Project_Directories), -I $(directory))

#SDL_Hub handlers
Header_Directory 		:= Headers
Library_bin_Directory 	:= bin/

all:
	make SDL_Handler
	./$(Project_output)

SDL_Handler:
	$(CC) $(Project_C_Files) $(SDL_Hub_Directory)$(Library_bin_Directory)*.o -I $(SDL_Hub_Directory)$(Header_Directory) $(Project_Header_Search_Directories) -o $(Project_output) -framework SDL2