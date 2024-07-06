#include <stdio.h>

int main(){
    int c;

    while((c = getchar()) != EOF){
        putchar(c);

        while(c == ' '){
            c = getchar();
            if(c != ' ' && c != EOF)
                putchar(c);
        }
        if(c == EOF)
            break;
    }
}