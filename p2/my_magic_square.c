///////////////////////////////////////////////////////////////////////////////
// Copyright 2020 Jim Skrentny
// Posting or sharing this file is prohibited, including any changes/additions.
// Used by permission, CS 354 Spring 2022, Deb Deppeler
////////////////////////////////////////////////////////////////////////////////

////////////////////////////////////////////////////////////////////////////////
// Main File:        my_magic_square.c
// This File:        my_magic_square.c
// Other Files:      
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
// AI chats:         N?A
// 59/60 Error message does not match specification
//////////////////////////// 80 columns wide ///////////////////////////////////

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

// Structure that represents a magic square
typedef struct {
	int size;           // dimension of the square
	int **magic_square; // pointer to heap allocated magic square
} MagicSquare;

/* TODO:
 * Promps the user for the magic square's size, read it,
 * check if it's an odd number >= 3 (if not, display the required
 * error message and exit)
 *
 * return the valid number
 */
int getSize() {
	int magic_size = 0;
	// prompt user for input 
	printf("Enter magic square size (odd integer >=3):\n");

	// read keyboard input into magic_string variable 
	if ( scanf(" %d", &magic_size) != 1) {
		printf("Error reading user input.\n");
		exit(1);
	}

	//check if size is valid
	if (magic_size < 3){
		printf("Magic square size must be >=3.\n\r");
		exit(1);
	}

	if (magic_size % 2 == 0){
		printf("Magic square size must be odd.\n\r");
		exit(1);
	}
	return  magic_size;   
} 

/* TODO:
 * Makes a magic square of size n,
 * and stores it in a MagicSquare (on the heap)
 .*
 * It may use the Siamese magic square algorithm 
 * or alternate from assignment 
 * or another valid algorithm that produces a magic square.

 * n - the number of rows and columns
 *
 * returns a pointer to the completed MagicSquare struct.
 */
MagicSquare *generateMagicSquare(int n) {
	int square_number = 1;
	int row = 0;
	int col = 0;
	int prev_row = 0;
	int prev_col = 0;
	
	MagicSquare *my_magic_square = malloc(sizeof(MagicSquare));
	my_magic_square->size = n;

	// Allocate 2D Array
	int **magic_square_arr = malloc(n * (sizeof(int*)));
	if (magic_square_arr == NULL){
		printf("Failed to allocate memory for magic square:\n\r");
		exit(1);
	}
	for (int i = 0; i < n; i++){ 
		*((magic_square_arr)+i) = malloc(n * sizeof(int));
		if(*((magic_square_arr)+i) == NULL) {
			printf("failed to created 2d array\n\r");
			exit(1);
		}
	}

	// Initalize all elements in the magic square to 0	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			*(*(magic_square_arr+i)+j) = 0;
		}
	}

	// Place 1 in the middle top box in magic square
	col = n / 2; //middle col of the square
	*(*((magic_square_arr)+row)+col) = square_number;
	square_number++;

	// Determine what row and col is needed for next magic number
	while(square_number <= (n * n)) {
		prev_row = row;
		prev_col = col;

		if (row !=  0) {
			row--;
		} else {
			row = n - 1; //last row
		}
		if (col !=  n-1){
			col++;
		} else {
			col = 0;
		}

		// Checks if magic square already contains a number
		if (*(*(magic_square_arr+row)+col) == 0){
			*(*((magic_square_arr)+row)+col) = square_number;
			square_number++;
		} else {
			col = prev_col;
			if (prev_row !=  n-1){
				row = prev_row + 1;
			} else {
				row = 0;
			}
			*(*((magic_square_arr)+row)+col) = square_number;
			square_number++;
		}
	}

	my_magic_square->magic_square = magic_square_arr;

	return my_magic_square;    
} 

/* TODO:  
 * Opens a new file (or overwrites the existing file)
 * and writes the magic square values to the file
 * in the specified format.
 *
 * magic_square - the magic square to write to a file
 * filename - the name of the output file
 */
void fileOutputMagicSquare(MagicSquare *magic_square, char *filename) {
	int magic_input_size = magic_square->size;	
	int **my_magic_square = magic_square->magic_square;

	// Open the file and check if it opened successfully.
	FILE *fp = fopen(filename, "w");
	if (fp == NULL) {
		printf("Can't open file for writing.\n");
		exit(1);
	}
	// Print magic square into the file
	fprintf(fp, "%i\n\r", magic_square->size);	
	for (int i = 0; i < magic_input_size; i++) {
		for (int j = 0; j < magic_input_size; j++) {
			if (j == (magic_input_size - 1)) {
				fprintf(fp, "%i\n", *(*(my_magic_square+i)+j));
			} else {
				fprintf(fp, "%i,", *(*(my_magic_square+i)+j));
			}
		}
	}

	//Close the file.
	if (fclose(fp) != 0) {
		printf("Error while closing the file.\n");
		exit(1);
	} 
}


/* TODO:
 * Generates a magic square of the user specified size and
 * outputs the square to the output filename.
 * 
 * Add description of required CLAs here
 */
int main(int argc, char **argv) {
	// Check input arguments to get output filename
	if (argc != 2){
		printf("Incorrect command-line arguments given.\n");
		exit(1);
	}
	// TODO: Get magic square's size from user
	int square_size = getSize();

	// TODO: Generate the magic square by correctly interpreting 
	//       the algorithm(s) in the write-up or by writing or your own.  
	//       You must confirm that your program produces a 
	//       Magic Sqare as described in the linked Wikipedia page.
	MagicSquare *new_magic_square = generateMagicSquare(square_size);
	int **magic_square_arr = new_magic_square->magic_square;
	// TODO: Output the magic square
	char *magic_square_file = argv[1];
	fileOutputMagicSquare(new_magic_square, magic_square_file);

	// Free all dynamically allocated memory.
	for (int i = (square_size - 1); i >= 0; i--){
		free(*((magic_square_arr) + i));
	}
	free(magic_square_arr);
	magic_square_arr = NULL;	
	free(new_magic_square);
	new_magic_square = NULL;

	return 0;
} 

//    F23


