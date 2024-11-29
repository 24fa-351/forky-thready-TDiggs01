#include <stdio.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <sys/types.h>

#define MAX_COUNT   200
#define BUF_SIZE    100
char buf[BUF_SIZE];
int yi = 0;
int zi = 0;
int stop = 0;

struct thread_args {
    pthread_t tid;
    int p_number;
    FILE *fpt;
};


void* myThreadFun(void* _args) {

    struct thread_args *args = (struct thread_args *) _args;
    int process_number = args->p_number;
    int temp = args->p_number;
    process_number++;

    fprintf(args->fpt, "Process %d ( %ld ) begining \n", args->p_number, args->tid);
    //write(1, buf, strlen(buf));
    sleep(1);

    if(process_number != stop) {
        fprintf(args->fpt, "Process %d ( %ld ) creating Process %d \n", temp, args->tid, process_number );
        //write(1, buf, strlen(buf));
    }
    sleep(2);
    fprintf(args->fpt, "Process %d ( %ld ) exiting\n", temp, args->tid);
    //write(1, buf, strlen(buf));
    sleep(1);

    return NULL;
}


int main ( int argc, char *argv[] ) {

    struct thread_args *args = malloc (sizeof (struct thread_args));
    args->fpt = fopen("results.txt", "w+");
    args->tid = getpid();
    stop = atoi(argv[2]);

    if ( argv[1] <= 0 ) {
        printf("There is nothing.");
        return 0;
    }
    if ( atoi(argv[2]) < 1 && atoi(argv[2]) > 256 ) {
        printf( "There has to be a number between 1 and 256." );
        return 0;
    }
    if ( argv[3] == NULL ) {
        printf( "There is no pattern." );
        return 0;
    }
    else if ( atoi(argv[3]) == 1  ) {
     
        sprintf(buf, "%ld Pattern 3 begining \n", args->tid);
        write(1, buf, strlen(buf));
        for(int xi = 0; xi < atoi(argv[2]); xi++) {
            fork();
        }
        
        args->p_number = zi;
        pthread_create(&args->tid, NULL, myThreadFun, args);
        zi++;
        sleep(3);
    
        pthread_join(args->tid, NULL);
        pthread_exit(NULL);
    }
    else if( atoi(argv[3]) == 2  ) {
        sprintf(buf, "%ld Pattern 2 begining", args->tid);
        write(1, buf, strlen(buf));

        for(int xi = 0; xi < atoi(argv[2]); xi++) {
            myThreadFun(args);
        }

    }
    else if( atoi(argv[3]) == 3  ) {

    // Creating threads 
    for(int xi = 0; xi < atoi(argv[2]); xi++) {
        args->p_number = yi;
        pthread_create(&args->tid, NULL, myThreadFun, args);
        yi++;
        sleep(3);
    }
    pthread_join(args->tid, NULL);
    pthread_exit(NULL);

    }
    fclose(args->fpt);

    return 0;
}
