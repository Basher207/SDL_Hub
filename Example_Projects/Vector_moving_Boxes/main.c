#include <Hub_Controller.h>
#include <Hub_Drawer.h>

#include <MouseHandler.h>
#include <Module.h>

#include <stdio.h>

Module modules [numberOfModules];
Search_Context mouseSearchContext;

void Update ();

int main () {
	Hub_SetSize (720,600);
	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 15; y++) {
			IntialiseModule (&modules[x + y * 15],&mouseSearchContext);
			modules[x + y * 15].bound.rect.x = x * 30;
			modules[x + y * 15].bound.rect.y = y * 30;
			modules[x + y * 15].bound.rect.w = 25;
			modules[x + y * 15].bound.rect.h = 25;
			modules[x + y * 15].color  = x * 0x000F0000;
			modules[x + y * 15].color += y * 0x00000F00;
		}
	}
	Hub_Crate_SDL_Window (Update, "Window");
}
void Update () {
	Hub_Color = 0x00FFFFFF;
	Hub_ClearBackground ();
	Hub_Color = 0x00000000;

	static SDL_Rect* selectedBound = 0;
	static int previousX, previousY;
	int mouseX, mouseY;
	if (SDL_GetMouseState (&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		if (selectedBound == 0) {
			selectedBound = Start_Search_On (mouseX, mouseY,&mouseSearchContext);
		} else {
			if (selectedBound != 0) {
				selectedBound->x += mouseX - previousX;
				selectedBound->y += mouseY - previousY;
			}
		}
	} else {
		selectedBound = 0;
	}
	previousX = mouseX;
	previousY = mouseY;

	RenderModuels (modules, numberOfModules);
}