/* $begin sharing */
#include "csapp.h"
#include "csapp.c"
#define N 2
void *thread(void *vargp);

char **ptr;  /* global variable */ //line:conc:sharing:ptrdec

int main() 
{
    long int i;  
    pthread_t tid;
    char *msgs[N] = {
	    "Hello from foo",  
	    "Hello from bar"   
    };

    ptr = msgs; 
    for (i = 0; i < N; i++)  
        Pthread_create(&tid, NULL, thread, (void *)i); 
    Pthread_exit(NULL); 
}

void *thread(void *vargp) 
{
    long int myid = (long int)vargp;
    static int cnt = 0; //line:conc:sharing:cntdec
    printf("[%ld]: %s (cnt=%d)\n", myid, ptr[myid], ++cnt); //line:conc:sharing:stack
    return NULL;
}
/* $end sharing */