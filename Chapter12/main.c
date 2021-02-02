#include <stdio.h>
#include<stdlib.h>
int main(void) {
    const char *string = "Hello";
    register const char *s;
    for (s = string; *s;++s);
    return(s - string);

}

/*
 *  char *speak = calloc(10, sizeof(char));
    puts(speak);
    sprintf(speak, "Hello World!");
    puts(speak);
    free(speak);
    return 0;
 *
 *
 *
 */