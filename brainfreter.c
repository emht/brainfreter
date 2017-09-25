/** Beware that this program takes allocates continuous memory locations and do not store the previous pointer location.
 * Pointers switch via *pntr-- or *pntr++
 *******************************************************************************************************************
 *************************** Global variables, pointers ****************************************************
 * cells, leftmost, rightmost, 
 * char *commands;
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>	// For the access() function to check the existence of the file
#include <stdbool.h>

// The number of cells to be considered by the BrainF**k Interpreter
#define CELLS 10

// flags
// File: if filename has correct format specified by the documentations
bool File_flag = false;

// Commands or the characters used by the language
// char *commands = {'<', '>', '+', '-', '[', ']', ',', '.'};

// Initialising the number of memory cells for the operation
// calloc to initialise the allocated memory to zero
char *cells = (char *)calloc(CELLS, sizeof(char));

// Pointer to current cell, leftmost and rightmost cell
char *current;
char *leftmost
char *rightmost;

// Initialising to the start of the memory cells.
// Should do const leftmost and cost rightmost
leftmost = &cells[0];
rightmost = &cells[CELLS - 1];

// Shell Initialisation
int shell();

// Interpreter function
int interpret(char);

// All the function definitions
int increment();
int decrement();
int leftshift();
int rightshift();
int print();
int input();
int loopin();
int loopout();

int main(int argc, char *argv[]) {
	

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
	char *filename = argv[1];
	if( access( filename, F_OK ) != -1 ) {
		// File is accessible
		int charac = 0;	
		
		// Now check for correct format of the file
		// File Format accespted are ".bf" and ".b"
		while(filename[charac] != NULL) {
			if(filename[charac] == ".") {
				// Check for ".b" and ".bf" format
				if(filename[charac + 1] == "b") {
					if(filename[charac + 2] == NULL) {
						// The file is of ".b" format
						File_flag = true;
						break;
					}
					else if(filename[charac + 2] == "f" && filename[charac + 3] == NULL) {
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
	free(cells);
	return 0;
}

int shell() {
	/** Specification:
	 */
	print("Voila!!, you entered the matrix.\nImplementing shell in version 2.0!\n");
	return 0;
}

int increment() {
	(*current)++;
	return 0;
}

int decrement() {
	(*current)--;
	return 0;
}

int leftshift() {
// Add the feature to check if the pointer is already at the leftmost position
// If the pointer is already at the leftmost position
// Warn the User and exit the program with an error code
	current--;
	return 0;
}

int rightshift() {
// Add the feature to check if the pointer is already at the rightmost position
// If it is, either increase the size, or exit the program with an error code
	current++;
	return 0;
}

int loopin() {
	if(*current == 0) {
		// look for corresponding ']'

	}
	else {
		// Follow next instruction i.e. read and execute next symbol
	}
	return 0;
}

int loopout() {
	if(*current == 0) {
		// Follow next instruction i.e after ']'

	}
	else {
		// Look for its corresponding '['
	}
	return 0;
}

int print() {
	printf("%c", *current);
	return 0;
}

int input() {
	// Input as an integer so that the ASCII value gets stored
	// In current as the address of the memory cell is contained in the pointer current
	scanf("%d", current);
	return 0;
}

int interpret(char command) {
	/** Specification:
	 * Line is passed to the function so that the interpreted can parse over each of its command
	 * Current Pointer is passed so that the required modification can take place
	 */
	
	//	char command = NULL;
	// Read the characters of each line one by one
	// Ignore the spaces encountered if any till the return character is encountered

	// Check if the all the character is a allowed command

	// Process each command symbol
	switch(command) {

		// Increment the value of current cell
		case '+':
			increment();
			break;
		
		// Decrement the value of current value
		case '-':
			decrement();
			break;

		// Shifts the pointer to left side of the current cell
		case '<':
			leftshift();
			break;

		// Shifts the pointer to the right side of the current cell
		case '>':
			rightshift();
			break;

		// Looks for its correspondent "]", refer specifications for more details.
		case '[':
			loopin();
			break;

		// Looks for its correspondent "[", refer specifications for more details.
		case ']':
			loopout();
			break;

		// Prints the value corresponding to ascii value present in current cell to stdout.
		case '.':
			print();
			break;

		// ASCII value of the input from stdin is stored in current cell/memory.
		case ',':
			input();
			break;
		
		// Ignore the space if present
		case ' ':
			// Pass to the next command in the script
			fileptr++;
			break;
		default:
			printf("Error!(Code 4)  Unrecognised symbol: %c\n", command);
			printf("Exitting program...\n");
			exit(4);
	}
	return 0;
}