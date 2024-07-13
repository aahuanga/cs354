////////////////////////////////////////////////////////////////////////////////
// Main File:        my_c_signal_handler.c
// This File:        my_c_signal_handler.c
// Other Files:      send_signal.c, my_div0_handler.c
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
// 86/90 Failed to check return value for my_c_signal_handler & send_signal.c and my_div0_handler.c: SIGINT Handler had /n in beginning
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <signal.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <time.h>

// Global Variables
int ALARM_SEC = 5;
int COUNTER = 0;

/* 
 * Handles SIGALRM signal by outputing the PID and current time every
 * 5 seconds.
 */
void handler_SIGALRM(){
	time_t currentTime;
	time(&currentTime);
	printf("PID: %d CURRENT TIME: %s", getpid(), ctime(&currentTime));
	alarm(ALARM_SEC);
}

/* 
 * Handles SIGINT signal by outputting how many SIGUSR1 was recieved
 * and exits.
 */
void handler_SIGINT(){
	printf("\nSIGINT handled.\n");
	printf("SIGUSR1 was received %d times. Exiting now.\n", COUNTER);
	exit(0);
}

/* 
 * Hands SIGUSR1 signal by outputting a message on recieving a SIGUSR1
 * signal and incrementing a counter of how many signals recieved.
 */
void handler_SIGUSR1(){
	printf("SIGUSR1 handled and counted!\n");
	COUNTER++;
}

/* 
 * Sets alarm to go off every 5 seconds and registers signal handlers
 * including: SIGALRM, SIGUSR1, SIGINT.
 * 
 */
int main()
{
	alarm(ALARM_SEC);

	// Register SIGALRM handler
	struct sigaction sa;
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGALRM;
	if (sigaction(SIGALRM, &sa, NULL) != 0){
		printf("Error binding SIGALRM handler.\n");
		exit(1);
	}

	printf("PID and time print every 5 seconds.\n\r");
	printf("Type Ctrl-C to end the program.\n\r");

	//SIGUSR1
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGUSR1;
	if (sigaction(SIGUSR1, &sa, NULL) != 0){
		printf("Error binding SIGUSR1 handler.\n");
		exit(1);
	}

	//SIGINT
	memset(&sa, 0, sizeof(sa));
	sa.sa_handler = handler_SIGINT;
	if (sigaction(SIGINT, &sa, NULL) != 0){
		printf("Error binding SIGINT handler.\n");
		exit(1);
	}

	while(1){
	} 
}
