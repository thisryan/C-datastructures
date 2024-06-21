#include "testing/tests.h"

#include <stdio.h>

// TODO: There is still memory leaks in this test system

void add_test(TestModule* m, TestFunction test, char* name) {
    if(m->index == m->amount){
        m->amount = m->amount == 0 ? 1 : m->amount * 2;
        m->functions = realloc(m->functions, m->amount * sizeof(TestFunction));
        m->names = realloc(m->names, m->amount * sizeof(char*));
    }

    m->functions[m->index] = test;
    m->names[m->index] = name;
    m->index++;
}


void run_module(TestModule* m) {
    int passed = 0;
    int failed = 0;

    for(int i = 0;i < m->index;i++){
        printf("%s: ", m->names[i]);
        TestResult result = {.error = false, .message = NULL};
        m->functions[i](&result);
        if(result.error) {
            printf("\033[31mFailed\033[0m\n%s\n", result.message);
            failed++;
            break;
        }
        passed++;
        printf("\033[32mPassed\033[0m\n");
    }

    if(passed != 0)printf("\033[32m%d Tests Passed\033[0m\n", passed);
    if(failed != 0)printf("\033[31m%d Tests Failed\033[0m\n", failed);
}
