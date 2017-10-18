/** It is the header file for the functions
  * Used in my brainfreter program
  */

// The number of cells to be considered by the BrainF**k Interpreter
#define CELLS 10

// Shell Initialisation
int shell() {
  printf("Hello!\n");
}

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