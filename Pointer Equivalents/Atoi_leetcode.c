#include <stdio.h>
#include <ctype.h>

int myAtoi(char *s); // Function for parsing a string and converting the string to its equivalent int and deals with special cases as what to do when the string exceeds storage capacity of the 32 bit signed int. In case the number is negative then the value stored will be -2^31 and if the number is positive then the value stored will be 2^31 - 1.

int main () {
    printf("%d", myAtoi("2147483648"));
}

/*    Working
takes a pointer to string as a pointer and returns the number in the string(signed int).
skips any preceding white spaces. Then if the number is preceded by a sign stores it in the sign var.
Skips starting zeros of the number. e.g:  +00002922 will be read as +2922.
uses two variables ind, first_value for the special cases such as when the number in the string exceedes the capacity of the signed 32 bit int. If the number is negative then -2^31 is returned and if it is ppositive then 2^31 - 1 is returned*/
int myAtoi(char* s) {
    int sign;
    unsigned int num;
    int first_val, ind;
    first_val = ind = 0;

    while (*s == ' ')
        s++;
    sign = (*s == '-') ? -1 : 1;
    if (*s == '+' || *s == '-') {
        s++;
    }
    while (*s == '0')
        s++;
    for (num = 0; *s <= '9' && *s >= '0'&& num <= 2147483648; s++, ind++) {
        num = num * 10 + (*s - '0');
        if (first_val == 0) {
            first_val = num;
        }
    }

    if (ind > 10 || (ind == 10 && first_val > 2) || num >= 2147483648) {
        if (sign == -1) {
            return -2147483648;
        }
        else {
            return 2147483647;
        }
    }
    return num * sign;
}