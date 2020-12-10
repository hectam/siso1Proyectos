#include <pthread.h>
#include <stdio.h>
#define NUM THREADS 5
int main(int argc, char *argv[])
{
int i, policy;
pthread t tid[NUM THREADS];
pthread attr t attr;
/* get the default attributes */
pthread attr init(&attr);
/* get the current scheduling policy */
if (pthread attr getschedpolicy(&attr, &policy) != 0)
fprintf(stderr, "Unable to get policy.\n");
else {
if (policy == SCHED OTHER)
printf("SCHED OTHER\n");
else if (policy == SCHED RR)
printf("SCHED RR\n");
else if (policy == SCHED FIFO)
printf("SCHED FIFO\n");
}
/* set the scheduling policy - FIFO, RR, or OTHER */
if (pthread attr setschedpolicy(&attr, SCHED FIFO) != 0)
fprintf(stderr, "Unable to set policy.\n");
/* create the threads */
for (i = 0; i < NUM THREADS; i++)
pthread create(&tid[i],&attr,runner,NULL);
/* now join on each thread */
for (i = 0; i < NUM THREADS; i++)
pthread join(tid[i], NULL);
}
/* Each thread will begin control in this function */
void *runner(void *param)
{
/* do some work ... */
pthread exit(0);
}