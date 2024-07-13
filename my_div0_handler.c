////////////////////////////////////////////////////////////////////////////////
// Main File:        my_div0_handler.c
// This File:        my_div0_handler.c
// Other Files:      send_signal.c, my_c_signal_handler.c
// Semester:         CS 354 Lecture 002 Fall 2023
// Instructor:       deppeler
// 
// Author:           Anna Huang
// Email:            ahuang62@wisc.edu
// CS Login:         ahuang62
//
///////////////////////////  WORK LOG  //////////////////////////////
//  Document your work sessions on your copy http://tiny.cc/work-log
//  Download and submit a pdf of your work log for each project.
/////////////////////////// OTHER SOURCES OF HELP ////////////////////////////// 
// Persons:          N/A
//
// Online sources:   N/A
// 
// AI chats:         N/A
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Global Variables
int COUNTER = 0;
/* 
 * Handles SIGFPE signal by outputing an error message and total operations
 * completed
 */
void handler_SIGFPE(){
	printf("Error: a division by 0 operation was attempted.\n");
	printf("Total number of operations completed successfully: %d\n", COUNTER);
	printf("The program will be terminated.\n");
	exit(0);
}

/* 
 * Handles SIGINT signal by outputting how many operations were completed
 * and exits.
 */
void handler_SIGINT(){
	printf("Total number of operations completed successfully: %d\n", COUNTER);
	printf("The program will be terminated.\n");
	exit(0);
}

/* 
 * Obtain two integers from user input and outputs the divided result
 * and the remainder.
 * 
 */
int main()
{
	struct sigaction sa;

	// Registers SIGFPE
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGFPE;
	if (sigaction(SIGFPE, &sa, NULL) != 0){
		printf("Error binding SIGFPE handler.\n");
		exit(1);
	}

	// Registers SIGINT
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGINT;
	if (sigaction(SIGINT, &sa, NULL) != 0){
		printf("Error binding SIGINT handler.\n");
		exit(1);
	}

	while(1){
		int buffer_size = 100;
		char buffer[buffer_size];
		int first_int;
		int second_int;
		int result;
		int remainder;

		printf("Enter first integer: ");
		if ( fgets(buffer, buffer_size, stdin) == NULL ) {      
             fprintf(stderr, "Error reading %i characters of user input.\n", buffer_size);
 }	
		first_int = atoi(buffer);

		printf("Enter second integer: ");
		if ( fgets(buffer, buffer_size, stdin) == NULL ) {      
			fprintf(stderr, "Error reading %i characters of user input.\n", buffer_size);
		}
		second_int = atoi(buffer);

		// Calculate the result and remainder of the two integers
		result = first_int / second_int;
		remainder = first_int % second_int;

		printf("%d / %d is %d with a remainder of %d\n", first_int, second_int, result, remainder);
		
		COUNTER++;
	} 
}
