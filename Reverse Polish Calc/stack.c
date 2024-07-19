#include <stdio.h>

#define STACKSIZE 100 //The size of the stack 

static int ind = 0; //The stack index
static double stack[STACKSIZE]; //The array on which the stack is implemented

/*     Working 
Uses the global stack index to return the last number that was pushed into the stack and updates the index so as to remove that number from the stack.
And if the stack is empty prints an error message*/
double pop (void) {
    if(ind > 0) 
        return stack[--ind];
    else 
        printf("Error! Stack UNDERFLOW\n");
}

/*     Working
Takes in a double and checks if there is still space in the stack. If so, pushes the number onto the stack and updates the stack index.
If the stack is full prints an error message.*/
void push (double num) {
    if(ind < STACKSIZE) 
        stack[ind++] = num;
    else 
        printf("Error! Stack OVERFLOW\n");
}

/*     Working 
Checks to see if there is still space in the stack. If there is, checks if there is atleast one number in the stack. If both the conditions are true, then duplicates the last entry and returns 1 to show that the duplication was successful.
If any one of the two conditions fail, return zero to show that duplication failed.*/
int dup (void) {
    if(ind < STACKSIZE && ind > 0){
        stack[ind] = stack[ind - 1];
        ind++;
        return 1;
    }
    return 0;
}

/*     Working
Checks if there are numbers in the stack. If there are, then uses the global stack index to clear out the stack.
If there were no numbers to begin with then prints out an error message and returns 0.*/
int clear (void) {
    if (ind > 0) {
        while (ind > 0)
            stack[--ind] = '\0';
        return 1;
    }
    else {
        printf("The Stack is already empty\n");
        return 0;
    }  
}

/*     Working 
Checks to see if there are more than two numbers in the stack. If yes, then swap the last two entries.
Else return zero and prints out an error message.*/
int swap (void) {
    double temp;
    
    if(ind >= 2) {
        temp = stack[ind - 1];
        stack[ind - 1] = stack[ind - 2];
        stack[ind - 2] = temp;
        return 1;
    }
    else {
        printf("Not enough Values to Swap\n");
        return 0;
    }
}

/*     Working
Uses the global index to print the stack. and returns the number of values in the stack.*/
int print_stack (void) {
    int i;

    for(i = 0; i < ind; i++) 
        printf("%f ", stack[i]);
    return i;
}