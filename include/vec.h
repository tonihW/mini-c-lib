#ifndef MINI_C_LIB_VEC_H
#define MINI_C_LIB_VEC_H

#include <stdlib.h>

#define VEC_CAP_INC 16

typedef struct vec_s
{
    size_t cap;
    size_t ptr;
    void ** data;
} vec;

void vec_print(vec * v);
void vec_zero(vec * v, size_t ptr);
void vec_malloc_or_realloc(vec * v, size_t len);
void vec_push(vec * v, void * data);
void vec_extend(vec * v, size_t len, void ** data);
void * vec_pop(vec * v, size_t ptr);

#endif // MINI_C_LIB_VEC_H
