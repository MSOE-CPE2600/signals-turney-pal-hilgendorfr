/**
 * File: send_signal.c
 * Modified by: Ryan Pal Hilgendorf
 * 
 * Brief summary of program: takes a PID from the user, seeds the generator,
 *     and sends the signal and random value to sigqueue
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <time.h>

int main() {
    // get pid
    int pid;
    printf("Insert PID of running program: ");
    scanf("%d", &pid);

    // seed the generator
    srand(time(NULL));

    // generate random signal value
    union sigval signalValue;
    signalValue.sival_int = rand();

    // send signal and value to process
    if (sigqueue(pid, SIGUSR1, signalValue) != 0) {
        perror("Signal Queue Error");
        exit(0);
    }
    return 0;
}