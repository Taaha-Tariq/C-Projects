#include <stdio.h>
#include <stdlib.h> //For atof (converts a string to a double)

/*    Reverse Polish Calculator
    the operands should precede the operator and does addition,subtraction,multiplication and division and can handle decimal digits. 
    there should be atleast a single blank space between subsequent entries in the input                 */

#define MAX_LEN 20 //The size of the stack and the character string
#define NUMBER 0 //getop returns this when it stores a number in the string
int ind = 0; //The index of the stack

double pop (void); //A function for returning the last value that was pushed onto the stack
void push (double num); //A function for pushing values onto the stack
int getop (char s[]); //A function for reading the input and storing numbers in a string and communicating with the main using return values about the input types

double stack[MAX_LEN]; //The array on which the stack is implemented
char str[MAX_LEN]; //A string for temporarily storing the numbers

int main (void) {
    int type, temp, dbz; //type stores the return value of getop, temp temporarily stores values and dbz indicates if the dividend was divided by zero in the input
    type = dbz = 0;

    /*     Working
    getop takes inputs from the terminal and communicates with main as to what kind of an input it received by returning specific values*/
    // 0 or NUMBER if the input was a number
    // The operators value if the input was an operator '+' '-' '/' '*'
    // If it encounters an '\n' returns its value
    // EOF if it encounters an end of file. Ctrl Z should be used to exit the loop
    while((type = getop(str)) != EOF && dbz != 1) {
        switch(type) {
            case 0:
            push(atof(str));
            break;
            case '+':
            push(pop() + pop());
            break;
            case '-':
            temp = pop();
            push(pop() - temp);
            break;
            case '/':
            temp = pop();
            if(temp != 0)
                push(pop() / temp);
            else {
                printf("Division by zero is undefined");
                dbz = 1;
            }
            break;
            case '*':
            push(pop() * pop());
            break;
            case '\n':
            printf("The result is %f\n", pop());
            break;
            default:
            printf("Wrong input");
            break;
        }
    }
}

/*   Working
Takes a string to store numbers in. IN and OUT are used to indicate if the loop is currently in the number or not.*/
/*Skips the starting white spaces and when it encounters the first digit, starts storing it in the array till the number ends. Then returns 0 to the main to indicate that a number was encountered*/
/*When it encounters an operator returns the operators ascii value to main and in case of an endline returns its ascii value.*/
int getop (char s[]) {
    int c, IN, OUT, i;
    IN = i = 0;
    OUT = 1;

    while((c = getchar()) != EOF && c != '\n') {
        if(c == '*' || c == '/' || c == '-' || c == '+')   
            return c;
        else if(c != ' ' && c != '\t') {
            s[i++] = c;
            IN = 1;
            OUT = 0;
        }  
        else {
            OUT = 1;
            if(IN == 1 && OUT == 1) {
                s[i] = '\0';
                return NUMBER;
            }
        }     
    }

    if(c == '\n')
        return '\n';
    else 
        return EOF;
}

/*     Working
Takes a double as an argument and stores it in the stack using the global variable ind and updates the global var*/
void push (double num) {
    if(ind < MAX_LEN){
        stack[ind++] = num;
    }
    else {
        printf("stack Overflow");
    }
}

/*     Working 
returns the last number that was pushed unto the stack and updates the ind.*/
double pop (void) {
    if(ind > 0){
        return stack[--ind];
    }
    else {
        printf("Stack Underflow");
        return 0.0;
    }
}
