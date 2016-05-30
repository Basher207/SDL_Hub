#Compiler to be used:
CC=gcc

#Project Specific

Project_C_Files  = *.c ./**/*.c
Project_output   = main.o


Project_Header_Search_Directories = ./**/

#SDL_Hub handlers
Header_Directory 		= Headers
Library_bin_Directory 	= bin/*.o
SDL_Hub_Directory 		= ../../SDL_Hub/

all:
	make SDL_Handler
	./$(Project_output)

SDL_Handler:
	$(CC) $(Project_C_Files) $(SDL_Hub_Directory)$(Library_bin_Directory) -I $(SDL_Hub_Directory)$(Header_Directory) -I $(Project_Header_Search_Directories) -o $(Project_output) -framework SDL2