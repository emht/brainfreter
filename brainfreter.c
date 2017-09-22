#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>	// For the access() function to check the existence of the file

// The number of cells to be considered by the BrainF**k Interpreter
#define CELLS 10

// Commands or the characters used by the language
char *commands = ['<', '>', '+', '-', '[', ']', ',', '.'];

// Shell Initialisation
int shell();

// Interpreter function
int interpret(char *);

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
		//	printf("Error(1): File name missing!\nUsage: ./brainfreter [filename.bf]\n");
		//	exit(1);

		// Creating a shell for brainf**k like python or bash shell
		// the shell can be closed by "!" or "exit()" command
		printf("Initialising brainf**k interpreter shell:\n");
		shell();
		return 0;
	}
	
	// Storing the filename in the filename variable and check if it exists
	char *filename = argv[1];
	if( access( filename, F_OK ) != -1 ) {
		// File is accessible, Now check for correct format of the file
		// File Format accespted are ".bf" and ".b"
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
		exit(2);
	}

	// Initialising the number of memory cells for the operation
	int *cells = NULL;
	cells = (int)calloc(sizeof(int) * CELLS);
	
	// Pointer to current cell
	int *current = NULL;
	
	// Initialising to the start of the memory cells.
	current = &cell[0];
	
	while(filename != EOF) {
		interpret(line);
	}

	free(cells)
	return 0;
}

int shell() {
	/** Specification:
	 */

	return 0;
}

int interpret(char *line) {
	/** Specification:
	 */
	return 0;
}

int increment() {

	return 0;
}

int decrement() {
	return 0;
}

int leftshift() {
	
	return 0;
}

int rightshift() {

	return 0;
}

int loopin() {
	return 0;
}

int loopout() {
	return 0;
}

int print() {
	return 0;
}

int input() {
	return 0;
}
