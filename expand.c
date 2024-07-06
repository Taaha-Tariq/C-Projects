#include <stdio.h>

void expand(char s[], char z[], int n);
#define MAX_LEN 40
/*A program to replace sequences like a-d with all the characters in between.
the char s[] is the string to be read and manipulated
the char z[] is the string in which the result will be stored
int n is the memory capacity of char z[]
char s[] should have a minimum of two characters
*/

int main(){
    char str[] = "a-z0-9*a-g";
    char str2[MAX_LEN];
    expand(str, str2, MAX_LEN);
    printf("%s", str2);
}

/*   Working
it stores a character from char s[] in the int temp and then reads the next character if it is '-' then it loops storing all the characters from the character before '-' to the character after it*/
/*There is a condition for it to loop through storing from some x-z if '-' is stored in temp*/
/*For the third case if it doesnt read '-' at the next index, it stores temp and the character at that index in the char z[]*/
void expand(char s[], char z[], int n){
    int i, temp, j, k;
    k = j = 0;

    for(i = 0; s[i] != 0 && s[i + 1] != 0 && k < n - 2; i++){
        temp = s[i];
        if(s[++i] == '-'){
            i++;
            for(j = temp; j <= s[i] && k < n - 1; j++){
                z[k++] = j;
            }
        }
        else if(temp == '-'){
            for(j = s[i - 2] + 1; j <= s[i] && k < n - 1; j++){
                z[k++] = j;
            }
        }
        else {
            z[k++] = temp;
            z[k++] = s[i];
            j = 0;
        }
        if(k == n - 2)
            break;
    }
    z[k] = '\0';
}