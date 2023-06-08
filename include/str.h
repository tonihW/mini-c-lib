#ifndef MINI_C_LIB_STR_H
#define MINI_C_LIB_STR_H

#include <stdlib.h>

typedef struct str_s
{
    size_t len;
    char * data;
} str;

str str_new(char * data);
void str_free(str * s);
void str_push(str * s, char * data);

#endif // MINI_C_LIB_STR_H
