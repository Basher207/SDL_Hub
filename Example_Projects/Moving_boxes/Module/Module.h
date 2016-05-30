#ifndef MODULE_H
#define MODULE_H

#include <Hub_Vector.h>

typedef struct Module {
	Hub_Vector pos;
	Hub_Vector size;
} Module;

void RenderModules ();

Module* NewMoudle (int x, int y, int width, int height);
void RenderModule (Module* module);

#endif