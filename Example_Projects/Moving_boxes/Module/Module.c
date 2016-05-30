#include <Module.h>
#include <Hub_Drawer.h>

typedef struct ModuleLink {
	struct ModuleLink* nextModule;
	Module* thisModule;
} ModuleLink;


//Module link start
ModuleLink* modules;

int numberOfModules;

Module* NewMoudle (int x, int y, int width, int height) {
	Module* module;
	module = (Module*) malloc (sizeof (Module));
	module->pos.x  = x;
	module->pos.y  = y;
	module->size.x = width;
	module->size.y = height;

	return module;
}

void AddModule (Module* module) {
	ModuleLink* lastModule = modules;
	while (lastModule->nextModule != 0) {
		lastModule = lastModule->nextModule;
	}
	ModuleLink newLink;
	newLink.thisModule = module;
	lastModule->nextModule = &newLink;
}
void RenderModule ();
void RenderModules () {
	ModuleLink* moduleLink = modules;
	while (moduleLink != 0) {
		RenderModule (moduleLink->thisModule);
		moduleLink = moduleLink->nextModule;
	}
}
void RenderModule (Module* module) {
	Hub_DrawRect (module->pos, module->size);
}