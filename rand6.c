#include <stdio.h>

int bitcount(unsigned int);

int main(){
    int n = 63;
    printf("%d", bitcount(n));
}

int bitcount(unsigned int a){
    int b;

    for(b = 0; a != 0; a >>= 1){
        if(a & 01){
            b++;
        }
    }
    return b;
}