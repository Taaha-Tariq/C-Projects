#include <stdio.h>

// For printing the commands needed for the correct operation of the calculator
void print_help (void) {
    printf("\n*********************************************\n");
    printf("       Reverse Polish Calculator\n");
    printf("*********************************************\n");
    printf("The operands should precede the operator!\nThe negative sign followed directly by a number will be taken as a negative number.\n\n");
    printf("Commands to Use it:\n\n");
    printf(">     'a' : To raise the number by some power. Takes two operands, first base and the second exponent.\n");
    printf(">     'b' : square of the number\n");
    printf(">     'q' : square root of the number.\n");
    printf(">     'c' : cos of the number.\n");
    printf(">     's' : sin of the number.\n");
    printf(">     't' : tan of the number.\n");
    printf(">     'p' : To print the stack.\n");
    printf(">     'd' : To duplicate the last entry in the stack.\n");
    printf(">     'w' : Tp swap the last two entries.\n");
    printf(">     'h' : To print this again.\n");
    printf(">     'k' : To clean out the stack.\n");
    printf(">     '+' : For addition.\n");
    printf(">     '*' : For multiplication.\n");
    printf(">     '-' : For subtraction. The second number will be subtracted from the first.\n");
    printf(">     '/' : For division. The first number will be divided by the second.\n");
    printf(">     '$' : For taking modulus.\n");
    printf("\nTo exit the Program, press 'ctrl Z' on your keyboard.\n\n");
}