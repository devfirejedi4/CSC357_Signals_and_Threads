#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

// Structure to pass data to the thread function
struct ThreadData
{
    int thread_id;
    int num;
    char message[100];
};

// Thread function that returns a value
void* thread_function(void* arg)
{
    // Cast the argument back to the correct type
    struct ThreadData* data = (struct ThreadData*)arg;

    printf("Thread %d: %s\n", data->thread_id, data->message);
    printf("Thread %d: Received num: %d\n", data->thread_id, data->num);

    // If the thread needs to return a value, it can use pthread_exit
    int* result = malloc(sizeof(int));
    *result = data->num * 2;
    pthread_exit(result);
}

int main()
{
    pthread_t tid;
    struct ThreadData data = {1, 5, "Hello from the thread!"};
    int* result;

    // Create a thread and pass data to it
    int thread_create_result = pthread_create(&tid, NULL, thread_function, &data);

    if (thread_create_result != 0)
    {
        fprintf(stderr, "Thread creation failed: %d\n", thread_create_result);
        return 1;
    }

    // Wait for the thread to finish and get the result
    pthread_join(tid, (void**)&result);

    printf("Back in the main program\n");
    printf("Thread result: %d\n", *result);

    // Free the memory allocated for the result
    free(result);

    return 0;
}

