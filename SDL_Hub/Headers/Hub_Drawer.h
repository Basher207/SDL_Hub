#ifndef HUB_DRAWER_H
#define HUB_DRAWER_H

#include <SDL2/SDL.h>
#include <Hub_Vector.h>

extern Uint32 Hub_Color;

//Since alpha is ignored, typeIndex is used to identify which object is being pressed if any.

typedef struct Hub_ColorType {
	unsigned char b, g, r, typeIndex;
} Hub_ColorType;

void Hub_SetColor (Hub_ColorType color);
Hub_ColorType* Hub_GetPixel (int x, int y);
void Hub_SetPixelColor				(int x, int y);
void Hub_DrawPixelsFromPointToPoint (int x, int y, int tX, int tY);
void Hub_DrawRect (SDL_Rect rect);
void Hub_ClearBackground ();
#endif