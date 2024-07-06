#include <stdio.h>

#define MAX_LEN 20
void lower(char s[]);

int main(){
    char name[MAX_LEN] = "";//Enter the text that you wanna convert to lowercase
    lower(name);
    printf("%s", name);
}

void lower(char s[]){
    int i;

    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= 'A' && s[i] <= 'Z')
            s[i] = s[i] - 'A' + 'a';
        else
            continue;
    }
}