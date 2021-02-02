#include "common_header.h"
int main(void){

}
//
//Prevents buffer from messing with input by clearing it
char * s_gets(char *string, int len) {
    char *return_val, *find;
    return_val = fgets(string, len, stdin);
    if (return_val) {
        find = strchr(string, '\n'); //Look for newline
        if (find) //if the adress is not NULL
            *find = '\0';// place a null character there
        else
            while (getchar() != '\n')
                continue; //dispose of rest of line-- clear buffer
    }
    return return_val;
}

//Placing this in an inline static function would also work. Here's the prototype:
	//inline static clear_buffer(void){
	//	while (getchar() != '\n')
		//continue;
	//}
				
