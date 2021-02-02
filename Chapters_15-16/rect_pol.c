//
// Created by ulysses on 5/25/17.
//
#include<stdio.h>
#include<math.h>
#include<stdlib.h>
#define RAD_TO_DEG (180 * (4 * atan(1)))
typedef struct polar_v{
    double magnitude;
    double angle;
}Polar_V;
typedef struct rect_v{
    double x, y;
}Rect_V;

Polar_V  to_polar(Rect_V rv);
int main(void){

    Rect_V input;
    Polar_V result;
    puts("Please Enter x and y coordinates. Enter q to quit.");

    while ((scanf("%lf %lf", &input.x, &input.y)) == 2){
        result = to_polar(input);
        printf("Magnitude: %.3f\tAngle:%.3f\n", result.magnitude, result.angle);
    }
    printf("Done.\n");


    return 0;
}Polar_V to_polar(Rect_V rv){
    Polar_V pv;
    pv.magnitude = sqrt(rv.x * rv.x + rv.y * rv.y);
    pv.angle = (pv.magnitude == 0)? 0.0 : RAD_TO_DEG * atan2(rv.y, rv.x);
    return pv;
}