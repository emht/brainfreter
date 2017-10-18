#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <unistd.h>	// For the access() function to check the existence of the file
#include <stdbool.h>
#include "bf.h"

// flags
// File: if filename has correct format specified by the documentations
bool File_flag = false;

// Commands or the characters used by the language
// char *commands = {'<', '>', '+', '-', '[', ']', ',', '.'};

// Initialising the number of memory cells for the operation
// calloc to initialise the allocated memory to zero
int cells[CELLS] = {0}; 

int main(int argc, char *argv[]) {
	// Pointer to current cell, leftmost and rightmost cell
	int *current = cells;
	const int *leftmost = &cells[0];
	const int *rightmost = &cells[CELLS - 1];
	
	// Checking for the filename argument
	// If the filename to be interpreted is passed, then its output/errors are displayed
	// Else A current session like bash will open for interpreting bf commands
	if(argc < 2) {
		// Creating a shell for brainf**k like python or bash shell
		// the shell can be closed by "!" or "exit()" command
		printf("Initialising brainf**k interpreter shell:\n");
		shell();
		return 0;
	}
	
	// Storing the filename in the filename variable and check if it exists
	char filename[] = {'\0'};
	strcpy(filename, argv[1]);
	if(access(filename, F_OK) != -1) {
		// File is accessible
		int charac = 0;	
		
		// Now check for correct format of the file
		// File Format accespted are ".bf" and ".b"
		while(filename[charac] != '\0') {
			if(filename[charac] == '.') {
				// Check for ".b" and ".bf" format
				if(filename[charac + 1] == 'b') {
					if(filename[charac + 2] == '\0') {
						// The file is of ".b" format
						File_flag = true;
						break;
					}
					else if(filename[charac + 2] == 'f' && filename[charac + 3] == '\0') {
						// The file of ".bf" format
						File_flag = true;
						break;
					}
					else {
						// File do not have correct format
						printf("Unsupported File Format! Only \".b\" and \".bf\" file formats are supported. :(\n");
						exit(2);
					}
				}
				charac++;
			}
		}

	}
	else {
		// File is inaccessible and do not exist
		printf("Error(2): File do not exists, or is inaccessible.\nPlease check the existence and permissions of the file\n");
		exit(1);
	}
	
	// Creating a FILE pointer to access its contents
	extern FILE *fileptr;
	fileptr = fopen("filename", "r");
	
	if(fileptr == NULL) {
		printf("Error!\nCannot open file, Check if its permissible. \n");
		exit(3);
	}

	// Creating a char variable for temporarily storing the commands
	char command = fgetc(fileptr);

	// Change filename to the FILE pointer
	while(command != EOF) {
		// Initialise the current pointer to location zero in memory cell after interpreting each line
		// Processing each line and checking via "\r" return character
		current = &cells[0];
		while(command != '\n') {
			interpret(command);
			command = fgetc(fileptr);
		}
	}
	
	fclose(fileptr);
	return 0;
}