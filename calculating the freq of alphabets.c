#include <stdio.h>

#define NOA 26
int fre[NOA];//An array for storing the frequency if each alphabet in the input
int max_ret(int a[], int);//takes an array and its size and returns the biggest number from the array

int main(){
    int c, indices, max_val;

    indices = 0;
    
    /*To take in an input from the user. In this case, from the terminal and storing the frequency of each alphabet in an array*/
    while((c = getchar()) != EOF){
        if(c >= 'a' && c <= 'z')
            fre[c - 'a']++;
        else if(c >= 'A' && c <= 'Z')
            fre[c - 'A']++;
    }

    max_val = max_ret(fre, NOA);
    /*A loop to print a histogram based on how often the alphabet occured in the input*/
    for(int i = 0; i < max_ret(fre, NOA) * (NOA + 1); i++){
        if(indices > NOA - 1){
            putchar('\n');
            indices = 0;
            max_val--;
        }
        else if(fre[indices++] >= max_val){
            putchar('|');
            putchar(' ');
        }
        else{
            putchar(' ');
            putchar(' ');
        }
    }
    
    /*A loop to make the histogram look nicer and to print the alphabets in the order in which their freq is displayed*/
    for(int i = 1; i < 2 * (NOA + 1); i++){
        if(i < NOA + 1){
            putchar('-');
            putchar(' ');
        }
        else if(i == NOA + 1){
            putchar('\n');
        }
        else{
            putchar('a' + i - (NOA + 2));
            putchar(' ');
        }
    }
}

/*    Working
Uses two int and loops through the array. The integer j points towards index 0 initally but as loop goes on and a number greater than the number at index zero is encountered the int j stores that index. And so at the end index j stores the index of the biggest number in the array*/
/*And the number at that index is returned*/
int max_ret(int a[], int size){
    int i;
    int j = 0;

    for(i = 0; i < size; i++){
        if(a[j] > a[i])
            ;
        else
            j = i;
    }
    return a[j];
}