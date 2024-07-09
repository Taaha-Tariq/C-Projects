#include <stdio.h>

int lower(int a);//A function for converting a character to lowercase

int main(){
    printf("%c", lower('a'));
}

/*    Working
Takes in a character and returns its corresponding lowercase*/
int lower(int a){
    return (a >= 'A' && a <= 'Z') ? a - 'A' + 'a' : 0;
}