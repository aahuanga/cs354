////////////////////////////////////////////////////////////////////////////////
// Main File:        cache2Drows.c
// This File:        cache2Drows.c
// Other Files:      cache1D.c, cache2Dcols.c, cache2Dclash.c
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
int arr2D[3000][500];

int main(int argc, char *argv[]) {
	for (int row = 0; row < 3000; row++){
		for (int col = 0; col < 500; col++){
			arr2D[row][col] = row + col;
		}
	}
	return 0;
}
