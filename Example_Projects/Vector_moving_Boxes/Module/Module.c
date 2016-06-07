#include <Hub_Drawer.h>
#include <Module.h>
#include <stdio.h>

void RenderModuels (Module* modules, int length) {
	for (int i = length - 1; i > 0; i--) {
		Hub_Color = modules[i].color;
		Hub_DrawRect (modules[i].bound.rect);
	}
}
void ModulePressed (SDL_Rect* rect) {

}
void IntialiseModule (Module* module, Search_Context* searchContext) {
	Add_To_Search_Context (&module->bound, searchContext);
}