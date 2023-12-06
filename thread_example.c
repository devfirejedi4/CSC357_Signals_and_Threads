#include <stdio.h>
#include <pthread.h>

// Function to be executed by the thread
void* thread_function(void* arg)
{
    printf("Hello from the thread!\n");
    return NULL;
}

int main()
{
    pthread_t tid; // Thread ID
    int result;

    // Create a thread
    result = pthread_create(&tid, NULL, thread_function, NULL);

    if (result != 0)
    {
        fprintf(stderr, "Thread creation failed: %d\n", result);
        return 1;
    }

    // Wait for the thread to finish
    pthread_join(tid, NULL);

    printf("Back in the main program.\n");

    return 0;
}

