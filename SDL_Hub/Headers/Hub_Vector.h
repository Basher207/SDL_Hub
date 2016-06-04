#ifndef HUB_VECTOR_H
#define HUB_VECTOR_H

typedef struct Hub_Vector {
	float x, y;
} Hub_Vector;
Hub_Vector Hub_AddVector (Hub_Vector first, Hub_Vector second);
#endif