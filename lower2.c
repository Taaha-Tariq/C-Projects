#include <stdio.h>

int lower(int a);

int main(){
    printf("%c", lower('a'));
}

int lower(int a){
    return (a >= 'A' && a <= 'Z') ? a - 'A' + 'a' : 0;
}