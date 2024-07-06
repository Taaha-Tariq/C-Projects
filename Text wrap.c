#include <stdio.h>

#define MAX_LEN 20
#define WH_TO_WRAP 30

int c;
char words[MAX_LEN];

int len(char s[]);
void getwords(void);
void clear(char s[]);

int main(){
    int count, i;
    count = i = 0;

    while((c = getchar()) != EOF){
        if(c != '\n' && c != ' ' && c != '\t')
            words[i++] = c;
        else{
            if(len(words) > 0){
                if(len(words) <= WH_TO_WRAP - count){
                    for(i = 0, count += len(words); i < len(words); i++)
                        putchar(words[i]);
                    i = 0;
                    clear(words);
                }
                else{
                    putchar('\n');
                    for(i = 0, count = len(words); i < len(words); i++)
                        putchar(words[i]);
                    i = 0;
                    clear(words);
                }
                putchar(c);
                count++;
            }
            else{
                count++;
                putchar(c);
            }
        }
        if(c == '\n')
            count = 0;
        if(count > WH_TO_WRAP){
            putchar('\n');
            count = 0;
        }
    }
}

void getwords(void){
    int i;
    i = 0;

    words[i++] = c;
    while((c = getchar()) != '\t' && c != ' ' && c != '\n')
        words[i++] = c;
}

void clear(char s[]){
    int i;

    for(i = len(s) - 1; i >= 0; i--)
        s[i] = '\0';
    return;
}

int len(char s[]){
    int i;
    i = 0;

    for( ; s[i] != '\0'; i++)
        ;
    return i;
}