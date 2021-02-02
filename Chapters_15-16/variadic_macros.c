//
// Created by ulysses on 5/29/17.
//
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
#define PRINT(X, ...) printf("Number " #X ":" __VA_ARGS__)
int main(void){
    double x = 48, y = sqrt(x);
    PRINT(1, "x = %g\n", x);
    PRINT(2, "x = %.2f, y = %.4f\n", x, y);

    //PRINT(1, "%s%s%s%s", "The ", "Road to hell ", "is paved ", "with good intentions.");
    return 0;
}



/*In the first macro call, X has the value 1, so #X becomes "1". That makes the expansion look
like this:
        print("Message " "1" ": " "x = %g\n", x);
Then the four strings are concatenated, reducing the call to this:
        print("Message 1: x = %g\n", x);

Here’s the output:
        Message 1: x = 48
        Message 2: x = 48.00, y = 6.9282
Don’t forget, the ellipses have to be the last macro argument:
#define WRONG(X, ..., Y) #X #_ _VA_ARGS_ _ #y // won't work
*/
