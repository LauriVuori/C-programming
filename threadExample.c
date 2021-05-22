
// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>  //Header file for sleep(). man 3 sleep for details.
// #include <pthread.h>
  
// // A normal C function that is executed as a thread 
// // when its name is specified in pthread_create()
// void *myThreadFun(void *vargp)
// {
//     sleep(1);
//     printf("Printing GeeksQuiz from Thread \n");
//     return NULL;
// }
   
// int main()
// {
//     pthread_t thread_id;
//     printf("Before Thread\n");
//     pthread_create(&thread_id, NULL, myThreadFun, NULL);
//     pthread_join(thread_id, NULL);
//     printf("After Thread\n");
//     exit(0);
// }




// #include <stdio.h>
// #include <stdlib.h>
// #include <unistd.h>
// #include <pthread.h>
  
// // Let us create a global variable to change it in threads
// int g = 0;
  
// // The function to be executed by all threads
// void *myThreadFun(void *vargp)
// {
//     // Store the value argument passed to this thread
//     int *myid = (int *)vargp;
  
//     // Let us create a static variable to observe its changes
//     static int s = 0;
  
//     // Change static and global variables
//     ++s; ++g;
  
//     // Print the argument, static and global variables
//     printf("Thread ID: %d, Static: %d, Global: %d\n", *myid, ++s, ++g);
// }
  
// int main()
// {
//     int i;
//     pthread_t tid;
  
//     // Let us create three threads
//     for (i = 0; i < 3; i++)
//         pthread_create(&tid, NULL, myThreadFun, (void *)&tid);
  
//     pthread_exit(NULL);
//     return 0;
// }

#include <stdio.h>       /* standard I/O routines                 */
#include <pthread.h>     /* pthread functions and data structures */
#include <stdlib.h>
#include <time.h>
int g = 0;
int a = 0;
/* function to be executed by the new thread */
void* PrintHello(void* data) {
    int my_data = (int)data;     	/* data received by thread */

    // pthread_detach(pthread_self());
    while (1) {
        if (g == 0) {
            printf("Give num:\n");
            scanf("%d", &my_data);
            printf("NUMBER:<%d>\n", my_data);
            a = my_data;
            g = 1;
        }

    }
    pthread_exit(NULL);			/* terminate the thread */
}

void* Print(void* data) {


    // pthread_detach(pthread_self());
    while (1) {
        if (g == 1) {
            printf("PRINT:<%d>\n", a);
            g = 0;
        }
    }
    pthread_exit(NULL);			/* terminate the thread */
}

/* like any C program, program's execution begins in main */
int main(int argc, char* argv[])
{
    int        rc;         	/* return value                           */
    pthread_t  thread_id;     	/* thread's ID (just an integer)          */
    int        t         = 11;  /* data passed to the new thread          */

    /* create a new thread that will execute 'PrintHello' */
    rc = pthread_create(&thread_id, NULL, PrintHello, (void*)t);  
    rc = pthread_create(&thread_id, NULL, Print, (void*)t);  
    if(rc) {			/* could not create thread */
        printf("\n ERROR: return code from pthread_create is %d \n", rc);
        exit(1);
    }
    // printf("\n Created new thread (%u) ... \n", thread_id);
    
    pthread_exit(NULL);		/* terminate the thread */
}
