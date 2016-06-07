#ifndef MODULE_H
#define MODULE_H

#include <MouseHandler.h>

#ifdef MOUSEHANDLER_H

typedef struct Module {
	Bound bound;
	Uint32 color;
} Module;

void RenderModuels (Module* modules, int length);
void IntialiseModule (Module* module, Search_Context* searchContext);
// void ModulePressed (SDL_Rect* rect);

#endif
#endif