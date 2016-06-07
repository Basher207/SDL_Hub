#include <MouseHandler.h>

void Add_To_Search_Context (Bound* bound, Search_Context* context) {
	context->bounds[context->length] = bound;
	context->length++;
}

// To do
// Sort modules, and use a faster search through them (If it ever becomes necessary)

SDL_Rect* Start_Search_On (int x, int y, Search_Context* context) {
	for (int i = 0; i < context->length; i++) {
		SDL_Rect rect = context->bounds[i]->rect;
		if (rect.x < x && rect.x + rect.w > x && rect.y < y && rect.y + rect.h > y) {
			return &context->bounds[i]->rect;;
		}
	}
	return 0;
}