#define NUMBER -2 //Value that will be returned to let the caller know that a number was stored.
#define MAXLEN_NUM 15 //The size of the number that can be stores.
char NUM[MAXLEN_NUM];// The string for temp storing numbers so they can be pushed onto the stack.

/*     Working 
Uses the global stack index to return the last number that was pushed into the stack and updates the index so as to remove that number from the stack.
And if the stack is empty prints an error message*/
//IS DEFINED IN THE stack.c FILE
double pop (void);

/*     Working
Takes in a double and checks if there is still space in the stack. If so, pushes the number onto the stack and updates the stack index.
If the stack is full prints an error message.*/
//IS DEFINED IN THE stack.c FILE
void push (double num);

/*     Working 
Checks to see if there is still space in the stack. If there is, checks if there is atleast one number in the stack. If both the conditions are true, then duplicates the last entry and returns 1 to show that the duplication was successful.
If any one of the two conditions fail, return zero to show that duplication failed.*/
//IS DEFINED IN THE stack.c FILE
int dup (void);

/*     Working
Checks if there are numbers in the stack. If there are, then uses the global stack index to clear out the stack.
If there were no numbers to begin with then prints out an error message and returns 0.*/
//IS DEFINED IN THE stack.c FILE
int clear (void);

/*     Working 
Checks to see if there are more than two numbers in the stack. If yes, then swap the last two entries.
Else return zero and prints out an error message.*/
//IS DEFINED IN THE stack.c FILE
int swap (void);

/*     Working
Uses the global index to print the stack. and returns the number of values in the stack.*/
//IS DEFINED IN THE stack.c FILE
int print_stack (void);

/*     Working
Reads the input and stores them into a string till it encounters an end of file character or a newline character or the input exceeds the size of the string.
Returns zero if the end of file was read to let the caller know to exit the loop. Otherwise, returns 1.*/
//IS DEFINED IN THE getline.c FILE
int getline (void);

/*    Working
Uses the global j index to clear out the NUM string. then using the global index i loops through the stored line.
Skips any preceding white spaces in the stored line.
And when it encounters the first character that is not a blank, checks if that character is dot '.' or a digit if it is goes into a loop to store the number into the NUM string. And when it encounters the end of the number in the stored line, returns NUMBER to let the caller know that number was read from the stored line.
But if the first character that it encounters is not a digit nor a '.' returns its value to the caller.*/
//IS DEFINED IN THE getline.c FILE
int getchars_from_line (void);

// For printing the commands needed for the correct operation of the calculator
//IS DEFINED IN THE printhelp.c FILE
void print_help (void);