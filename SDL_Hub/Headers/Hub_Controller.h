#ifndef HUB_CONTROLLER_H
#define HUB_CONTROLLER_H

#include <SDL2/SDL.h>

extern Uint32* Hub_firstSurfacePixel;
extern int Hub_width, Hub_height;

void Hub_SetSize 					(int width, int height);
void Hub_Crate_SDL_Window 			(void (*)(), char * windowName);

#endif