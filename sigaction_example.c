#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGINT
void sigint_handler(int signum) 
{
    printf("\nReceived SIGINT (signum: %d)...\n", signum);
    
    // Set the signal handler back to custom handler
    struct sigaction sa;
    sa.sa_handler = sigint_handler;
    sigaction(SIGINT, &sa, NULL);
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
        printf("\nHAHA! I'm still running!\n");
        sleep(1);
    }

    return 0;
}

