#include <stdio.h>
#include <ctype.h>

/*Skips the white spaces in the start of the string and gets the sign if there is any. And then returns the numeric value of the string till the first non-digit term*/
int atoi(char s[]);

int main(){
    char str[20] = "   -29393";
    printf("%d", atoi(str));
}

/*     Working
Uses ctype header functions to skip any white space in the start of the string*/
/*Gets the sign if there is any in the string and then converts the string number to its integer form*/
int atoi(char s[]){
    int i, sign, val;

    for(i = 0; isspace(s[i]); i++)
        ;
    sign = (s[i] == '-') ? -1 : 1;
    if(s[i] == '+' || s[i] == '-')
        i++;
    for(val = 0; isdigit(s[i]); i++){
        val = val * 10 + (s[i] - '0');
    }
    return sign * val;
}