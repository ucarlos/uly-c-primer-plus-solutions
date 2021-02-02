//
// Created by ulysses on 3/1/17.
//
#include<stdio.h>
void pstrcpy(char *source, char *dest);
int pstrlen(char *string);
int main(void){
    char source[10] = "Bob";
    char dest[10] = "WASDFGJASA";
    printf("Before:\t%s\t%s\n", source, dest);
    pstrcpy(source, dest);
    printf("After:\t%s\t%s", source, dest);
    return 0;

}
void pstrcpy(char *source, char *dest){
    int sourcelen = pstrlen(source);
    int destlen = pstrlen(dest);
    if ((sourcelen + destlen) > sizeof(dest))
        return;
    else
        for (int i = 0; i < sourcelen; i++)
            *(dest + destlen + i) = *(source + i);


}

int  pstrlen(char *string){
    int counter = 0;
    while (*string != '\0'){
        counter++;
        string++;
    }
    return counter;
}
