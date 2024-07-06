#include <stdio.h>

#define in_comment 1
#define out_comment 0
#define not_a_comment -2
#define EOFR -3 
int c;

int check_comment(void);

int main() {
    int to_check, EOFR_in_com; 
    EOFR_in_com = 0;

    while((c = getchar()) != EOF){
        if(c == '/'){
            if((to_check = check_comment()) == not_a_comment && to_check != EOFR){
                putchar('/');
                putchar(c);
                }
            else if(to_check == EOFR)
                EOFR_in_com = 1;
        }
        if(EOFR_in_com == 1)
            break;
        if(to_check == not_a_comment)
        to_check = 0;
        else
            putchar(c);
    }
}

int check_comment(){
    int state;

    c = getchar();
    if(c == '*'){
        state = in_comment;
        for( ; (c = getchar()) != EOF && state != out_comment; ){
            if(c == '*'){
                c = getchar();
                if(c == '/')
                    state = out_comment;
            }
        }
        if(c == EOF)
            return EOFR;
        }
    else if(c == '/'){
        state = in_comment;
        for( ; (c = getchar()) != EOF && state != out_comment;){
            if(c == '\n')
                state = out_comment;
        }
        if(c == EOF)
            return EOFR;
    }   
    else{
        return not_a_comment;
    }
}