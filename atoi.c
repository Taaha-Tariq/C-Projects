#include <stdio.h>

//atoi converts strings to their numeric value
int atoi(char s[]);
#define MAX_LEN 10

int main(){
   char num[MAX_LEN] = "78291";
   printf("%d", atoi(num));
}

/*    Working
Uses the fact that ascii characters are contiguously stored and that decimal system is a positional system.*/
/*The string must start with a number and loops till the first non-digit character.*/
int atoi(char s[]){
    int i, n;
    
    for(n = 0, i = 0; s[i] >= '0' && s[i] <= '9'; i++)
        n = n * 10 + (s[i] - '0');
    return n;
}