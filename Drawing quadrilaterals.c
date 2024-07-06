#include <stdio.h>
#include <unistd.h>

int l, w;
void ft_putchar(char *s);//A function to print symbols to the output
void print_func(int, int);//Function to print the desired shape
void rush(int, int);//The first argument is the horizontal dimension and the second argument is the vertical dimension

int main(){
    int a , b;
    printf("Enter the width of the quadrilateral\n");
    scanf("%d", &a);
    printf("Enter the length of the quadrilateral\n");
    scanf("%d", &b);
    rush(a, b);
}

/*      Working
Takes in a pointer to a char and prints out the symbol stored in it to the output*/
void ft_putchar(char *s){
    write(1, s, 1);
}

/*       Working
Takes in two arguments, one for width and the other for height and prints 'o' at the corners, horizontal lines at the top and bottom faces and vertical lines at the right and left faces*/
void print_func(int x, int y){
    char g;
    int a = 1;
    
    if((w == 1 && l == 1) || (w == x && l == 1) || (w == 1 && l == y) || (w == x && l == y)){
        g = 'o';
        ft_putchar(&g);
    }
    else if(l == 1 || l == y){
        g = '-';
        ft_putchar(&g);
    }
    else if(w == 1 || w == x){
        g = '|';
        if(w == x){
            g = ' ';
            while(a < x - 1){
                ft_putchar(&g);
                a++;
            }
            g = '|';
            ft_putchar(&g);
            }
        else
            ft_putchar(&g);
    }
    if(w == x){
        g = '\n';
        ft_putchar(&g);
    }
}

/*    Working
Takes in two arguments and makes sure that they are non-negative and loops to print the desired shape to the terminal*/
void rush(int x, int y){
    if(x <= 0 || y <= 0){
        write(1, "Error Invalid input", 20);
        return;
    }
    l = w = 1;

    while(l <= y){
        w = 1;

        while(w <= x){
            print_func(x, y);
            w++;
        }
        l++;
    }
}
