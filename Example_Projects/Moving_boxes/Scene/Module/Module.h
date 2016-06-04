#ifndef MODULE_H
#define MODULE_H

#include <Hub_Vector.h>
#include <Hub_Drawer.h>

typedef struct Module {
	Hub_Vector pos;
	Hub_Vector size;

	Uint32 color;
} Module;

typedef struct ModuleLink {
	struct ModuleLink* nextModule;
	Module thisModule;
} ModuleLink;

void RenderModules ();
Module* AddModuleToLink (ModuleLink* modulelink);
Module* NewMoudle (int x, int y, int width, int height);

void RenderModules (ModuleLink* modules);
void RenderModule (Module* module);

#endif