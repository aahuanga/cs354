////////////////////////////////////////////////////////////////////////////////
// Main File:        
// This File:        send_signal.c
// Other Files:      my_c_signal_handler.c, my_div0_handler.c
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

/* 
 * Send signal based on the first argument (-i for SIGINT or -u for SIGUSR1)
 * and the PID.
 * 
 */
int main(int argc, char *argv[])
{
	// Check for correct number of CLA
	if (argc != 3){
		printf("Usage: send_signal <signal type> <pid>\n");
		exit(0);
	}

	// Convert pid argument into an integer
	pid_t pid = atoi(argv[2]);
	
	// Check for valid pid
	if (getpgid(pid) >= 0){
		// Check the second CLA is valid
		if (strcmp(argv[1], "-u") == 0){
			kill(pid, SIGUSR1);
		} else if (strcmp(argv[1],"-i") == 0){
			kill(pid, SIGINT);
		} else {
			printf("Usage: send_signal <signal type> <pid>\n");
			exit(0);
		}
	} else {
		printf("Usage: send_signal <signal type> <pid>\n");
		exit(0);
	}
}
