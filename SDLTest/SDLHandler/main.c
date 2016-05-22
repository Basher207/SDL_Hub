#include "SDL_Handler.h"

int Update ();

int main () {
	SetSize (900,500);
	Crate_SDL_Window (Update, "Window");
}
int Update () {
	static int pX, pY;
	int currentX, currentY;
	if (SDL_GetMouseState (&currentX, &currentY) & SDL_BUTTON(SDL_BUTTON_LEFT))
		DrawPixelsFromPointToPoint (pX, pY, currentX, currentY);
	pX = currentX; pY = currentY;
	return Continue;
}