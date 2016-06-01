#include <Hub_Controller.h>
#include <Hub_Drawer.h>
#include <Module.h>


void Update ();

int main () {
	Hub_SetSize (900,500);
	Hub_Crate_SDL_Window (Update, "Window");
}
void Update () {
	Hub_Color = 0x00FFFFFF;
	Hub_ClearBackground ();
	Hub_Color = 0x00000000;
	
	int mouseX, mouseY;
	if (SDL_GetMouseState (&mouseX, &mouseY) & SDL_BUTTON(SDL_BUTTON_LEFT)) {
		Module* module = NewMoudle (mouseX, mouseY, 20, 20);
		RenderModule (module);
	}
}