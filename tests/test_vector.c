#include <testing/tests.h>

#include <stdlib.h>

#define VECTOR_T int
#define VECTOR_NAME IntVector
#define VECTOR_PREFIX veci_
#define IMPLEMENT
#include <ds/vector.h>

Test(push_back_test) {
    IntVector vec = { 0 };
    int *numbers = malloc(1000 * sizeof(int));
    for(int i = 0;i < 1000;i++){
        numbers[i] = rand() % 1000000000;
    }

    for(int i = 0;i < 1000;i++){
        veci_push_back(&vec, numbers[i]);
    }
    
    for(int i = 0;i < 1000;i++){
        IASSERT_EQUAL(numbers[i], vec.data[i], "Iterations");
    }
}

Test(pop_back_test) {
    IntVector vec = { 0 };
    int *numbers = malloc(1000 * sizeof(int));
    for(int i = 0;i < 1000;i++){
        numbers[i] = rand() % 1000000000;
    }

    for(int i = 0;i < 1000;i++){
        veci_push_back(&vec, numbers[i]);
    }

    for(int i = 0;i < 1000;i++){
        IASSERT_EQUAL(numbers[999-i], veci_pop_back(&vec), "Iterations");
    }
}

Test(size_test){
    IntVector vec = { 0 };
    int *numbers = malloc(1000 * sizeof(int));
    for(int i = 0;i < 1000;i++){
        numbers[i] = rand() % 1000000000;
    }

    for(int i = 0;i < 1000;i++){
        veci_push_back(&vec, numbers[i]);
        IASSERT_EQUAL(i+1, veci_size(&vec), "Size wrong");
    }
}

int main(int argc, char const *argv[])
{
    TestModule m = { 0 };
    add_test(&m, push_back_test, "push_back_test");
    add_test(&m, pop_back_test, "pop_back_test");
    add_test(&m, pop_back_test, "size_test");

    run_module(&m);
    return 0;
}
