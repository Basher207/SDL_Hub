#include <Hub_Controller.h>
#include <Hub_Drawer.h>
#include <Module.h>
#include <Scene.h>
#include <stdio.h>
#include <time.h>
void Update ();

int main () {
	Hub_SetSize (900,500);
	IntialiseScene ();

	for (int x = 0; x < 15; x++) {
		for (int y = 0; y < 15; y++) {
	
			static unsigned char r = 0;
			r = (r + 10);
			Hub_ColorType col = {0, 0, r, 0};
	
			Module* module = AddModuleToScene (col);
			Hub_ColorType* color = ((Hub_ColorType*)&module->color);
			// printf ("Color r:%d, Color g %d, Color B: %d, typeIndex %d \n", color->r, color->g, color->b, color->typeIndex);
			
			module->pos.x = x * 20;
			module->pos.y = y * 20;
	
		
			module->size.x = 50;
			module->size.y = 50;
		}
	}

	Hub_Crate_SDL_Window (Update, "Window");
}
void Update () {
	UpdateScene ();

	Hub_Color = 0x00FFFFFF;
	Hub_ClearBackground ();
	Hub_Color = 0x00000000;
	RenderScene ();
}