#include <Module.h>
#include <Hub_Drawer.h>

Module* NewMoudle (int x, int y, int width, int height) {
	Module* module;
	module = (Module*) malloc (sizeof (Module));
	module->pos.x  = x;
	module->pos.y  = y;
	module->size.x = width;
	module->size.y = height;

	return module;
}

Module* AddModuleToLink (ModuleLink* modulelink) {

	ModuleLink* lastModule = modulelink;
	while (lastModule->nextModule != 0) {
		lastModule = lastModule->nextModule;
	}

	ModuleLink* newLink = calloc (1, sizeof (ModuleLink));
	lastModule->nextModule = newLink;

	return &newLink->thisModule;
}
void RenderModule ();
void RenderModules (ModuleLink* modules) {
	ModuleLink* moduleLink = modules;
	while (moduleLink != 0) {
		RenderModule (&moduleLink->thisModule);
		moduleLink = moduleLink->nextModule;
	}
}
void RenderModule (Module* module) {
	Hub_Color = module->color;
	SDL_Rect rect = {module->pos.x, module->pos.y, module->size.x, module->size.y};
	Hub_DrawRect (rect);
}