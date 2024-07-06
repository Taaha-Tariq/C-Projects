#include <stdio.h>
#include <string.h>

#define BUFSIZE 100
#define MAXLEN 1000

void ungetch(int);
void ungets(char s[]);
int getch(void);

char buf[BUFSIZE];
int bufp = 0;

int main(){
    int i;
    char s[MAXLEN];
    for(i = 0; (s[i] = getch()) != '\n'; i++)
        ;
    s[++i] = '\0';
    ungets(s);
    printf("%s", buf);
    return 0;
}

void ungetch(int a){
    if(bufp >= BUFSIZE){
        printf("Error");
    }
    else{
        buf[bufp++] = a;
    }
}

void ungets(char s[]){
    int i;

    for(i = strlen(s) - 1; i >= 0; i--)
        ungetch(s[i]);
}

int getch(void){
    return (bufp > 0) ? buf[--bufp] : getchar();
}