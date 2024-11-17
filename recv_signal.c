/**
 * File: recv_signal.c
 * Modified by: Ryan Pal Hilgendorf
 * 
 * Brief summary of program:
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal(int sig, siginfo_t *info, void *ucontext) {
    printf("Signal pid: %d\n", info->si_value.sival_int);
}


int main() {
    struct sigaction action;

    // set the sigaction to the handler
    action.sa_sigaction = handle_signal;

    // gets the flag
    action.sa_flags = SA_SIGINFO;

    // Signal register
    sigaction(SIGUSR1, &action, NULL);

    printf("Type 'CTRL + z'. To see process, type ps in terminal\n");
    while(1);
    return 0;
}
