#define _POSIX_SOURCE
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>
#include <unistd.h>

// Signal handler for SIGUSR1
void sigusr1_handler(int signum) 
{
    printf("Received SIGUSR1. Doing something special...\n");
    // Add custom behavior here
}

// Signal handler for SIGUSR2
void sigusr2_handler(int signum) 
{
    printf("Received SIGUSR2. Doing something else...\n");
    // Add custom behavior here
}

int main() 
{
    // Register the signal handlers for SIGUSR1 and SIGUSR2
    signal(SIGUSR1, sigusr1_handler);
    signal(SIGUSR2, sigusr2_handler);

    printf("PID: %d\n", getpid());
    printf("Send SIGUSR1 or SIGUSR2 to this process using 'kill -SIGUSR1 [PID]' or 'kill -SIGUSR2 [PID]'\n");

    // Infinite loop to keep the program running
    while (1) 
    {
        // Do some work here
        sleep(1);
    }

    return 0;
}

