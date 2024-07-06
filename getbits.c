#include <stdio.h>

int getbits(int, int, int);//A function to return the specified bits from a number
void printbits(int);//Function to print bits

int main (){
    int n = 70527;
    printbits(n);
    printf("%d", getbits(n, 9, 6));
}

/*     Working
Takes in a number and two indices(p and r). p specifies the position and r specifies the number of bits to be returned.*/
/*p is counted from the least significant bit and the least significant bit is at index 0*/
int getbits(int num, int p, int r){
    return (num >> (p - r + 1)) & ~(~0 << r);
}

/*       Working
Takes in a number and determines the number of bits that are used to store it*/
/*Loops through in reverse order till it equals negative one and at each iteration right shifts the number and isolates a single bit which is printed to the terminal*/
void printbits(int a){
    int size = sizeof(a) * 8;

    for(int i = size - 1; i >= 0; i--){
        int bits = (a >> i) & 1;
        printf("%d", bits);
    }
    printf("\n");
}