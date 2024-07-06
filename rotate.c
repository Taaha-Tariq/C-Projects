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

int rightrot(int x, int n){
    int stor, bitdis;

    stor = x & ~(~0 << n);
    x = x >> n;
    bitdis = bitcoun(x);
    stor = stor << (bitdis + 1);
    return stor | x;
}

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

void printbits(int a){
    int size = sizeof(a) * 8;

    for(int i = size - 1; i >= 0; i--){
        int bits = (a >> i) & 1;
        printf("%d", bits);
    }
    printf("\n");
}