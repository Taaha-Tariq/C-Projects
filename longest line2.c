#include <stdio.h>

#define MAXLINE 100
int getlines(char line[], int lim);
void copy(char to[], char from[]);
//not considering newline to be a part of the line whereas in book they have

int main(){
    int len, max;
    char line[MAXLINE];
    char max_len[MAXLINE];
    max = 0;

    while((len = getlines(line, MAXLINE)) > 0){
        if(len > max){
            max = len;
            copy(max_len, line);
        }
    }

    if(max > 0){
        printf("%s", max_len);
    }
}

int getlines(char line[], int lim){
    int i, c;

    for(i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++){
        line[i] = c;
    }
    line[i] = '\0';

    return i;
}

void copy(char to[], char from[]){
    int i;
    i = 0;

    while((to[i] = from[i]) != '\0')
        i++;
    to[i] = '\0';
}