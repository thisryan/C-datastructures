#ifndef VECTOR_HEADER_H
// \cond
#define VECTOR_HEADER_H
// \endcond

#include <stdlib.h>

// \cond Ignore for Doxygen
#define VECTOR_IMPL(word) VECTOR_COMB1(VECTOR_PREFIX,word)
#define VECTOR_COMB1(pre, word) VECTOR_COMB2(pre, word)
#define VECTOR_COMB2(pre, word) pre##word
// \endcond

#endif

#ifndef VECTOR_T
#error "VECTOR_T must be defined"
#endif

#ifndef VECTOR_NAME
#define VECTOR_NAME VECTOR_COMB1(VECTOR_COMB1(vector,_), VECTOR_T)
#endif

#ifndef VECTOR_PREFIX
#define VECTOR_PREFIX VECTOR_COMB1(VECTOR_NAME, _)
#endif
typedef struct VECTOR_NAME VECTOR_NAME;
struct VECTOR_NAME {
    VECTOR_T* data;
    size_t index;
    size_t amount;
};

void VECTOR_IMPL(push_back)(VECTOR_NAME* v, VECTOR_T data);
void VECTOR_IMPL(insert)(VECTOR_NAME* v, VECTOR_T data, size_t index);
VECTOR_T VECTOR_IMPL(pop_back)(VECTOR_NAME* v);
VECTOR_T VECTOR_IMPL(remove)(VECTOR_NAME* v, size_t index);
