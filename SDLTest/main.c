
#include <SDL2/SDL.h>
#include <stdio.h> 
// #include <stdlib.h>

int main (int argc, char ** argv) {
	SDL_Init (SDL_INIT_VIDEO);
	// SDL_Surface* screen = NULL;
	Uint32 var = 0;
	// screen = SDL_SetVideoMode (640,480, 32, SDL_HWSURFACE);
	char * windowName = "Window";
	SDL_Window* window = SDL_CreateWindow(windowName, 0, 0, 100, 100, 0);
	// SDL_Surface* myVideoSurface = SDL_SetVideoMode(640, 480, 16, var);

	while (1) {
		SDL_Event event;
		while (SDL_PollEvent (&event)) {
			switch (event.type) {
				case SDL_QUIT:
				printf ("\nQuitEvent \n");
				goto end;
			}
		}
	}
	end:
	printf ("Quit \n");
	// SDL_Flip(screen);
	SDL_Quit ();
}