#include <stdio.h>

void printbits(int);
int inverted(int, int, int);

int main(){
    int n = 255;
    printbits(n);
    printbits(inverted(n, 5, 4));
}

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

void printbits(int a){
    int size = sizeof(a) * 8;

    for(int i = size - 1; i >= 0; i--){
        int bits = (a >> i) & 1;
        printf("%d", bits);
    }
    printf("\n");
}