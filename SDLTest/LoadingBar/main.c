
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h> 
// #include <stdlib.h>

#define WIDTH 200
#define HEIGHT 400
void set_pixel_index(SDL_Surface *surface, int pixelIndex, Uint32 pixel) {
  Uint32 *target_pixel = (Uint32 *) surface->pixels + pixelIndex;
  *target_pixel = pixel;
}
int main (int argc, char ** argv) {
	SDL_Init (SDL_INIT_VIDEO);

	Uint32 var = 0;

	char * windowName = "Window";
	SDL_Window* window = SDL_CreateWindow(windowName, 0, 0, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer (window,-1, 0);

	Uint32 rmask, gmask, bmask, amask;


	SDL_Surface* surface = SDL_CreateRGBSurface (0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
	SDL_Texture* texture = SDL_CreateTexture (renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

	SDL_Rect texture_rect;
	texture_rect.x = 0;
	texture_rect.y = 0;
	texture_rect.w = WIDTH;
	texture_rect.h = HEIGHT;
	int x = 0;
	while (1) {
		SDL_Event event;
		while (SDL_PollEvent (&event)) {
			switch (event.type) {
				case SDL_QUIT:
				printf ("QuitEvent \n");
				goto end;

				case SDL_KEYDOWN:
				printf ("KeyPressed qutting \n");
				goto end;
			}
		}
		SDL_RenderClear(renderer);
		SDL_DestroyTexture(texture);
		for (int i = 0; i < HEIGHT; i++) {
			set_pixel_index (surface, x + i * WIDTH, 16777215);
		}
		texture = SDL_CreateTextureFromSurface (renderer, surface);

		SDL_RenderCopy (renderer, texture, NULL, &texture_rect);
		SDL_RenderPresent(renderer);
		SDL_Delay (16);
		if (++x > WIDTH) {
			printf ("Edge reached \n");
			goto end;
		}
	}
	end:
	printf ("Quit \n");	SDL_Quit ();
}