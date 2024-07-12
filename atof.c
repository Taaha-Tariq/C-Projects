#include <stdio.h>
#include <ctype.h>

double atof1(char s[]);//A function for converting a string to a double

int main() {
    char number[] = "    -398.2918";
    printf("%f", atof1(number));
}

/*     Working
Takes a string and skips the starting whitespaces using isspace*/
/*Then checks for any sign. If the string begins with - then the sign interger is set equal to -1 else 1*/
/*Loops through the string till it reaches a non digit symbol and at each iteration converts the string using the fact that numbers are represented by contiguous values in ascii*/
/*If the first non digit symbol it encounters is a decimal point then it goes into another loop converting the string but also keeps check of how many spaces to the left is the decimal point.*/
/*Then it multiplies the number(val) by sign and divides it by the power(data type)*/
double atof1(char s[]) {
    int sign, i;
    double val, power;

    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '-' || s[i] == '+')
        i++;

    for(val = 0.0; isdigit(s[i]); i++)
        val = val * 10.0 + (s[i] - '0');
    
    if(s[i] == '.')
        i++;
    for(power = 1.0; isdigit(s[i]); i++) {
        val = 10.0 * val + (s[i] - '0');
        power *= 10.0; 
    }
    return sign * val / power;
}