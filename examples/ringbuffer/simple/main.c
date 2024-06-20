#include <stdio.h>

#define RINGBUFFER_T int
#define RINGBUFFER_NAME IntDequeue
#define RINGBUFFER_PREFIX dqi_
#define IMPLEMENT
#include <ds/ringbuffer.h>

int main(int argc, char const *argv[])
{
    
    IntDequeue q = { 0 };
    q.amount = 13;
    q.data = malloc(q.amount * sizeof(int));

    dqi_push_back(&q, 10);
    dqi_push_back(&q, 11);
    dqi_push_back(&q, 12);
    dqi_push_back(&q, 13);
    dqi_push_back(&q, 14);
    dqi_push_back(&q, 15);
    dqi_push_back(&q, 16);

    for(int i = 0;i < 3;i++){
        int n = dqi_pop_front(&q);
        printf("%d \n", n);
    }


    dqi_push_front(&q, 1);
    dqi_push_front(&q, 2);
    dqi_push_front(&q, 3);
    dqi_push_back(&q, 17);
    dqi_push_back(&q, 18);
    dqi_push_back(&q, 19);
    dqi_push_back(&q, 20);

    for(int i = 0;i < 5;i++){
        int n = dqi_pop_front(&q);
        printf("%d \n", n);
    }

    for(int i = 0;i < 6;i++){
        int n = dqi_pop_back(&q);
        printf("%d \n", n);
    }


    printf("%d \n", dqi_pop_back(&q));
    printf("%d \n", dqi_pop_front(&q));

    printf("Second \n");

    IntDequeue q2 = { 0 };
    dqi_push_back(&q2, 10);
    dqi_push_back(&q2, 20);
    dqi_push_back(&q2, 30);
    dqi_push_back(&q2, 40);
    dqi_push_back(&q2, 50);

    printf("%d \n", dqi_front(&q2));
    return 0;
}
