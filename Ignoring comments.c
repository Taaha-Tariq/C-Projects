#include <stdio.h>

//A program for removing comments

int main(){
    int c, i;
    i = 0;
    
    /*      Working 
    It reads an input and whhen it encounters a forwardslash, it checks whether the next character is * or / and if it is, it ignores the input after that until it encounters a newline(\n) character in case of // or the ending sequence (*/) */
    while((c = getchar()) != EOF){
        if(c == '/'){
            c = getchar();
            if(c == '/'){
                for(i = 0; i == 0 && (c = getchar()) != EOF;){
                    if(c == '\n')
                        i = 1;
                }
            }
            else if(c == '*'){
                for(i = 0; i == 0 && (c = getchar()) != EOF;){
                    if(c == '*'){
                        c = getchar();
                        if(c == '/'){
                            i = 1;
                        }
                    }
                }
            }
            else{
                putchar('/');
            }
        }
        if(c == EOF)
            break;
        if(i != 1){
            putchar(c);
        }
        else{
            i = 0;
        }
    }
}