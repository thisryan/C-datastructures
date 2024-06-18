/**
 * @file

 * @author  Adrian O
 * @brief
 * @version 1
 * @date 2024-06-18
 *
 * @copyright Copyright (c) 2024
 */

 // This block only exists for better documentation
#ifdef _DOXYGEN_

/**
 * @brief The exported Vector type
 *
 */
typedef struct VECTOR_NAME {
    /**
     * @brief The items
     *
     */
    VECTOR_T* data;

    /**
     * @brief The index behind the last written element
     *
     */
    size_t index;

    /**
     * @brief The size of the data buffer
     *
     */
    size_t size;
} VECTOR_NAME;

/**
 * @brief Inserts element at the end of the vector
 *
 * @param v Pointer to the vector
 * @param data element to be added
 */
void VECTOR_PREFIX_push_back(VECTOR_NAME* v, VECTOR_T data);

/**
 * @brief Insert element at specific index
 *
 * @param v Pointer to the vector
 * @param data element to be added
 * @param index the index of the insertion
 */
void VECTOR_PREFIX_insert(VECTOR_NAME* v, VECTOR_T data, size_t index);

/**
 * @brief Remove element from the end of the vector
 *
 * @param v Pointer to the vector
 * @return VECTOR_T The removed element
 */
VECTOR_T VECTOR_PREFIX_pop_back(VECTOR_NAME* v);

/**
 * @brief Remove element from specified index
 *
 * @param v Pointer to the vector
 * @param index the index of the deletion
 * @return VECTOR_T the removed element
 */
VECTOR_T VECTOR_PREFIX_remove(VECTOR_NAME* v, size_t index);


/**
 * @brief This is the type which is stored inside the vector. This must be defined
 *
 */
#define VECTOR_T

 /**
  * @brief The name of the created Vector Type. If not defined the name will be vector_VECTOR_T
  *
  */
#define VECTOR_NAME

  /**
   * @brief The Prefix every function which operates on the vector has. If not defined the Prefix will be VECTOR_NAME
   *
   */
#define VECTOR_PREFIX

   /**
    * @brief If defined there are two sets of functions, one with errors post fixed by _e and one without errors
    *
    */
#define ERROR

    /**
     * @brief If defined the only defined functions are the error functions
     *
     */
#define SAFE

     /**
      * @brief If set the functions are implemented
      *
      */
#define IMPLEMENT
#endif

#ifndef VECTOR_HEADER_H
// \cond
#define VECTOR_HEADER_H
// \endcond

#include <stdlib.h>

// \cond Ignore for Doxygen
#define VECTOR_IMPL(word) VECTOR_COMB1(VECTOR_PREFIX,word)
#define VECTOR_COMB1(pre, word) VECTOR_COMB2(pre, word)
#define VECTOR_COMB2(pre, word) pre##word
#define NULL_VALUE (VECTOR_T) { 0 };
// \endcond

/**
 * @brief Error if the vector argument is NULL
 *
 */
#define VERR_NULLPOINTER -1

 /**
  * @brief Error if out of memory
  *
  */
#define VERR_OUTOFMEMORY -2

  /**
   * @brief Error if index is out of bounds
   *
   */
#define VERR_OUTOFBOUNDS -3

   /**
    * @brief Get the error text object
    *
    * @param error the error which occured
    * @return char* the error text
    */
char* get_error_text(int error) {
    switch (error) {
    case VERR_NULLPOINTER:
        return "Input vector was NULL";
    case VERR_OUTOFBOUNDS:
        return "Index was out of bounds";
    case VERR_OUTOFMEMORY:
        return "out of memory";
    }
}

#endif

// \cond
#ifndef VECTOR_T
#error "VECTOR_T must be defined"
#endif

#ifndef VECTOR_NAME
#define VECTOR_NAME VECTOR_COMB1(VECTOR_COMB1(vector,_), VECTOR_T)
#endif

#ifndef VECTOR_PREFIX
#define VECTOR_PREFIX VECTOR_COMB1(VECTOR_NAME, _)
#endif
// \endcond

// \cond
typedef struct VECTOR_NAME VECTOR_NAME;
struct VECTOR_NAME {
    VECTOR_T* data;
    size_t index;
    size_t amount;
};

size_t VECTOR_IMPL(size)(VECTOR_NAME* v);
void VECTOR_IMPL(delete)(VECTOR_NAME* v);

#if defined(SAFE) || defined(ERROR)

void VECTOR_IMPL(push_back_e) (VECTOR_NAME* v, VECTOR_T data, int* error);
void VECTOR_IMPL(insert_e)(VECTOR_NAME* v, VECTOR_T data, size_t index, int* error);
VECTOR_T VECTOR_IMPL(pop_back_e)(VECTOR_NAME* v, int* error);
VECTOR_T VECTOR_IMPL(remove_e)(VECTOR_NAME* v, size_t index, int* error);
VECTOR_T VECTOR_IMPL(get_e)(VECTOR_NAME* v, size_t index, int* error);

#endif

#ifndef SAFE

void VECTOR_IMPL(push_back)(VECTOR_NAME* v, VECTOR_T data);
void VECTOR_IMPL(insert)(VECTOR_NAME* v, VECTOR_T data, size_t index);
VECTOR_T VECTOR_IMPL(pop_back)(VECTOR_NAME* v);
VECTOR_T VECTOR_IMPL(remove)(VECTOR_NAME* v, size_t index);

#endif

#ifdef IMPLEMENT

size_t VECTOR_IMPL(size)(VECTOR_NAME* v) {
    return v->index;
}

void VECTOR_IMPL(delete)(VECTOR_NAME* v) {
    free(v->data);
    v->amount = 0;
    v->index = 0;
}

#if defined(SAFE) || defined(ERROR)

void VECTOR_IMPL(push_back_e) (VECTOR_NAME* v, VECTOR_T data, int* error) {
    if (error != NULL) *error = 0;

    if (v == NULL) {
        if (error != NULL) *error = VERR_NULLPOINTER;
        return;
    }

    if (v->index >= v->amount) {
        v->amount = v->amount ? v->amount * 2 : 1;
        v->data = realloc(v->data, v->amount * sizeof(VECTOR_T));

        if (v->data == NULL) {
            if (error != NULL) *error = VERR_OUTOFMEMORY;
            return;
        }
    }

    v->data[v->index++] = data;
}

void VECTOR_IMPL(insert_e)(VECTOR_NAME* v, VECTOR_T data, size_t index, int* error) {
    if (error != NULL) *error = 0;
    if (v == NULL) {
        if (error != NULL) *error = VERR_NULLPOINTER;
        return;
    }

    if (v->index >= v->amount) {
        v->amount = v->amount ? v->amount * 2 : 1;
        v->data = realloc(v->data, v->amount * sizeof(VECTOR_T));

        if (v->data == NULL) {
            if (error != NULL) *error = VERR_OUTOFMEMORY;
            return;
        }
    }

    if (index > v->index || index < 0) {
        if (error != NULL) *error = VERR_OUTOFBOUNDS;
        return;
    }

    for (size_t i = v->index;i > index;i--) {
        v->data[i] = v->data[i - 1];
    }

    v->data[index] = data;
    v->index++;
}

VECTOR_T VECTOR_IMPL(pop_back_e)(VECTOR_NAME* v, int* error) {
    if (error != NULL) *error = 0;

    if (v == NULL) {
        if (error != NULL) *error = VERR_NULLPOINTER;
        return NULL_VALUE;
    }

    if (v->index == 0) {
        if (error != NULL) *error = VERR_OUTOFBOUNDS;
        return NULL_VALUE;
    }

    return v->data[--v->index];
}

VECTOR_T VECTOR_IMPL(remove_e)(VECTOR_NAME* v, size_t index, int* error) {
    if (error != NULL) *error = 0;

    if (v == NULL) {
        if (error != NULL) *error = VERR_NULLPOINTER;
        return NULL_VALUE;
    }

    if (index < 0 || index >= v->index) {
        if (error != NULL) *error = VERR_OUTOFBOUNDS;
        return NULL_VALUE;
    }

    VECTOR_T store = v->data[index];
    for (size_t i = index;i < v->index - 1;i++) {
        v->data[i] = v->data[i + 1];
    }
    v->index--;

    return store;
}

VECTOR_T VECTOR_IMPL(get_e)(VECTOR_NAME* v, size_t index, int* error) {
    if (error != NULL) *error = 0;

    if (v == NULL) {
        if (error != NULL) *error = VERR_NULLPOINTER;
        return NULL_VALUE;
    }

    if (index < 0 || index >= v->index) {
        if (error != NULL) *error = VERR_OUTOFBOUNDS;
    }

    return v->data[index];
}

#endif

#ifndef SAFE 
void VECTOR_IMPL(push_back)(VECTOR_NAME* v, VECTOR_T data) {
    if (v->index >= v->amount) {
        v->amount = v->amount ? v->amount * 2 : 1;
        v->data = realloc(v->data, v->amount * sizeof(VECTOR_T));
    }

    v->data[v->index++] = data;
}

void VECTOR_IMPL(insert)(VECTOR_NAME* v, VECTOR_T data, size_t index) {
    if (v->index >= v->amount) {
        v->amount = v->amount ? v->amount * 2 : 1;
        v->data = realloc(v->data, v->amount * sizeof(VECTOR_T));
    }

    if (index > v->index || index < 0) {
        return;
    }

    for (size_t i = v->index;i > index;i--) {
        v->data[i] = v->data[i-1];
    }

    v->data[index] = data;
    v->index++;
}

VECTOR_T VECTOR_IMPL(pop_back)(VECTOR_NAME* v) {
    if (v->index == 0) {
        return (VECTOR_T) { 0 };
    }

    return v->data[--v->index];
}

VECTOR_T VECTOR_IMPL(remove)(VECTOR_NAME* v, size_t index) {
    if (index < 0 || index >= v->index) {
        return (VECTOR_T) { 0 };
    }

    VECTOR_T store = v->data[index];
    for (size_t i = index;i < v->index - 1;i++) {
        v->data[i] = v->data[i + 1];
    }
    v->index--;

    return store;
}

#endif
#endif

#undef VECTOR_T
#undef VECTOR_PREFIX
#undef VECTOR_NAME
#undef VECTOR_push_back
#undef VECTOR_insert
#undef VECTOR_pop_back
#undef VECTOR_remove
#undef IMPLEMENT
#undef SAFE

// \endcond