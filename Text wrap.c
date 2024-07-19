#include <stdio.h>

#define MAX_LEN 20 //The size of the word string
#define WH_TO_WRAP 30 //The number of columns after which the line should wrap to the next line

int c;
char words[MAX_LEN]; //string for storing words

int len(char s[]); //Function for returning the size of the string
void getwords(void); //functions for storing words into the global string.
void clear(char s[]); //function for emptying the words string.

int main(){
    int count, i;
    count = i = 0;
    
    /*    Working
    Reads from input till it encounters the EOF character
    It first stores each word into a string then checks if there are enough columns left to accomodate the stored word in the current line. If there are then it prints the word, else it goes to the next line and then prints the word.*/
    while((c = getchar()) != EOF){
        if(c != '\n' && c != ' ' && c != '\t')
            words[i++] = c;
        else{
            if(len(words) > 0){
                if(len(words) <= WH_TO_WRAP - count){
                    for(i = 0, count += len(words); i < len(words); i++)
                        putchar(words[i]);
                    i = 0;
                    clear(words);
                }
                else{
                    putchar('\n');
                    for(i = 0, count = len(words); i < len(words); i++)
                        putchar(words[i]);
                    i = 0;
                    clear(words);
                }
                putchar(c);
                count++;
            }
            else{
                count++;
                putchar(c);
            }
        }
        if(c == '\n')
            count = 0;
        if(count > WH_TO_WRAP){
            putchar('\n');
            count = 0;
        }
    }
}

/*    Working
loops and stores words in a string till it encounters a blank or a tab or a newline character.*/
void getwords(void){
    int i;
    i = 0;

    words[i++] = c;
    while((c = getchar()) != '\t' && c != ' ' && c != '\n')
        words[i++] = c;
}

/*    Working
takes a string and loops backwards setting each position equal to '\0' and empties the string.*/
void clear(char s[]){
    int i;

    for(i = len(s) - 1; i >= 0; i--)
        s[i] = '\0';
    return;
}

/*    Working
loops through a string till it encounters '\0' and returns its length.*/
int len(char s[]){
    int i;
    i = 0;

    for( ; s[i] != '\0'; i++)
        ;
    return i;
}