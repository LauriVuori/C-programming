#include <signal.h>
#include <stdio.h>
#include <string.h>
#include <sys/time.h>

void task1(void);
void task2(void);
void task3(void);

void timer_ISR (int signum);
void timer_init(void);

int main () {

    timer_init();
    /* Do busy work. */
    while (1){
    }
} 

void timer_init(void)
{

struct sigaction sa;
struct itimerval timer; 

/* Install timer_handler as the signal handler for SIGVTALRM. */
memset (&sa, 0, sizeof (sa));
sa.sa_handler = &timer_ISR;
sigaction (SIGVTALRM, &sa, NULL);

/* Configure the timer to expire after 250 msec... */
timer.it_value.tv_sec = 0;
timer.it_value.tv_usec = 10000;
/* ... and every 250 msec after that. */
timer.it_interval.tv_sec = 0;
timer.it_interval.tv_usec =10000;
/* Start a virtual timer. It counts down whenever this process is
executing. */
setitimer (ITIMER_VIRTUAL, &timer, NULL);

}


void timer_ISR (int signum) {
    static int count = 0, t1 = 600, t2 = 350, t3 = 250;
    void (*ptr1)() = &task1;
    void (*ptr2)() = &task2;
    void (*ptr3)() = &task3;
    printf ("%5d(%4d %4d %4d):", count, t1, t2, t3);
    count += 10;
    t1 -= 10;
    t2 -= 10;
    t3 -= 10;
    if (t1 == 0) {
        ptr1();
        t1 = 600;
    }
    if (t2 == 0) {
        ptr2();
        t2 = 350;
    }
    if (t3 == 0) {
        ptr3();
        t3 = 250;
    }
    printf("\n");
}

void task1 (void){
    printf(" task1");
}
void task2 (void){
    printf(" task2");
}
void task3 (void){
    printf(" task3");
}