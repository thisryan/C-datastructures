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
