#include <Hub_Controller.h>
#include <Hub_Drawer.h>
#include <SDL2/SDL_render.h>
#include <Hub_Vector.h>

#define WHITE_COLOR 0x00FFFFFF

Uint32 Hub_Color = WHITE_COLOR;

int Hub_Absolute (int n) {
	if (n < 0)
		return -n;
	return n;
}
Hub_ColorType* Hub_GetPixel (int x, int y) {
  if (x > Hub_width || x < 0 || y > Hub_height || y < 0)
  	return 0;
  Uint32* target_pixel = Hub_firstSurfacePixel + x + y * Hub_width;
  return (Hub_ColorType*)target_pixel;
}
void Hub_SetColor (Hub_ColorType color) {
	Hub_Color = *((Uint32*)&color);
}

void Hub_SetPixelColor(int x, int y) {
  if (x > Hub_width || x < 0 || y > Hub_height || y < 0)
  	return;
  Uint32* target_pixel = Hub_firstSurfacePixel + x + y * Hub_width;
  *target_pixel = Hub_Color;
}

void Hub_DrawPixelsFromPointToPoint (int x, int y, int tX, int tY) {
	while (x != tX || y != tY) {
		Hub_SetPixelColor (x, y);
		int xDelta = tX - x,
			yDelta = tY - y;
		if (Hub_Absolute (xDelta) > Hub_Absolute (yDelta)) {
			x = xDelta > 0 ? x + 1 : x - 1;
		} else {
			y = yDelta > 0 ? y + 1 : y - 1;
		}
	}
	Hub_SetPixelColor (tX, tY);
}
void Hub_DrawRect (SDL_Rect rect) {
	int distanceFromRight = Hub_width - rect.x;
	int distanceFromBottom = Hub_height - rect.y;

	if (distanceFromRight < rect.w) {
		rect.w = distanceFromRight;
	}
	if (distanceFromBottom < rect.h) {
		rect.h = distanceFromBottom;
	}
	Uint32* leftPixel = Hub_firstSurfacePixel;

	leftPixel += (int)rect.x + (int)rect.y * Hub_width;

	for (int y = 0; y < rect.h; y++) {
		Uint32* widthDrawer = leftPixel;
		for (int x = 0; x < rect.w; x++) {
			*widthDrawer = Hub_Color;
			widthDrawer++;
		}
		leftPixel += Hub_width;
	}
}
void Hub_ClearBackground () {
	SDL_Rect screenRect = { 0, 0, Hub_width, Hub_height};
	Hub_DrawRect (screenRect);
}