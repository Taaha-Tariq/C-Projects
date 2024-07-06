#include <stdio.h>

void strcat(char s[], char t[]);//concatenates the second string onto the first
#define MAX_LEN 30

int main(){
    char first_name[MAX_LEN] = "";
    char last_name[] = "";
    strcat(first_name, last_name);
    printf("%s", first_name);
}

void strcat(char s[], char t[]){
    int i, j;

    for(i = 0; s[i] != '\0'; i++)
        ;
    for(j = 0; i < MAX_LEN && t[j] != '\0'; j++)
        s[i++] = t[j];
    s[i] = '\0';
}