/**
 * File: signal_alarm.c
 * Modified by: Ryan Pal Hilgendorf
 * 
 * Brief summary of program: Sends an alarm signal after an allotted
 *     amount of time, then exits the program.
 */
#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal() {
    printf("Received Alarm. Wee Woo.\n");
    exit(0);
}

int main() {
    // Signal register
    signal(SIGALRM, handle_signal);

    // sends alarm after 5 seconds
    alarm(5);
    // wait until alarm signal is sent
    unsigned int sleepTime = 10;
    while (sleepTime) {
        printf("Sleeping.\n");
        sleepTime = sleep(sleepTime);
    }
    return 0;
}