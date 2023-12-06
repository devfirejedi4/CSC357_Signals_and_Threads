#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT
void sigint_handler(int signum) 
{
    printf("\nReceived SIGINT (signum: %d)...\n", signum);
}

int main() 
{
    // Register the signal handler for SIGINT
    signal(SIGINT, sigint_handler);

    printf("Press Ctrl+C to trigger SIGINT...\n");

    // Infinite loop to keep the program running
    while (1) 
    {
        // Do some work here
        sleep(1);
    }

    return 0;
}

