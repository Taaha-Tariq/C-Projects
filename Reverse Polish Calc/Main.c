#include <stdio.h>
#include "calc.h"
#include <math.h>
#include <stdlib.h>

int main () {
    /*
    type:  stores the value returned by getline and as long as it is greater than zero (no EOF encountered) the loop continues.
    next_line:  After the inner loop has looped through the stored line and performed all the operations, it sets it equal to one to get a newline.
    get_val:  stores the value returned by getchars_from_line and is used as an expression for the switch.
    wh_to_prin:  Is set equal to one when some arithmetic operation is performed and lets the switch know that the result is to be printed.
    */
    int type, next_line, get_val, wh_to_prin;
    double temp; //For temp storing the numbers, in case of non-commutative operations.

    print_help();

    /*    Working
    Loops untill there is no line to be read. And after a line is read goes into another loop that reads that line and performs the specified operations using a switch and when the inner loop reaches the end of the stored line it prints the result if an arthmetic operation was performed and tells the outer loop to get a newline.*/
    while ((type = getline()) > 0) {
        next_line = wh_to_prin = 0;
        while (next_line != 1) {
            get_val = getchars_from_line();
            switch (get_val) {
                case NUMBER: 
                    push(atof(NUM));
                    break;
                case '\0':
                case '\n':
                    if (wh_to_prin) {
                        printf("\nThe result is %f\n", pop());
                        wh_to_prin = 0;
                    }
                    next_line = 1;
                    break;
                case '+':
                    push(pop() + pop());
                    wh_to_prin = 1;
                    break;
                case '*':
                    push(pop() * pop());
                    wh_to_prin = 1;
                    break;
                case '/':
                    temp = pop();
                    if(temp != 0) {
                        push(pop() / temp);
                        wh_to_prin = 1;
                    }
                    else 
                        printf("\nDivision by zero is undefined\n");
                    break;
                case '-':
                    temp = pop();
                    push(pop() - temp);
                    wh_to_prin = 1;
                    break;
                case '$':
                    temp = pop();
                    push((int)pop() % (int)temp);
                    wh_to_prin = 1;
                    break;
                case 's':
                    push(sin(pop()));
                    wh_to_prin = 1;
                    break;
                case 'c':
                    push(cos(pop()));
                    wh_to_prin = 1;
                    break;
                case 't':
                    push(tan(pop()));
                    wh_to_prin = 1;
                    break;
                case 'd':
                    if(dup()) 
                        printf("Successfully duplicated\n");
                    else 
                        printf("Error! Couldn't duplicate the last entry\n");
                    break;
                case 'p':
                    if(print_stack()) 
                        printf("\n");
                    else 
                        printf("The stack is empty\n");
                    break;
                case 'k':
                    if(clear()) 
                        printf("The stack was successfully emptied\n");
                    break;
                case 'w':
                    if(swap()) 
                        printf("Successfully Swapped\n");
                    break;
                case 'h':
                    print_help();
                    break;
                case 'q':
                    push(sqrt(pop()));
                    wh_to_prin = 1;
                    break;
                case 'a':
                    temp = pop();
                    push(pow(pop(), temp));
                    wh_to_prin = 1;
                    break;
                case 'b':
                    push(pow(pop(), 2));
                    wh_to_prin = 1;
                    break;
                default:
                    printf("INVALID INPUT!\n");
                    break;
            }
        }
    }

    return 0;
}