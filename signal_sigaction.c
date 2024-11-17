/**
 * File: signal_sigaction.c
 * Modified by: Ryan Pal Hilgendorf
 * 
 * Brief summary of program: forks, passes SIGUSR1 through, and catches.
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <sys/wait.h>

void handle_signal(int sig, siginfo_t *info, void *ucontext) {
    printf("pid: %d\n", info->si_pid);
}

int main() {
    pid_t pid = fork();
    if (pid == 0) {
        // kill parent pid with signal
        kill(getppid(), SIGUSR1);
        printf("Child\n");
    } else {
        struct sigaction action;

        // set the sigaction to the handler
        action.sa_sigaction = handle_signal;

        // gets the flag
        action.sa_flags = SA_SIGINFO;

        // Signal register
        sigaction(SIGUSR1, &action, NULL);

        // wait for child
        wait(NULL);
        printf("Parent\n");
    }
    return 0;
}