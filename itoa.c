#include <stdio.h>

void itoa(char s[], int n);//Takes an integer and stores its numeric value in a string
void reverse(char s[], int n);//To reverse the string bcz the stored string is in reverse order. n is the size of the string
int stringsize(char s[]);//To find the size of the string
#define MAX_LEN 10

int main(){
    int n = 892021;
    char s[MAX_LEN];
    itoa(s, n);
    printf("%s", s);
}

/*    Working
It takes an integer and loops till the number is reduced to zero*/
/*At each iteration it takes the modulo of the number and stores the ascii value of the remainder in the passed string*/
/*Since we are taking modulo and storing the ascii values of the remainder in the string, the stored number in the string is in reverse order*/
void itoa(char s[], int n){
    int i, temp;

    for(i = 0; n > 0; n = n / 10){
        temp = n % 10;
        s[i++] = temp + '0';
    }
    s[i] = '\0'; 
    reverse(s, stringsize(s));
}

/*    Working 
Takes a string and its size*/
/*loops till the index is less than half of the string length*/
/*At each iteration, swaps the indices which are equidistant from the center*/
void reverse(char s[], int n){
    int i, temp;

    for(i = 0; i < n / 2; i++){
        temp = s[n - i - 1];
        s[n - 1 - i] = s[i];
        s[i] = temp;
    }
    s[++n] = '\0'; 
}

/*     Working
Loops till it reaches the ending 0 of a string and returns the number of iterations*/
int stringsize(char s[]){
    int i;

    for(i = 0; s[i] != '\0'; i++)
        ;
    return i;
}