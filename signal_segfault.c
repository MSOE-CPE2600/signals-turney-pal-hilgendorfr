/**
 * @file signal_segfault.c
 * @brief Program that dereferences a null pointer causing a segmentation fault
 */

/**
 * Modified by: Ryan Pal Hilgendorf
 * 
 * Brief summary of modifications: catches a segmentation fault when thrown.
 *     then keeps repeatedly faulting and catching infinitely since it does
 *     not exit.
 */


#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>

void handle_signal() {
    printf("Fault recieved.\n");
}

int main () {
    // Signal register
    signal(SIGSEGV, handle_signal);

    // Declare a null pointer
    int* i = NULL;

    // Dereference the null pointer
    printf("The value of i is: %d\n", *i);

    // Return to exit the program
    return 0;
}