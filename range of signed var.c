#include <stdio.h>
#include <math.h>

int main(){
    int i, g;
    char *ptr = &i;
    char *ptr2 = &g;
    int bits = (ptr - ptr2) * 8;

    double max = pow(2, bits);
    double max_signed = (max / 2) - 1;
    printf("The Range is form -%.0f to %.0f", max_signed + 1, max_signed);
}