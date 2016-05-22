#define WHITE_COLOR 16777215

#include <SDL2/SDL.h>

enum UpdateReturn {
	Continue = 0,
	Quit = 1
};
void SetSize (int width, int height);
void SetPixelColor(int x, int y, Uint32 pixel);
void DrawPixelsFromPointToPoint (int x, int y, int tX, int tY);
void Crate_SDL_Window (int (*)(), char * windowName);	