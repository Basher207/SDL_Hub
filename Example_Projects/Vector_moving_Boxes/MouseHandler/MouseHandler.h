#ifndef MOUSEHANDLER_H
#define MOUSEHANDLER_H

#include <SDL2/SDL.h>

#define  numberOfModules 225

typedef enum BoundType {
	module = 0,
	length
} BoundType;

void ModulePressed (SDL_Rect* rect);

//TODO: Associate the Bound Type with the function that needs to be called
// void (*EquivelantFunctions[])(SDL_Rect* rect) = 
// 	{
// 		ModulePressed
// 	};

typedef struct Bound {
	SDL_Rect rect;
	BoundType boundType;
} Bound;

typedef struct Search_Context {
	Bound* bounds [225];
	int length;
} Search_Context;

void Add_To_Search_Context (Bound* bound, Search_Context* context);
SDL_Rect* Start_Search_On (int x, int y, Search_Context* context);

#endif