
/*
Testing suite
- define test
- assertions
*/

#include <stdbool.h>
#include <stdlib.h>
#include <stdio.h>

//TODO: add simple functionality for quickly constructing error messages out of context data

#define COMB1(pre, word) COMB2(pre, word)
#define COMB2(pre, word) pre##word

typedef struct TestResult TestResult;
struct TestResult {
    bool error;
    char* message;
};

typedef void (*TestFunction)(TestResult* result);

typedef struct TestModule TestModule;
struct TestModule {
    TestFunction* functions;
    char** names;
    size_t index;
    size_t amount;
};

#define Test(name) void name(TestResult *result)

void add_test(TestModule* m, TestFunction test, char* name);
void run_module(TestModule* m);

#define IASSERT_EQUAL(expected, actual, msg) \
int COMB1(n1,__LINE__) = expected; \
int COMB1(n2,__LINE__) = actual; \
if(COMB1(n1,__LINE__) != COMB1(n2,__LINE__)) { \
    char* format = "    Assert error: Expected %d: Actual %d\n    %s"; \
    int amount = snprintf(NULL, 0, format, COMB1(n1,__LINE__), COMB1(n2,__LINE__), msg) + 1;\
    result->message = malloc(amount * sizeof(char)); \
    snprintf(result->message, amount, format, COMB1(n1,__LINE__), COMB1(n2,__LINE__), msg); \
    result->error = true; \
    return; \
} 

