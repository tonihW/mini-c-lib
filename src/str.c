#include "str.h"
#include <string.h>
#include <assert.h>

str str_new(char * data)
{
    assert(data != NULL);
    
    str s;
    s.len = strlen(data);
    s.data = malloc((s.len + 1) * sizeof(char));
    memcpy(s.data, data, s.len + 1);
    
    return s;
}

void str_free(str * s)
{
    assert(s != NULL && s->data != NULL);
    
    free(s->data);
}

void str_push(str * s, char * data)
{
    assert(s != NULL && s->data != NULL);
    assert(data != NULL);
    
    size_t data_len = strlen(data);
    size_t new_len = s->len + data_len;
    char * new_data = realloc(s->data, (new_len + 1) * sizeof(char));
    assert(new_data != NULL);
    s->data = new_data;
    memcpy(&s->data[s->len], data, data_len + 1);
    s->len = new_len;
}
