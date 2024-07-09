#include <stdio.h>

#define MAX_LEN 20
void itob(int n, char s[], int b);//A function for converting a number stored in an integer to a string depending on the base that is passed
void reverse(char s[], int n);//To reverse the string bcz the stored string is in reverse order. n is the size of the string
int stringsize(char s[]);//To find the size of the string

int main(){
    int n = -920;
    char number[MAX_LEN];
    itob(n, number, 8);
    printf("%s", number);
}

/*    Working
Takes in a number, a string and a base and converts the number in an integer form to a string using the base that is passed*/
/*If base 16 is passed the number in the string will be in the form of a hexadecimal number*/
/*It also takes into consideration the sign of the integer number*/
void itob(int n, char s[], int b){
    int sign, i, temp;
    i = 0;
    
    if((sign = n) < 0)
        n = -n;
    
    do{
        temp = n % b;
        if(temp > 9)
            s[i++] = temp - 10 + 'a';
        else 
            s[i++] = temp + '0';
    }while((n /= b) > 0);

    if(sign < 0)
        s[i++] = '-';
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