#include <stdio.h>
#include <stdbool.h>

bool Leap_year(int yy){
    if(yy % 4 == 0 && !(yy % 100 == 0))
    {return 1;}
    else{
        if(yy % 100 == 0 && yy % 400 == 0){
            return 1;
        }
        else{
            return 0;
        }
    }
}
int days_in_month[] = {1, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

int main(){
    int dd, mm, yy;
    dd = 9;
    mm = 7;
    yy = 2005;
    int days_to_be_added = 6940;
    int boolean = Leap_year(yy);
    if(boolean == 1){
            days_in_month[2] = 29;
        }else{}
    int days_that_can_be_accomodated = days_in_month[mm] - dd;
    int additional_days = days_to_be_added - days_that_can_be_accomodated;
    if(additional_days <= 0){
        dd += days_to_be_added;
    }
    else{if(mm < 12){   
        boolean = Leap_year(yy);
        if(boolean == 1){
            days_in_month[2] = 29;
        }else{
            days_in_month[2] = 28;
        }
        mm++;
        while(additional_days > days_in_month[mm]){
            if(mm < 12){
                boolean = Leap_year(yy);
                if(boolean == 1){
            days_in_month[2] = 29;
        }else{days_in_month[2] = 28;}
          additional_days = additional_days - days_in_month[mm];
          mm++;
          dd = additional_days;}
          else{
            boolean = Leap_year(yy);
            if(boolean == 1){
            days_in_month[2] = 29;
        }else{days_in_month[2] = 28;}
           additional_days = additional_days - days_in_month[mm];
          mm = 0;
          mm++;
          dd = additional_days; 
          yy += 1;
          }
        }
        dd = additional_days;
    }
    else{
        yy += 1;
        boolean = Leap_year(yy);
        mm = 0;
        mm++;
        if(boolean == 1){
            days_in_month[2] = 29;
        }else{days_in_month[2] = 28;}
        while(additional_days > days_in_month[mm]){
          if(mm < 12){
            boolean = Leap_year(yy);
            if(boolean == 1){
            days_in_month[2] = 29;
        }else{days_in_month[2] = 28;}
          additional_days = additional_days - days_in_month[mm];
          mm++;
          dd = additional_days;}
          else{
            boolean = Leap_year(yy);
            if(boolean == 1){
            days_in_month[2] = 29;
        }else{days_in_month[2] = 28;}
           additional_days = additional_days - days_in_month[mm];
          mm = 0;
          mm++;
          dd = additional_days; 
          yy += 1;
          }
        }
        dd = additional_days;
    }
    }
    printf("%d/%d/%d", dd, mm, yy);
    return 0;
}