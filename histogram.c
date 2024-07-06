#include <stdio.h>

#define MAX_LEN 30
int max_ret(int a[], int);//Returns the largest number in the passed array
int words_counter(int a[], int);//Counts the number of words in the passed array

int main(){
    int c, lengths[MAX_LEN], length, count;
    length = count = 0;

    for(int i = 0; i < MAX_LEN; i++)
        lengths[i] = 0;
    
    /*      Working 
    Reads an input and stores the length of each word in an array(lengths)*/
    while((c = getchar()) != EOF){
        while(c != ' ' && c != '\n' && c != '\t'){
            length++;
            c = getchar();
        }
        if(length != 0){
            if(count < MAX_LEN){
                lengths[count++] = length;
                length = 0;
                }
        }
        if(count == MAX_LEN){
            printf("\nYour Words exceeded the index of the array\n");
            break;
            }
       }

    int x, f;
    x = 0;
    f = max_ret(lengths, MAX_LEN);
    
    /*     Working
    Prints a histogram showing the length of each word in the input using the array(lengths)*/
    /*loops (number of words + 1) * (largest word in the array)times and prints out the vertical lines to show the length of each word*/
    for(int i = 1; i <= (max_ret(lengths, MAX_LEN) * (words_counter(lengths, MAX_LEN) + 1)); i++){
        if(x > words_counter(lengths, MAX_LEN) - 1){
            putchar('\n');
            x = 0;
            f--;
            continue;
        }
        if(lengths[x++] >= f){
            putchar('|');
            putchar(' ');
            putchar(' ');
        }
        else{
            putchar(' ');
            putchar(' ');
            putchar(' ');
        }
    }

    /*For making the display neat by printing horizontal lines below the histogram and printing out the indices of the words along with their length*/
    for(int i = 1; i < 2 * (words_counter(lengths, MAX_LEN) + 1); i++){
        if(i < words_counter(lengths, MAX_LEN) + 1){
            putchar('-');
            putchar(' ');
            putchar(' ');
        }
        else if(i == words_counter(lengths, MAX_LEN) + 1){
            putchar('\n');
        }
        else{
            if(i - (words_counter(lengths, MAX_LEN) + 1) < 10)
                printf("%d  ", i - (words_counter(lengths, MAX_LEN) + 1));
            else
                printf("%d ", i - (words_counter(lengths, MAX_LEN) + 1));
        }
    }
}

/*     Working
Loops through the passed array and compares the value at the first index with the rest until it encounters a value bigger than that. In which case it compares this bigger value with the rest*/
int max_ret(int a[], int size){
    int k, j;
    j = 0;

    for(int i = 1; i < size; i++){
        if(a[j] > a[i])
            k = a[j];
        else{
            k = a[i];
            j = i;
        }
    }
    return k;
}

/*    Working
loops through an array till it encounters '\0' and returns the number of words whose lengths are stored in the array*/
int words_counter(int a[], int size){
    int q = 0;

    for(int i = 0; i < size; i++){
        if(a[i] != 0){
            q++;
        }
    }
    return q;
}