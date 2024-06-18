#include <stdio.h>

#define VECTOR_T int // set the type
#define VECTOR_NAME IntVector // set the name of the datatype
#define VECTOR_PREFIX veci_ // set the function prefix
#define IMPLEMENT // implement the functions
#define SAFE
#include <ds/vector.h>

void veci_print(IntVector* vec) {
    for (size_t i = 0;i < veci_size(vec);i++) {
        printf("%d ", vec->data[i]);
    }
    printf("\n");

}

int main(int argc, char const* argv []) {

    int error;

    // We expect an error here
    veci_push_back_e(NULL, 10, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }


    IntVector vec = { 0 };
    printf("Push Back \n");

    veci_push_back_e(&vec, 10, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_push_back_e(&vec, 11, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
        error = 0;
    }
    veci_push_back_e(&vec, 12, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_push_back_e(&vec, 13, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_push_back_e(&vec, 14, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_push_back_e(&vec, 15, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }

    veci_print(&vec);

    printf("Insert\n");
    veci_insert_e(&vec, 2, 2, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_insert_e(&vec, 3, 2, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_insert_e(&vec, 4, 2, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }

    // We expect an error here
    veci_insert_e(&vec, 4, 200, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }

    veci_print(&vec);

    printf("Pop back\n");
    for (int i = 0;i < 3;i++) {
        int d = veci_pop_back_e(&vec, &error);
        if (error < 0) {
            printf("Error: %d : %s \n", error, get_error_text(error));
        }
        else {
            printf("%d \n", d);
        }
    }

    veci_print(&vec);

    printf("Remove \n");

    for (int i = 0;i < 3;i++) {
        veci_remove_e(&vec, 1, &error);
    }

    veci_print(&vec);


    veci_pop_back_e(&vec, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_pop_back_e(&vec, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }
    veci_pop_back_e(&vec, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }

    // We expect an error here
    veci_pop_back_e(&vec, &error);
    if (error < 0) {
        printf("Error: %d : %s \n", error, get_error_text(error));
    }

    veci_print(&vec);

    veci_delete(&vec);

    return 0;
}
