#include <stdio.h>

#define MAX_LEN 10
int htoi(char s[]);//Converts a string of hexadecimal number to its equivalent decimal value


int main(){
    char rand[MAX_LEN] = "4053fd";
    printf("%d", htoi(rand));
}

/*      Working
Loops through the string till it encounters '\0' and Uses the fact that hexadecimal system is a poistional system with weights associated with each position(16)*/
int htoi(char s[]){
    int val, i;
    val = 0;
    
    for(i = 0; s[i] != '\0'; i++){
        if(s[i] >= '0' && s[i] <= '9'){
            val = val * 16 + (s[i] - '0');
        }
        if(s[i] >= 'a' && s[i] <= 'f'){
            val = val * 16 + (s[i] - 'a' + 10);
        }
        if(s[i] >= 'A' && s[i] <= 'F'){
            val = val * 16 + ((s[i] - 'A' + 10));
        }
    }
    return val;
}