#include <stdio.h>

int setbits(int, int, int, int);
void printbits(int);

int main(){
    int x = 127;
    int y = 12;
    printbits(x);
    printbits(y);
    printbits(setbits(x, 5, 3, y));

    printf("%d", setbits(x, 5, 3, y));
}

/*     Working 
It takes two numbers x and y and two indices p and n.
And starting at position p of x from the Least significant bit sets n bits equal to the rightmost n-bits of y
For example: let x = 100111, p = 3, n = 3, y = 1001010100 
So the returned number will be 101001*/
int setbits(int x, int p, int n, int y){
return (x & ((y << (p - n + 1)) | ~(~(~0 << n) << (p - n + 1))));
}

/*       Working
Takes in a number and determines the number of bits that are used to store it*/
/*Loops through in reverse order till it equals negative one and at each iteration right shifts the number and isolates a single bit which is printed to the terminal*/
void printbits(int num){
    int size = sizeof(num) * 8;

    for(int i = size - 1; i >= 0; i--){
        int bits = (num >> i) & 1;
        printf("%d", bits);
    }
    printf("\n");
}