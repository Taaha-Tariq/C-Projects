#include <stdio.h>

#define MAX_LEN 20
void lower(char s[]);//A function for converting a string to lowercase

int main(){
    char name[MAX_LEN] = "";//Enter the text that you wanna convert to lowercase
    lower(name);
    printf("%s", name);
}

/*    Working
Takes a string and loops through it and whenever it encounters a capital letter changes it to its corresponding lowercase using the fact that alphabets are stored contiguously in ascii*/
void lower(char s[]){
    int i;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
        else
            continue;
    }
}