#ifndef _POINTER_FUNCS_H_
#define _POINTER_FUNCS_H_


void add_from_pointer(int *x, int *y, int *z);
void mul_from_pointer(int *x, int *y, int *z);
bool is_global(int *num);
bool is_local(int *num);
bool is_heap(int *num);


#endif
