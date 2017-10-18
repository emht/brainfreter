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
