//
// Created by ulysses on 6/2/17.
//
#include "common_header.h"
#include <math.h>
#define DEG(x) (x) * (M_PI)/(180)
typedef struct pol{
    double x_value;
    double y_value;
}Polar;
Polar to_Polar(double radius, double angle);
int main(void){
    double radius, angle;
    printf("Enter the Radius and angle of the polar coordinate:");
    scanf("%lf%lf", &radius, &angle);
    Polar temp = to_Polar(radius, angle);
    printf("%.3f and %.3f degrees has been converted into rectangular coordinates:\nX = %.3f\tY = %.3f\n",
           radius, angle, temp.x_value, temp.y_value);

    return 0;
}
Polar to_Polar(double radius, double angle){
    Polar coord = {(radius *cos(DEG(angle))), (radius * sin(DEG(angle)))};
    return coord;
}