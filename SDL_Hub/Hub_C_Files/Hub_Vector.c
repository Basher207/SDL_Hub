#include <Hub_Vector.h>

Hub_Vector Hub_AddVector (Hub_Vector first, Hub_Vector second) {
	Hub_Vector newVector;

	newVector.x = first.x + second.x;
	newVector.y = first.y + second.y;

	return newVector;
}