//
// Created by ulysses on 5/12/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<string.h>
int calendar[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31,30, 31};

int main(void){
    int month, day, year;

    printf("Enter the month, date and year:");
    scanf("%d %d %d", &month, &day, &year);

    while ((!(1 <= month && month <= 12) || !(1<= day && day <= 31))||
            ((month == 2) && (day > 29))){
        printf("Incorrect month or date. Try again.\n");
        scanf("%d %d", &month, &day);
    }

    int date_num = 0;
    for (int i = 0; i < month - 1; i++)
        date_num += calendar[i];


    date_num += ((month > 2) && ((year % 4 == 0) || (year % 400 == 0)))? day + 1 : day;
    printf("%d day(s) have elapsed since January 1, %d.\n", date_num, year);
    return 0;

}


