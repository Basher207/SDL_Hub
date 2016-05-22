#Compiler to be used:
CC=clang

SDL_LINK = -framework SDL2

Project_name = main
SDL_Handler_FileName = SDL_Handler

all:
	make SDL_Handler
	./$(Project_name).o


SDL_Handler:
	$(CC) $(Project_name).c $(SDL_Handler_FileName).c $(SDL_LINK) -o $(Project_name).o