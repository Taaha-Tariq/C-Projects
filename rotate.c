#include <stdio.h>

int bitcoun(int);
int rightrot(int, int);
void printbits(int);

int main(){
    int n = 298;
    printbits(n);
    printbits(rightrot(n, 3));
    printf("%d", rightrot(n, 3));
}

/*    Working
takes two arguments, a number x and an index n then stores the rightmost n-bits of the number in a temp var and discards the rightmost n-bits of the number. After which it calculates the position of the most significant bit in the changed number and moves the stored bits to the left by position + 1 and combines the two numbers using or operator.*/
/*   What the program is doing is: 
     let x = 101011011 and n = 3 
     so the rightmost three bits are 011,
     it discards these three bits from the original number and it becomes x = 101011
     and then moves them after the most significant bit.
     so the final number is 011 101011 or 01110111*/
int rightrot(int x, int n){
    int stor, bitdis;

    stor = x & ~(~0 << n);
    x = x >> n;
    bitdis = bitcoun(x);
    stor = stor << (bitdis + 1);
    return stor | x;
}
/*    Working
Returns the position of the most significant bit in a number.
starts from the left and when it encounters a one returns its position.*/
int bitcoun(int a){
    int size;
    size = sizeof(a) * 8;

    for(int i = size - 1; i >= 0; i--){
        if((a >> i) & 1){
            return i;
        }
    }
    return 0;
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