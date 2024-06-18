#include <stdio.h>

#define VECTOR_T int // set the type
#define VECTOR_NAME IntVector // set the name of the datatype
#define VECTOR_PREFIX veci_ // set the function prefix
#define IMPLEMENT // implement the functions
#include <ds/vector.h>

void veci_print(IntVector *vec){
    for(size_t i = 0;i < veci_size(vec);i++){
        printf("%d ", vec->data[i]);
    }
    printf("\n");

}

int main(int argc, char const* argv []) {

    IntVector vec = { 0 };
    printf("Push Back \n");
    veci_push_back(&vec, 10);
    veci_push_back(&vec, 11);
    veci_push_back(&vec, 12);
    veci_push_back(&vec, 13);
    veci_push_back(&vec, 14);
    veci_push_back(&vec, 15);

    veci_print(&vec);

    printf("Insert\n");
    veci_insert(&vec, 2, 2);
    veci_insert(&vec, 3, 2);
    veci_insert(&vec,4,2);
    
    veci_print(&vec);

    printf("Pop back\n");
    for(int i = 0;i < 3;i++) {
        printf("%d \n", veci_pop_back(&vec));
    }

    veci_print(&vec);

    printf("Remove \n");

    for(int i = 0;i < 3;i++){
        veci_remove(&vec, 1);
    }

    veci_print(&vec);

    veci_delete(&vec);
    
    return 0;
}
