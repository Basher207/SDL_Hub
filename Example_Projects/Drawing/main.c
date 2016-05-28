#include <Hub_Controller.h>
#include <Hub_Drawer.h>

int Update ();

int main () {
	Hub_SetSize (900,500);
	Hub_Crate_SDL_Window (Update, "Window");
}
int Update () {
	static int pX, pY;
	int currentX, currentY;
	if (SDL_GetMouseState (&currentX, &currentY) & SDL_BUTTON(SDL_BUTTON_LEFT))
		Hub_DrawPixelsFromPointToPoint (pX, pY, currentX, currentY);
	pX = currentX; pY = currentY;
	return Hub_Continue;
}