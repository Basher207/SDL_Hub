#ifndef HUB_DRAWER_H
#define HUB_DRAWER_H

#include <SDL2/SDL.h>

void Hub_SetPixelColor				(int x, int y, Uint32 pixel);
void Hub_DrawPixelsFromPointToPoint (int x, int y, int tX, int tY);

#endif