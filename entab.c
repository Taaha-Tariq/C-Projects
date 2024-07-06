#include <stdio.h>

#define TABWIDTH 8

int main(){
    int c, space, column;
    space = column = 0;
    
    /*     Working 
    Takes in an input and replaces the blanks where they can be by tab character in the input stream*/
    /*Calculates the number of columns from the first letter or digit and blank spaces and wherever possible replaces the blank spaces with the tab sequence*/
    while((c = getchar()) != EOF){
        if(c == ' ')
            space++;
        else{
            for(int i = 0; space >= TABWIDTH - column % TABWIDTH; space -= (TABWIDTH - column % TABWIDTH) , i++){
                putchar('\t');
                if(i != 0){
                    column = 0;
                }
            }
                for(int i = 0; i < space; i++){
                    putchar(' ');
                    if(i == space - 1){
                        space = 0;
                        column = 0;
                    }
                }
            putchar(c);
            column += 1;
            if(c == '\n')
                column = 0;
            }
        }
    }

