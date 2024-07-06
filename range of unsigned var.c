#include <stdio.h>
#include <math.h>

int main(){
    int i, g;   //change the data type
    char* ptr = &i;
    char *ptr2 = &g;
    
    int bits = (ptr - ptr2) * 8;
    double max_unsigned = pow(2, bits) - 1;
    printf("%.0f", max_unsigned);
}