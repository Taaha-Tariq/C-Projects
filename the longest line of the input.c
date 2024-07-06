#include <stdio.h>

#define MAX_LEN 50
int getlines(char s[], int);
int stlen(char s[]);
void copy(char s[], char t[]);//the first is the array to be copied and the second is the array into which it will copy
int i = 0;

int main(){
    char ran[MAX_LEN];
    char cpy[MAX_LEN];
    int c;

    while((c = getchar()) != EOF){
        getlines(ran, c);
        if(c == '\n'){
            copy(ran, cpy);
            ran[0] = '\0';
            i = 0;
        }
    }
    printf("%s", cpy);
}

void copy(char s[], char t[]){
    int i = 0;
    
    if(stlen(s) > stlen(t)){
        for(; i < stlen(s); i++)
            t[i] = s[i];
        t[i] = '\0';
    }
    t[i] = '\0';
}

int stlen(char s[]){
    int i;

    for(i = 0; s[i] != '\0'; i++)
        ;
    return i;
}

int getlines(char s[], int c){
    
    if(c != '\n' && i < MAX_LEN - 1)
        s[i++] = c;
    else {
        s[i] = '\0';
        return i;
        }
    return 0;
}