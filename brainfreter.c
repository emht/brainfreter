/** Beware that this program takes allocates continuous memory locations and do not store the previous pointer location.
 * Pointers switch via *pntr-- or *pntr++
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
char *commands = ['<', '>', '+', '-', '[', ']', ',', '.'];

// Initialising the number of memory cells for the operation
int *cells = NULL;
// calloc to initialise the allocated memory to zero
cells = (int)calloc(sizeof(int) * CELLS);

// Pointer to current cell, leftmost and rightmost cell
int *current = NULL;
int *leftmost = NULL, *rightmost = NULL;

// Initialising to the start of the memory cells.
current = &cell[0];
const leftmost = &cell[0];
const rightmost = &cell[CELLS - 1];

// Shell Initialisation
int shell();

// Interpreter function
int interpret(char, int *);

// All the function definitions
int increment(int *);
int decrement(int *);
int leftshift(int *);
int rightshift(int *);
int print(int *);
int input(int *);
int loopin(int *);
int loopout(int *);

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
// Add the Regex feature here.
/*if(filename != *.bf || filename != *.b) {
	printf("Unsupported File Format! Only \".bf\" and \".b\" file formats are supported. :("\n);
}
else {
	// Interpret the file and produce output/errors for each line.
	// Using interpret function which inputs each line from file.
	// Produce outputs/errors as per the code.
	char *line = NULL;
	interpret(line);
	*/
	}
	else {
		// File is inaccessible and do not exist
		printf("Error(2): File do not exists, or is inaccessible.\nPlease check the existence and permissions of the file\n");
		exit(1);
	}
	
	// Creating a FILE pointer to access its contents
	FILE *fileptr;
	fileptr = fopen("filename", "r");
	
	if(fileptr == NULL) {
		printf("Error!\nCannot open file, Check if its permissible. \n");
		exit(3);
	}

	// Creating a char variable for temporarily storing the commands
	char command;

	// Change filename to the FILE pointer
	while(command = fgetc(fileptr) != EOF) {
		// Initialise the current pointer to location zero in memory cell after interpreting each line
		// Processing each line and checking via "\r" return character
		current = &cell[0];
		while(command != '\r') {
			interpret(command, current);
			command = fgetc(fileptr);
		}
	}


	fclose(fileptr);
	free(cells)
	return 0;
}

int shell() {
	/** Specification:
	 */
	print("Voila!!, you entered the matrix.\nImplementing shell in version 2.0!\n");
	return 0;
}

int interpret(char command, int *current) {
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
		case "+":
			increment(current);
			break;
		
		// Decrement the value of current value
		case "-":
			decrement(current);
			break;

		// Shifts the pointer to left side of the current cell
		case "<":
			leftshift(current);
			break;

		// Shifts the pointer to the right side of the current cell
		case ">":
			rightshift(current);
			break;

		// Looks for its correspondent "]", refer specifications for more details.
		case "[":
			loopin(current);
			break;

		// Looks for its correspondent "[", refer specifications for more details.
		case "]":
			loopout(current);
			break;

		// Prints the value corresponding to ascii value present in current cell to stdout.
		case ".":
			print(current);
			break;

		// ASCII value of the input from stdin is stored in current cell/memory.
		case ",":
			input(current);
			break;
		
		// Ignore the space if present
		case " ":
			// Pass to the next command in the script
			fileptr++;
			break;
		default:
			

	return 0;
}

int increment(int *current) {
	(*current)++;
	return 0;
}

int decrement(int *current) {
	(*current)--;
	return 0;
}

int leftshift(int *current) {
// Add the feature to check if the pointer is already at the leftmost position
// If the pointer is already at the leftmost position
// Warn the User and exit the program with an error code
	current--;
	return 0;
}

int rightshift(int *current) {
// Add the feature to check if the pointer is already at the rightmost position
// If it is, either increase the size, or exit the program with an error code
	current++;
	return 0;
}

int loopin(int *current) {
	
	return 0;
}

int loopout(int *current) {

	return 0;
}

int print(int *current) {
	printf("%c", *current);
	return 0;
}

int input(int *current) {
	// Input as an integer so that the ASCII value gets stored
	// In current as the address of the memory cell is contained in the pointer current
	scanf("%d", current);
	return 0;
}
