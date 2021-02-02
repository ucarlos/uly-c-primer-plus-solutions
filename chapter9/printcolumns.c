//
// Created by ulysses on 1/16/17.
//
#include<stdio.h>
#include<ctype.h>
void chline(char ch, int rows, int columns);

int main(void){
    char character;
    int rows, columns;
    printf("Enter the character you want and its span(in rows and columns):");
    character = (char)getchar();
    scanf("%d %d", &rows, &columns);
    chline(character, rows, columns);
}
void chline(char ch, int rows, int columns){
    if (rows < 1 || columns < 1) return;
    for (int i = 1; i <= rows; i++){
        for (int j = 1; j <= columns; j++)
            putchar(ch);
        printf("\n");
    }

}