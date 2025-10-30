/****************************************************************************************************
 *
 * Name       : Aritra Sarkar, Anish Das, Dripta Patra
 * Roll No.   : 002311001048, 002311001009, 002311001006
 * Team No.   : 04
 * Group      : A1
 * Date       : 11-09-2025
 *
 * Assignment 6 : Parallel Programming using THREAD
 *
 * Details:
 *         The objective of this assignment is to use thread programming technique to
 *         write a parallel program which will do Matrix Multiplication between two
 *         large Square Matrices with unsigned character elements. You have to also
 *         measure the time elapsed. The Matrix should be large enough (at least
 *         3000 x 3000) and dynamically allocated to fit in your computer memory.
 *         Both the Matrices need to be initialized with random numbers (�mod� to
 *         some value).
 *         As you increase the number of threads(max to your number of CPUs), your
 *         timing should show improvement. Use �gettimeofday� to note down the
 *         timing. Make sure you attach the timing to the starting comment block of
 *         your source file. Your time should not include the Matrices initialization
 *         time.
 *         You have to use various �Pthread� library calls to do this assignment
 *         properly. Use the proper process listing command (ps) to show (and attach
 *         it to the starting comment block of your source file) that your threads are
 *         running in the system. Also, use proper command to show CPU
 *         utilization(cpustat or sar) and attach these outputs to the starting comment
 *         block of your source file.
 *         This program should take four command line arguments. The first
 *         argument is the dimension of the Square Matrix.
 *         The second argument is about the number of threads. For example, the
 *         value of the second argument will be 1, 2, 3, 4 etc.; signifying total no of
 *         threads which will be created.
 *         The third argument will be the value of the �mod� which will be used to
 *         initialize all the elements of two input square matrices.
 *         The fourth (last) argument will be the print_switch. If its value is �1�, both the
 *         Input and Output Matrices and as well as the Result Matrix will be printed
 *         on the screen. In case the value is �0�, Matrices won�t be printed on the
 *         screen.
 *
 * Compile:
 *     gcc -o A1_04_6 A1_06_c -std=c99 -lpthread
 *
 * Run:
 *     ./A1_04_6 <dim> <num of threads> <modulo  value> <switch flag>
 *
 * sample input :
 *     ./matrix_mul 3000 4 100 0
 *
 * sample output:
 *              [be2348@localhost assign6]$ gcc -o A1_04_6 A1_04_6.c -std=c99 -lpthread
 *              [be2348@localhost assign6]$ ./A1_04_6 3000 8 100 0
 *
 *              Matrix multiplication using 8 threads completed in 36.202 s
 *
 *              --- System Info ---
 *              Process ID: 15906
 *
 *              [Thread Info: ps -L]
 *                PID   TID %CPU STAT COMMAND
 *              15906 15906  705 S+   A1_04_6
 *
 *              [CPU Utilization: mpstat]
 *              Linux 3.10.0-514.21.1.el7.x86_64 (localhost.localdomain)        Thursday 11 September 2025      _x86_64_        (16 CPU)
 *
 *              01:55:50  IST  CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
 *              01:55:51  IST  all    1.69    0.00    4.69    0.00    0.00    0.00    0.00    0.00    0.00   93.62
 *              01:55:51  IST    0    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST    1    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST    2    1.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   99.00
 *              01:55:51  IST    3    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST    4    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST    5    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST    6    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST    7   26.00    0.00   74.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
 *              01:55:51  IST    8    0.00    0.00    1.00    0.00    0.00    0.00    0.00    0.00    0.00   99.00
 *              01:55:51  IST    9    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST   10    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST   11    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST   12    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST   13    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST   14    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              01:55:51  IST   15    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *
 *              Average:     CPU    %usr   %nice    %sys %iowait    %irq   %soft  %steal  %guest  %gnice   %idle
 *              Average:     all    1.69    0.00    4.69    0.00    0.00    0.00    0.00    0.00    0.00   93.62
 *              Average:       0    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:       1    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:       2    1.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00   99.00
 *              Average:       3    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:       4    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:       5    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:       6    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:       7   26.00    0.00   74.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00
 *              Average:       8    0.00    0.00    1.00    0.00    0.00    0.00    0.00    0.00    0.00   99.00
 *              Average:       9    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:      10    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:      11    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:      12    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:      13    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:      14    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *              Average:      15    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00    0.00  100.00
 *
 *              [CPU Utilization: sar]
 *              Linux 3.10.0-514.21.1.el7.x86_64 (localhost.localdomain)        Thursday 11 September 2025      _x86_64_        (16 CPU)
 *
 *              01:55:51  IST     CPU     %user     %nice   %system   %iowait    %steal     %idle
 *              01:55:52  IST     all      1.88      0.00      4.50      0.00      0.00     93.62
 *              Average:        all      1.88      0.00      4.50      0.00      0.00     93.62
 *
 ********************************************************************************************************************************/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <sys/time.h>
#include <unistd.h>

char **A, **B, **C;
int N;
int num;

typedef struct
{
    int id;
    int start; // starting row idx
    int end;   // Ending row idx
} ThreadData;

// Allocate the memory for the 2D matrix
char **allocate_matrix(int n)
{
    char **mat = (char **)malloc(n * sizeof(char *));
    if (!mat)
    {
        perror("malloc failed");
        exit(EXIT_FAILURE);
    }
    for (int i = 0; i < n; i++)
    {
        mat[i] = (char *)malloc(n * sizeof(char));
        if (!mat[i])
        {
            perror("malloc failed");
            exit(EXIT_FAILURE);
        }
    }
    return mat;
}

// Fill the matrix with random numbers
void init_mat(char **mat, int n, int mod)
{
    for (int i = 0; i < n; i++)
        for (int j = 0; j < n; j++)
            mat[i][j] = rand() % mod;
}

// Print the matrix
void print_mat(char **mat, int n, char *name)
{
    printf("\nMatrix %s:\n", name);
    for (int i = 0; i < n; i++)
    {
        for (int j = 0; j < n; j++)
            printf("%3u ", mat[i][j]);
        printf("\n");
    }
}

// Do the matrix multiplication
void *mult(void *arg)
{
    ThreadData *data = (ThreadData *)arg;
    int id = data->id;
    int start = data->start;
    int end = data->end;

    for (int i = start; i < end; i++)
    {
        for (int j = 0; j < N; j++)
        {
            int sum = 0;
            for (int k = 0; k < N; k++)
            {
                sum += A[i][k] * B[k][j];
            }
            C[i][j] = (char)(sum % 256);
        }
    }
    pthread_exit(NULL);
}

int main(int argc, char *argv[])
{
    if (argc != 5)
    {
        fprintf(stderr, "Usage: %s <dim> <num of threads> <mod val> <print switch>\n", argv[0]);
        exit(EXIT_FAILURE);
    }

    N = atoi(argv[1]);        // Matrix dimension
    num = atoi(argv[2]);      // No of threads
    int mod = atoi(argv[3]);  // mod value for the matrix elements
    int flag = atoi(argv[4]); // print or not-print

    if (N <= 0 || num <= 0 || mod <= 0)
    {
        fprintf(stderr, "Error: Invalid arguments\n");
        exit(EXIT_FAILURE);
    }

    srand(time(NULL)); // To get random values on using rand() everytime wrt time else we will get the same matrix every time

    /*
      -> srand(time(NULL)); sets the seed for the random number generator.
      -> time(NULL) returns the current system time in seconds, which changes every second.
    */

    A = allocate_matrix(N);
    B = allocate_matrix(N);
    C = allocate_matrix(N);

    init_mat(A, N, mod);
    init_mat(B, N, mod);

    if (flag == 1)
    {
        print_mat(A, N, "A");
        print_mat(B, N, "B");
    }

    struct timeval start, end; // timeval is an inbuilt structure
    gettimeofday(&start, NULL);

    pthread_t threads[num]; // array if threads(only declaration)
    ThreadData data[num];   // array of ThreadData structure

    int row = N / num;
    int rem = N % num;
    int curr = 0;

    for (int t = 0; t < num; t++)
    {
        int extra = (t < rem) ? 1 : 0;
        data[t].id = t;
        data[t].start = curr;
        data[t].end = curr + row + extra;
        curr = data[t].end;

        if (pthread_create(&threads[t], NULL, mult, &data[t]) != 0)
        { // Thread creation and matrix multiplication in parallel
            perror("pthread_create failed");
            exit(EXIT_FAILURE);
        }

        /*
            -> Creates a new thread.
            -> Starts running the function mult() in parallel.
            -> Passes a pointer to data[t], which tells the thread which rows to handle.
        */
    }

    for (int t = 0; t < num; t++)
    {
        pthread_join(threads[t], NULL); // The main thread waits until all worker threads have completed their work.
    }

    gettimeofday(&end, NULL);
    double elapsed_s = (end.tv_sec - start.tv_sec) + (end.tv_usec - start.tv_usec) / 1000000.0;

    printf("\nMatrix multiplication using %d threads completed in %.3f s \n", elapsed_s, num);

    if (flag == 1)
    {
        print_mat(C, N, "C (Result)");
    }

    printf("\n--- System Info ---\n");

    printf("Process ID: %d\n", getpid());

    char cmd[128];
    snprintf(cmd, sizeof(cmd), "ps -L -p %d -o pid,tid,pcpu,stat,comm", getpid());
    printf("\n[Thread Info: ps -L]\n");
    system(cmd);

    printf("\n[CPU Utilization: mpstat]\n");
    system("mpstat -P ALL 1 1");

    printf("\n[CPU Utilization: sar]\n");
    system("sar -u 1 1");

    return 0;
}
