#ifndef HUB_DRAWER_H
#define HUB_DRAWER_H

#include <SDL2/SDL.h>
#include <Hub_Vector.h>

extern Uint32 Hub_Color;

void Hub_SetPixelColor				(int x, int y);
void Hub_DrawPixelsFromPointToPoint (int x, int y, int tX, int tY);
void Hub_DrawRect (Hub_Vector topLeft, Hub_Vector rectSize);
void Hub_ClearBackground ();

#endif