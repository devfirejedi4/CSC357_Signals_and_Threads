#include <stdio.h>
#include <pthread.h>

#define NUM_THREADS 5

int counter = 0;
pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;

// Function to be executed by the thread
void* thread_function(void* arg) 
{
    pthread_t tid = pthread_self();
    
    int i;
    for (i = 0; i < 10000; i++) 
    {
        pthread_mutex_lock(&mutex);
        counter++;
        printf("Thread %lu adding to counter: %d\n", (unsigned long)tid, counter);
        pthread_mutex_unlock(&mutex);
    }
    return NULL;
}

int main()
{
    pthread_t threads[NUM_THREADS];
    int i, result;

    // Create multiple threads
    for (i = 0; i < NUM_THREADS; i++)
    {
        result = pthread_create(&threads[i], NULL, thread_function, NULL);

        if (result != 0)
        {
            fprintf(stderr, "Thread creation failed: %d\n", result);
            return 1;
        }
    }

    // Wait for all threads to finish
    for (i = 0; i < NUM_THREADS; i++)
    {
        pthread_join(threads[i], NULL);
    }

    printf("Counter value: %d\n", counter);

    return 0;
}

