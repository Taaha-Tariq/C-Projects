#include <stdio.h>

int main(){
    int c;
    
    /*    Working 
    Loops through and reads the input till it encounters the EOF character and if there are multiple subsequent white spaces loops through them so that only one white space is printed to the terminal.*/
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