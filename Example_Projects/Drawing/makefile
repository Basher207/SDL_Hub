#Compiler to be used:
CC=clang

#Project Specific
Project_name = main.c
Project_output = main.o

Header_Directory = Headers
Library_bin_Directory = bin/*.o

SDL_Hub_Directory = ../../SDL_Hub/

all:
	make SDL_Handler
	./$(Project_output)

SDL_Handler:
	$(CC) $(Project_name) $(SDL_Hub_Directory)$(Library_bin_Directory) -I $(SDL_Hub_Directory)$(Header_Directory) -o $(Project_output) -framework SDL2

	#-F $(SDL_Hub_Directory)/SDL/SDL2.framework