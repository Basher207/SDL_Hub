#include <Hub_Controller.h>
#include <Hub_Drawer.h>

#include <SDL2/SDL_render.h>

#define WHITE_COLOR 0x00FFFFFF

int Hub_Absolute (int n) {
	if (n < 0)
		return -n;
	return n;
}
void Hub_SetPixelColor(int x, int y, Uint32 pixel) {
  if (x > Hub_width || x < 0 || y > Hub_height || y < 0)
  	return;
  Uint32 *target_pixel = (Uint32 *)Hub_firstSurfacePixel + x + y * Hub_width;
  *target_pixel = pixel;
}
void Hub_DrawPixelsFromPointToPoint (int x, int y, int tX, int tY) {
	while (x != tX || y != tY) {
		Hub_SetPixelColor (x, y, WHITE_COLOR);
		int xDelta = tX - x,
			yDelta = tY - y;
		if (Hub_Absolute (xDelta) > Hub_Absolute (yDelta)) {
			x = xDelta > 0 ? x + 1 : x - 1;
		} else {
			y = yDelta > 0 ? y + 1 : y - 1;
		}
	}
	Hub_SetPixelColor (tX, tY, WHITE_COLOR);
}