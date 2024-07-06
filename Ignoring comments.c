#include <stdio.h>

int main(){
    int c, i;
    i = 0;

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