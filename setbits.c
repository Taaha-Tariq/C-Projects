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

int setbits(int x, int p, int n, int y){
return (x & ((y << (p - n + 1)) | ~(~(~0 << n) << (p - n + 1))));
}

void printbits(int num){
    int size = sizeof(num) * 8;

    for(int i = size - 1; i >= 0; i--){
        int bits = (num >> i) & 1;
        printf("%d", bits);
    }
    printf("\n");
}