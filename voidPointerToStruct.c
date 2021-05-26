#include <stdio.h>       /* standard I/O routines                 */
#include <pthread.h>     /* pthread functions and data structures */
#include <stdlib.h>
#include <time.h>
int g = 0;
int a = 0;
typedef struct test{
    int a;
}test;

void* PrintHello(void* data);
    
int main(void) {
    test Terve;
    Terve.a = 5;
    pthread_t thread_id;
    int a = pthread_create(&thread_id, NULL, PrintHello, (void*)&Terve);
    sleep(2);
    printf("!!%d!!", Terve.a);
    pthread_exit(NULL);

}

void* PrintHello(void* data) {
    test * jou = (test*)data;     	/* data received by thread */

    // pthread_detach(pthread_self());
        printf("asd\n");
        printf("<%d>\n", jou->a);
        jou->a = 2500;
    pthread_exit(NULL);			/* terminate the thread */
}


