#include "vec.h"
#include <stdio.h>
#include <assert.h>

#define SWAP(T, a, b) do { T tmp = a; a = b; b = tmp; } while (0)

void vec_print(vec * v)
{
    printf("cap: %zu, ptr: %zu\n", v->cap, v->ptr);
}

void vec_zero(vec * v, size_t ptr)
{
    assert(ptr >= v->ptr);
    
    for (size_t i = ptr; i < v->cap; i++)
    {
        v->data[i] = NULL;
    }
}

void vec_malloc_or_realloc(vec * v, size_t len)
{
    if (v->data == NULL)
    {
        v->cap = (len <= VEC_CAP_INC) ? VEC_CAP_INC : len;
        v->ptr = 0;
        v->data = malloc(v->cap * sizeof(void *));
        assert(v->data != NULL);
        vec_zero(v, v->ptr);
    }
    else
    {
        if (v->ptr + len > v->cap)
        {
            v->cap += (len <= VEC_CAP_INC) ? VEC_CAP_INC : len;
            void ** data_new = realloc(v->data, v->cap * sizeof(void *));
            assert(data_new != NULL);
            v->data = data_new;
            vec_zero(v, v->ptr);
        }
    }
}

void vec_push(vec * v, void * data)
{
    vec_malloc_or_realloc(v, 1);
    v->data[v->ptr++] = data;
}

void vec_extend(vec * v, size_t len, void ** data)
{
    vec_malloc_or_realloc(v, len);
    for (size_t i = 0; i < len; i++)
    {
        v->data[v->ptr++] = data[i];
    }
}

void * vec_pop(vec * v, size_t ptr)
{
    assert(ptr < v->ptr);
    
    void * popped = v->data[ptr];
    v->data[ptr] = NULL;
    for (size_t i = ptr; i < v->ptr; i++)
    {
        SWAP(void *, v->data[i], v->data[i + 1]);
    }
    v->ptr--;
    
    return popped;
}
