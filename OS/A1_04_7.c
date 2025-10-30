/*
Avoiding Deadlock with 3 Totals and 4 Threads
---------------------------------------------

DEADLOCK AVOIDANCE STRATEGY:
Always lock mutexes in a consistent global order: m1 -> m2 -> m3
This prevents circular wait conditions that cause deadlocks.

DEADLOCK CREATION:
To CREATE deadlock, threads could lock mutexes in different orders:
- Thread 1: lock m1, then m2
- Thread 2: lock m2, then m1
- This creates circular wait: T1 waits for m2 (held by T2), T2 waits for m1 (held by T1)

ASSIGNMENT REQUIREMENTS:
- Total_1, Total_2, Total_3 initialized to 100,000
- Th1: moves up to 10 from Total_1 to Total_2 or Total_3
- Th2: moves up to 20 from Total_2 to Total_1 or Total_3
- Th3: moves up to 30 from Total_3 to Total_1 or Total_2
- Th4: displays all totals consistently
- All operations must be thread-safe with proper mutex locking
*/

#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>
#include <unistd.h>
#include <time.h>

// Global totals as per assignment requirement
int Total_1 = 100000;
int Total_2 = 100000;
int Total_3 = 100000;

// Three mutexes to protect the three global variables
pthread_mutex_t m1 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m2 = PTHREAD_MUTEX_INITIALIZER;
pthread_mutex_t m3 = PTHREAD_MUTEX_INITIALIZER;

// Thread Th1: moves up to 10 from Total_1 to Total_2 or Total_3
void *thread1(void *arg)
{

    while (1)
    {
        int qty = rand() % 10 + 1;
        int choice = rand() % 2;

        if (choice == 0)
        {
            // Move from Total_1 to Total_2
            // Lock in order: m1 -> m2 (avoiding deadlock)
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m2);

            if (Total_1 >= qty)
            {
                Total_1 -= qty;
                Total_2 += qty;
                printf("Th1: Moved %d from Total_1 to Total_2\n", qty);
            }
            else
            {
                printf("Th1: Insufficient Total_1 balance (%d) for transfer of %d\n", Total_1, qty);
            }

            pthread_mutex_unlock(&m2);
            pthread_mutex_unlock(&m1);
        }
        else
        {
            // Move from Total_1 to Total_3
            // Lock in order: m1 -> m3 (avoiding deadlock)
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m3);

            if (Total_1 >= qty)
            {
                Total_1 -= qty;
                Total_3 += qty;
                printf("Th1: Moved %d from Total_1 to Total_3\n", qty);
            }
            else
            {
                printf("Th1: Insufficient Total_1 balance (%d) for transfer of %d\n", Total_1, qty);
            }

            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m1);
        }

        usleep(100000);
    }
    return NULL;
}

// Thread Th2: moves up to 20 from Total_2 to Total_1 or Total_3
void *thread2(void *arg)
{

    while (1)
    {
        int qty = rand() % 20 + 1;
        int choice = rand() % 2;

        if (choice == 0)
        {
            // Move from Total_2 to Total_1
            // Lock in order: m1 -> m2 (avoiding deadlock)
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m2);

            if (Total_2 >= qty)
            {
                Total_2 -= qty;
                Total_1 += qty;
                printf("Th2: Moved %d from Total_2 to Total_1\n", qty);
            }
            else
            {
                printf("Th2: Insufficient Total_2 balance (%d) for transfer of %d\n", Total_2, qty);
            }

            pthread_mutex_unlock(&m2);
            pthread_mutex_unlock(&m1);
        }
        else
        {
            // Move from Total_2 to Total_3
            // Lock in order: m2 -> m3 (avoiding deadlock)
            pthread_mutex_lock(&m2);
            pthread_mutex_lock(&m3);

            if (Total_2 >= qty)
            {
                Total_2 -= qty;
                Total_3 += qty;
                printf("Th2: Moved %d from Total_2 to Total_3\n", qty);
            }
            else
            {
                printf("Th2: Insufficient Total_2 balance (%d) for transfer of %d\n", Total_2, qty);
            }

            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m2);
        }

        usleep(150000);
    }
    return NULL;
}

// Thread Th3: moves up to 30 from Total_3 to Total_1 or Total_2
void *thread3(void *arg)
{

    while (1)
    {
        int qty = rand() % 30 + 1;
        int choice = rand() % 2;

        if (choice == 0)
        {
            // Move from Total_3 to Total_1
            // Lock in order: m1 -> m3 (avoiding deadlock)
            pthread_mutex_lock(&m1);
            pthread_mutex_lock(&m3);

            if (Total_3 >= qty)
            {
                Total_3 -= qty;
                Total_1 += qty;
                printf("Th3: Moved %d from Total_3 to Total_1\n", qty);
            }
            else
            {
                printf("Th3: Insufficient Total_3 balance (%d) for transfer of %d\n", Total_3, qty);
            }

            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m1);
        }
        else
        {
            // Move from Total_3 to Total_2
            // Lock in order: m2 -> m3 (avoiding deadlock)
            pthread_mutex_lock(&m2);
            pthread_mutex_lock(&m3);

            if (Total_3 >= qty)
            {
                Total_3 -= qty;
                Total_2 += qty;
                printf("Th3: Moved %d from Total_3 to Total_2\n", qty);
            }
            else
            {
                printf("Th3: Insufficient Total_3 balance (%d) for transfer of %d\n", Total_3, qty);
            }

            pthread_mutex_unlock(&m3);
            pthread_mutex_unlock(&m2);
        }

        usleep(200000);
    }
    return NULL;
}

// Thread Th4: displays all totals and grand total consistently
void *thread4(void *arg)
{

    while (1)
    {
        // Lock all mutexes in order to get consistent snapshot
        pthread_mutex_lock(&m1);
        pthread_mutex_lock(&m2);
        pthread_mutex_lock(&m3);

        int grand_total = Total_1 + Total_2 + Total_3;

        printf("\n********************************************************\n");
        printf("The CURRENT SUMS are:\n");
        printf(">>> Total_1 : %d\n", Total_1);
        printf(">>> Total_2 : %d\n", Total_2);
        printf(">>> Total_3 : %d\n", Total_3);
        printf(">>> Grand Total (T1+T2+T3) : %d\n", grand_total);
        printf("**********************************************************\n\n");

        // Unlock in reverse order
        pthread_mutex_unlock(&m3);
        pthread_mutex_unlock(&m2);
        pthread_mutex_unlock(&m1);

        sleep(1);
    }
    return NULL;
}

int main()
{
    printf("Starting Deadlock Avoidance Program\n");
    printf("Initial values: Total_1=%d, Total_2=%d, Total_3=%d\n", Total_1, Total_2, Total_3);
    printf("Grand Total should always remain: %d\n\n", Total_1 + Total_2 + Total_3);

    // Seed random number generator
    srand(time(NULL));

    // Declare thread variables
    pthread_t Th1, Th2, Th3, Th4;

    // Create all four threads
    if (pthread_create(&Th1, NULL, thread1, NULL) != 0)
    {
        printf("Error creating thread Th1\n");
        return 1;
    }

    if (pthread_create(&Th2, NULL, thread2, NULL) != 0)
    {
        printf("Error creating thread Th2\n");
        return 1;
    }

    if (pthread_create(&Th3, NULL, thread3, NULL) != 0)
    {
        printf("Error creating thread Th3\n");
        return 1;
    }

    if (pthread_create(&Th4, NULL, thread4, NULL) != 0)
    {
        printf("Error creating thread Th4\n");
        return 1;
    }

    printf("Threads are created successfully.\n");

    // Wait for threads (they run forever, so this blocks indefinitely)
    pthread_join(Th1, NULL);
    pthread_join(Th2, NULL);
    pthread_join(Th3, NULL);
    pthread_join(Th4, NULL);

    return 0;
}