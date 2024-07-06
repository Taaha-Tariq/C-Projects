#include <stdio.h>

void squeeze(char s[], char t[]);

int main(){
    char name[] = "Hello i like gaming";
    char vowels[] = "aeiou";

    squeeze(name , vowels);
    printf("%s", name);
}

void squeeze(char s[], char t[]){
    int i, j, count, k;

    for(i = count = k = 0; s[i] != '\0'; i++){
        for(j = 0; t[j] != '\0'; j++){
            if(s[i] == t[j])
                count++;
        }
        if(count == 0)
            s[k++] = s[i];
        else
            count = 0;   
    }
    s[k] = '\0';
}