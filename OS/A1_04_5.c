/****************************************************************************************************
 *
 * Name       : Aritra Sarkar, Anish Das, Dripta Patra
 * Roll No.   : 002311001048, 002311001009, 002311001006
 * Team No.   : 04
 * Group      : A1
 * Date       : 04-09-2025
 * Details:
 *         Consider a main process which creates three threads Th1, Th2, and Th3. The main
 *         process also creates two random quantities (X, Y), both less than 10. These two
 *         values will be placed by the main process in the shared memory (One variant of IPC
 *         Primitive) that is accessible by all the three threads Th1, Th2 and Th3. The shared
 *         memory will be created by the main process using shmat/shmget calls.
 *         For each pair of values (X,Y), it is required that some computations should be done
 *         by various threads. The thread Th1 will compute A (X*Y), the thread Th2 will
 *         compute B (2*X+2*Y+1) and Th3 computes C (B/A). All these values are kept in the
 *         shared memory in a tabular fashion as shown below.
 *         The number of (X,Y) pairs will be taken as an argument from the CLI. It is the
 *         responsibility of the main process to populate required numbers of (X,Y)s in the
 *         shared memory. The program will only exit when all A,B,C are computed for all given
 *         (X,Y) values. Before exiting, all (X,Y)s, As, Bs and Cs should be displayed as per the
 *         format shown below.
 *         Whenever, the threads complete one phase of computations (A, B and C), they will
 *         go for another pair of (X,Y) values; but they will start all together. This can be
 *         achieved by proper synchronization.
 *         Use the proper shell command(ipcs or simmilar) to display the Shared Memory
 *         Status/Info/Statistics and attach this sample output as a part of the starting comment
 *         block. This statistics should show the Shared Memory which your program has
 *         created.
 * compile commands:
 *         gcc --std=c99  A1_04_5.c -o A1_04_5 -lpthread -lm
 * execution command :
 *         ./A_04_5 <No of pairs>
 * sample output:
 *            [be2348@localhost assign5]$ ./A1_04_5 10
 *
 *            ------ Shared Memory Segments --------
 *            key        shmid      owner      perms      bytes      nattch     status
 *            0x00000072 65536      be2342     444        1          0
 *            0xffffffff 1474561    be2348     666        2536       0
 *
 *            Pairs(X,Y) | A      | B      | C
 *            -------------------------------------
 *            ( 1, 6)   | 6      | 15     | 2.50
 *            ( 2, 0)   | 0      | 5      | 0.00
 *            ( 0, 3)   | 0      | 7      | 0.00
 *            ( 9, 4)   | 36     | 27     | 0.75
 *            ( 5, 1)   | 5      | 13     | 2.60
 *            ( 9, 1)   | 9      | 21     | 2.33
 *            ( 3, 2)   | 6      | 11     | 1.83
 *            ( 3, 7)   | 21     | 21     | 1.00
 *            ( 8, 8)   | 64     | 33     | 0.52
 *            ( 1, 1)   | 1      | 5      | 5.00
 *
 *            ------ Shared Memory Segments --------
 *            key        shmid      owner      perms      bytes      nattch     status
 *            0x00000072 65536      be2342     444        1          0
 *            0xffffffff 1474561    be2348     666        2536       1
 *
 ********************************************************************************************/

#define _XOPEN_SOURCE 700
#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include <sys/types.h>
#include <semaphore.h>
#include <time.h>
#include <unistd.h>

#define MAX_PAIRS 50

typedef struct
{
    int N;
    int idx;
    int x[MAX_PAIRS];
    int y[MAX_PAIRS];
    int A[MAX_PAIRS];
    int B[MAX_PAIRS];
    double C[MAX_PAIRS];
    sem_t th_main, Th1, Th2, Th3; // counting semaphores for each threads
} SData;

SData *ptr;

// Thread 1: Compute A = X * Y
void *thread1(void *arg)
{
    while (1)
    {
        sem_wait(&ptr->Th1);
        int i = ptr->idx;
        if (i >= ptr->N)
            break;
        ptr->A[i] = ptr->x[i] * ptr->y[i];
        sem_post(&ptr->th_main);
    }
    return NULL;
}

// Thread 2: Compute B = 2*X + 2*Y + 1
void *thread2(void *arg)
{
    while (1)
    {
        sem_wait(&ptr->Th2);
        int i = ptr->idx;
        if (i >= ptr->N)
            break;
        ptr->B[i] = (2 * ptr->x[i]) + (2 * ptr->y[i]) + 1;
        sem_post(&ptr->th_main);
    }
    return NULL;
}

// Thread 3: Compute C = B / A
void *thread3(void *arg)
{
    while (1)
    {
        sem_wait(&ptr->Th3);
        int i = ptr->idx;
        if (i >= ptr->N)
            break;
        if (ptr->A[i] != 0)
            ptr->C[i] = (double)ptr->B[i] / ptr->A[i];
        else
            ptr->C[i] = 0.0; // avoid division by zero
        sem_post(&ptr->th_main);
    }
    return NULL;
}

// The main function
int main(int argc, char *argv[])
{
    if (argc != 2)
    {
        printf("Usage: %s N\n", argv[0]);
        return 1;
    }

    system("ipcs -m");

    int N = atoi(argv[1]);

    if (N > MAX_PAIRS)
    {
        printf("Max %d pairs allowed\n", MAX_PAIRS);
        return 1;
    }

    // Shared memory setup
    key_t key = ftok("shmfile", 65);
    int shmid = shmget(key, sizeof(SData), 0666 | IPC_CREAT);
    ptr = (SData *)shmat(shmid, NULL, 0);
    /*
        1.ftok() — maps a pathname + small id → a numeric key_t.
        2.shmget(key, size, flags) — ask kernel for a shared memory segment with that key and size; returns shmid.
        3.shmat(shmid, addr, flags) — map the segment into your process address space and return a pointer you can use like normal memory.
    */
    ptr->N = N;
    ptr->idx = 0;

    // Init semaphores
    sem_init(&ptr->th_main, 1, 0);
    sem_init(&ptr->Th1, 1, 0);
    sem_init(&ptr->Th2, 1, 0);
    sem_init(&ptr->Th3, 1, 0);
    /*
        1. Initializes all semaphores with value 0.
        2. The second argument 1 means “shared between processes”.
    */

    // Generate random (X,Y) pairs
    srand(time(NULL));
    for (int i = 0; i < N; i++)
    {
        ptr->x[i] = rand() % 10; // random
        ptr->y[i] = rand() % 10; // random
    }

    pthread_t th1, th2, th3;
    pthread_create(&th1, NULL, thread1, NULL);
    pthread_create(&th2, NULL, thread2, NULL);
    pthread_create(&th3, NULL, thread3, NULL);

    // Drive the computation
    for (int i = 0; i < N; i++)
    {
        ptr->idx = i;
        // wake up all 3 threads
        sem_post(&ptr->Th1);
        sem_post(&ptr->Th2);
        sem_post(&ptr->Th3);
        // wait for all 3 to finish
        sem_wait(&ptr->th_main);
        sem_wait(&ptr->th_main);
        sem_wait(&ptr->th_main);
    }

    // Print in table format
    printf("%-10s | %-6s | %-6s | %-6s\n", "Pairs(X,Y)", "A", "B", "C");
    printf("-------------------------------------\n");
    for (int i = 0; i < N; i++)
    {
        printf("(%2d,%2d)   | %-6d | %-6d | %-6.2f\n",
               ptr->x[i], ptr->y[i],
               ptr->A[i], ptr->B[i], ptr->C[i]);
    }

    system("ipcs -m");
    return 0;
}
