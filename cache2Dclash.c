////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Dclash.c
// This File:        cache2Dclash.c
// Other Files:      cache1D.c, cache2Drows.c, cache2Dcols.c
// Semester:         CS 354 Lecture 002 Fall 2023
// Grade Group:      gg9  
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

#define GLOBAL_N 10

/* Global Variables */
int arr2D[128][8];

int main(int argc, char *argv[]) {
	for (int iteration = 0; iteration < 100; iteration++) {
		for (int row = 0; row < 128; row += 64) {
			for (int col = 0; col < 8; col++) {
				arr2D[row][col] = iteration + row + col;
			}
		}
	}
	return 0;
}

