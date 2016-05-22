
#include <SDL2/SDL.h>
#include <SDL2/SDL_render.h>
#include <stdio.h> 
// #include <stdlib.h>

#define WIDTH 600
#define HEIGHT 600
#define WHITE_COLOR 16777215

SDL_Surface* screenSurface;

int Absolute (int numb) {
	if (numb < 0)
		numb = -numb;
	return numb;
}
void SetPixelColor(int x, int y, Uint32 pixel) {
  if (x > WIDTH || x < 0 || y > HEIGHT || y < 0)
  	return;
  Uint32 *target_pixel = (Uint32 *) screenSurface->pixels + x + y * WIDTH;
  *target_pixel = pixel;
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
}
int main (int argc, char ** argv) {
	SDL_Init (SDL_INIT_VIDEO);

	Uint32 var = 0;

	char * windowName = "Window";
	SDL_Window* window = SDL_CreateWindow(windowName, 0, 0, WIDTH, HEIGHT, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer (window,-1, 0);

	Uint32 rmask, gmask, bmask, amask;


	screenSurface = SDL_CreateRGBSurface (0, WIDTH, HEIGHT, 32, 0, 0, 0, 0);
	SDL_Texture* texture = SDL_CreateTexture (renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, WIDTH, HEIGHT);

	SDL_Rect texture_rect;
	texture_rect.x = 0;
	texture_rect.y = 0;
	texture_rect.w = WIDTH;
	texture_rect.h = HEIGHT;

	int x, y;
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
		// SDL_RenderClear(renderer);
		SDL_DestroyTexture(texture);

		int tX, tY;
		SDL_GetMouseState (&tX, &tY);

		DrawPixelsFromPointToPoint (x, y, tX, tY);
		x = tX;
		y = tY;

		texture = SDL_CreateTextureFromSurface (renderer, screenSurface);

		SDL_RenderCopy (renderer, texture, NULL, &texture_rect);
		SDL_RenderPresent(renderer);
		// SDL_Delay (16);
		if (++x > WIDTH) {
			printf ("Edge reached \n");
			goto end;
		}
	}
	end:
	printf ("Quit \n");	SDL_Quit ();
}