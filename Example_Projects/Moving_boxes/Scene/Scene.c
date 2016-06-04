#include <Scene.h>
#include <stdio.h>
Scene instance;
int moduleIndex;

Module* AddModuleToScene (Hub_ColorType color) {
	Module* newModule;
	color.typeIndex = instance.numberOfModules;
	if (instance.numberOfModules++ == 0) {
		newModule = &instance.moduleLink.thisModule;
	} else {
		newModule = AddModuleToLink (&instance.moduleLink);
	}
	instance.moduleForIndex[instance.numberOfModules - 1] = newModule;
	newModule->color = *((Uint32*)&color);
	return newModule;
}
void IntialiseScene () {
	instance.numberOfModules = 1;
}

void RenderScene () {
	RenderModules (&instance.moduleLink);
}
void UpdateScene () {
	static int previousX, previousY;
	static short selectedBoxIndex = -1;

	int mouseX, mouseY;

	if (SDL_GetMouseState (&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		if (selectedBoxIndex == -1) {
			selectedBoxIndex = Hub_GetPixel (mouseX, mouseY)->typeIndex;
		} else {
			Module* moduleToMove = instance.moduleForIndex[selectedBoxIndex];
			if (moduleToMove != 0) {
				Hub_Vector mouseMovement = {mouseX - previousX, mouseY - previousY};
				moduleToMove->pos = Hub_AddVector (moduleToMove->pos, mouseMovement);
			}
		}

	} else {
		selectedBoxIndex = -1;
	}

	previousX = mouseX;
	previousY = mouseY;

	RenderScene ();
}