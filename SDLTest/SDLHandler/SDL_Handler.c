#include "SDL_Handler.h"
#include <SDL2/SDL_render.h>
#include <stdio.h> 

int width = 500, height = 500;
SDL_Surface* screenSurface;

int Absolute (int n) {
	if (n < 0)
		return -n;
	return n;
}
void SetPixelColor(int x, int y, Uint32 pixel) {
  if (x > width || x < 0 || y > height || y < 0)
  	return;
  Uint32 *target_pixel = (Uint32 *) screenSurface->pixels + x + y * width;
  *target_pixel = pixel;
}
void SetSize (int w, int h) {
	if (screenSurface == NULL) {
		width  = w;
		height = h;
	} else {
		printf ("Window already created");
	}
}
void DrawPixelsFromPointToPoint (int x, int y, int tX, int tY) {
	while (x != tX || y != tY) {
		SetPixelColor (x, y, WHITE_COLOR);
		int xDelta = tX - x,
			yDelta = tY - y;
		if (Absolute (xDelta) > Absolute (yDelta)) {
			x = xDelta > 0 ? x + 1 : x - 1;
		} else {
			y = yDelta > 0 ? y + 1 : y - 1;
		}
	}
	SetPixelColor (tX, tY, WHITE_COLOR);
}
void Crate_SDL_Window (int (*updateFunction)(), char * windowName) {
	SDL_Init (SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow(windowName, 0, 0, width, height, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer (window,-1, 0);

	Uint32 rmask, gmask, bmask, amask;


	screenSurface = SDL_CreateRGBSurface (0, width, height, 32, 0, 0, 0, 0);
	SDL_Texture* texture = SDL_CreateTexture (renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, width, height);

	SDL_Rect texture_rect;
	texture_rect.x = 0;
	texture_rect.y = 0;
	texture_rect.w = width;
	texture_rect.h = height;

	int x, y;
	while (1) {
		SDL_Event event;
		while (SDL_PollEvent (&event)) {
			switch (event.type) {
				case SDL_QUIT:
				printf ("QuitEvent \n");
				goto end;

				case SDL_KEYDOWN:
				if (event.key.keysym.sym == SDLK_ESCAPE) {
					printf ("Esc pressed qutting \n");
					goto end;
				} else {
					break;
				}
			}
		}
		// SDL_RenderClear(renderer);
		SDL_DestroyTexture(texture);
		if (updateFunction () == Quit)
			goto end;
		texture = SDL_CreateTextureFromSurface (renderer, screenSurface);

		SDL_RenderCopy (renderer, texture, NULL, &texture_rect);
		SDL_RenderPresent(renderer);
		// SDL_Delay (16);
	}
	end:
	printf ("Quit \n");	SDL_Quit ();
}