#ifndef SCENE_H
#define SCENE_H

#include <Module.h>

typedef struct Scene {
	ModuleLink moduleLink;
	Module* moduleForIndex[0xFF];

	int numberOfModules;
} Scene;

Module* AddModuleToScene (Hub_ColorType color);

extern Scene instance;

void IntialiseScene ();
void UpdateScene ();
void RenderScene ();

#endif