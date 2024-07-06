#include <stdio.h>

#define MAX_LEN 10
char stack[MAX_LEN];
int count = -1;

void push(char s);
int pop(void);

int main(){
    int c ,i, d;
    i = 0;

    while((c = getchar()) != EOF){
        if(c == '(' || c == '[' || c == '{')
            push(c);
        if(c == '}' || c == ']' || c == ')'){
            d = pop();
            if(c == d + 1 || c == d + 2)
                ;
            else{
                if(d == '(')
                    printf("\nEXPECTED %c BEFORE ", d + 1);
                else
                    printf("\nEXPECTED %c BEFORE ", d + 2);
            }
        }
        putchar(c);
    }
    
}

void push(char s){
    if(count + 1 < MAX_LEN)
       stack[++count] = s;
    else
        printf("Error! OVERFLOW");
}

int pop(void){
    int temp;

    if(count > -1){
        temp = stack[count];
        stack[count--] = '\0';
        return temp;
        }
    else
        printf("Error! UNDERFLOW");

    return -1;  
}