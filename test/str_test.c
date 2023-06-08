#include <str.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TEST(name, func)\
    int test_##name()   \
    {                   \
        func            \
    }

TEST(new,
    str s = str_new("hello world!");
    
    return strcmp(s.data, "hello world!") == 0;
)

TEST(push,
    str s = str_new("hello");
    str_push(&s, " ");
    str_push(&s, "world");
    str_push(&s, "!");

    return strcmp(s.data, "hello world!") == 0;
)

int main(int argc, char * argv[])
{
    int status = 1;

    status &= !test_new();
    status &= !test_push();
    
    return status;
}
