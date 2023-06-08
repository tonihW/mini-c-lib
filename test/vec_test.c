#include <vec.h>
#include <stdio.h>
#include <string.h>
#include <assert.h>

#define TEST(name, func)\
    int test_##name()   \
        func            \

TEST(push, {
    vec v;
    v.data = NULL;
    
    vec_push(&v, "hello");
    vec_push(&v, " ");
    vec_push(&v, "world");
    vec_push(&v, "!");
    
    return v.cap == VEC_CAP_INC && v.ptr == 4;
})

const char * test_extend_data1[] = {
    "hello",
    "world",
    "!",
    "asd"
};
const char * test_extend_data2[] = {
    "test 1",
    "test 2",
    "test 3",
    "test 4"
};
TEST(extend, {
    vec v;
    v.data = NULL;
    
    vec_extend(&v, 4, (void **) test_extend_data1);
    vec_extend(&v, 4, (void **) test_extend_data2);
    
    return v.cap == VEC_CAP_INC && v.ptr == 8;
})

int main(int argc, char * argv[])
{
    int status = 1;

    status &= !test_push();
    status &= !test_extend();
    
    return status;
}
