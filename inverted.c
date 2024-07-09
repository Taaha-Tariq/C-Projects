#include <stdio.h>

void printbits(int);
int inverted(int, int, int);//A function that inverts the specified bits

int main(){
    int n = 255;
    printbits(n);
    printbits(inverted(n, 5, 4));
}


/*     Working
Takes an int x and two integers one specifying the starting index and the other the number of bits to invert*/
/*It separates the int x into three ints one storing the bits to the left of the bits to be inverted (gt), the other storing the bits to be inverted (et) and the last storing the bits to the right of the bits to be inverted*/
/*Then it inverts the bits stored in et*/
/*After which it moves the bits to their respective positions in the original number and combines the three ints using or operator and returns the value*/
int inverted(int x, int p, int n){
    int gt, et, st;

    gt = x >> (p + 1);
    gt = gt << (p + 1);
    st = x & ~(~0 << (p - n + 1));
    et = (x >> (p - n + 1)) & ~(~0 << n);
    et = ~et & ~(~0 << n);
    et = et << (p - n + 1);
    return et | st | gt;
}

//A function for printing bits to the terminal
void printbits(int a){
    int size = sizeof(a) * 8;

    for(int i = size - 1; i >= 0; i--){
        int bits = (a >> i) & 1;
        printf("%d", bits);
    }
    printf("\n");
}