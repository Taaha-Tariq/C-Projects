#include <stdio.h>

#define TABWIDTH 8
//A program to replace tabs in the input with an equivalent amount of blank spaces

int main(){
    int c;
    int space, column;

    column = 0;
    
    /*     Working
    Reads input and calculates the number of columns from the first letter or digit and when it encounters a tab calculates the space based on the columns and the length of a typical tab and prints out as many blanks*/
    while((c = getchar()) != EOF){
        if(c == '\t'){
            space = TABWIDTH - column % TABWIDTH;
            for(int i = 1; i <= space; i++){
                putchar(' ');
                column = 0;
            }
        }
        else{
            putchar(c);
            column += 1;
            if(c == '\n')
                column = 0;
        }
    }
}
