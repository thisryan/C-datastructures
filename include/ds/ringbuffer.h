#ifndef VECTOR_HEADER_H

#include <stdlib.h>

#define RINGBUFFER_IMPL(word) RINGBUFFER_COMB1(RINGBUFFER_PREFIX, word)
#define RINGBUFFER_COMB1(pre, word) RINGBUFFER_COMB2(pre, word)
#define RINGBUFFER_COMB2(pre, word) pre##word
#define RINGBUFFER_NULL_VALUE (RINGBUFFER_T) { 0 };

#endif

#ifndef RINGBUFFER_T
#error "RINGBUFFER_T must be defined"
#endif

#ifndef RINGBUFFER_NAME
#define RINBUFFER_NAME RINGBUFFER_COMB1(RINGBUFFER_COMB1(ringbuffer,_), RINGBUFFER_T)
#endif

#ifndef RINGBUFFER_PREFIX
#define RINGBUFFER_PREFIX RINGBUFFER_COMB1(RINGBUFFER_NAME, _)
#endif
