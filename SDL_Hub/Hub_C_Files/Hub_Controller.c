#include <Hub_Controller.h>
#include <SDL2/SDL_render.h>

#define WHITE_COLOR 0x00FFFFFF

SDL_Surface* Hub_ScreenSurface;

Uint32* Hub_firstSurfacePixel = NULL;
int Hub_width = 500, Hub_height = 500;

void Hub_SetSize (int w, int h) {
	if (Hub_ScreenSurface == NULL) {
		Hub_width  = w;
		Hub_height = h;
	} else {
		printf ("Window already created");
	}
}
void Hub_Crate_SDL_Window (int (*updateFunction)(), char * windowName) {
	if (Hub_ScreenSurface != NULL)
		return;
	SDL_Init (SDL_INIT_VIDEO);
	SDL_Window* window = SDL_CreateWindow(windowName, 0, 0, Hub_width, Hub_height, 0);
	SDL_Renderer* renderer = SDL_CreateRenderer (window,-1, 0);

	Uint32 rmask, gmask, bmask, amask;


	Hub_ScreenSurface = SDL_CreateRGBSurface (0, Hub_width, Hub_height, 32, 0, 0, 0, 0);
	Hub_firstSurfacePixel = Hub_ScreenSurface->pixels;
	SDL_Texture* texture = SDL_CreateTexture (renderer, SDL_PIXELFORMAT_RGB888, SDL_TEXTUREACCESS_STREAMING, Hub_width, Hub_height);

	SDL_Rect texture_rect;
	texture_rect.x = 0;
	texture_rect.y = 0;
	texture_rect.w = Hub_width;
	texture_rect.h = Hub_height;

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
		if (updateFunction () == Hub_Quit)
			goto end;
		texture = SDL_CreateTextureFromSurface (renderer, Hub_ScreenSurface);

		SDL_RenderCopy (renderer, texture, NULL, &texture_rect);
		SDL_RenderPresent(renderer);
		// SDL_Delay (16);
	}
	end:
	printf ("Quit \n");	SDL_Quit ();
}