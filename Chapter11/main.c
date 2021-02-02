#include<stdio.h>
#include<math.h>

/*double hour_x = floor(radius *cos(angle));
   double hour_y = floor(radius *sin(angle));
 *
 *
 */
int main(void){
    int hour, minute, radius;
    int center_x, center_y;
    printf("Please enter the hour and radius:");
    scanf("%d %d", &hour, &radius);
    center_x = center_y = radius;
    double angle = M_PI_2 - ((M_PI * hour) / 6.0);
    //radius * floor(cos(M_PI_2 - M_PI/6 * (hour % 3)));
    double slope_hour_x = floor(radius *cos(angle));
    double slope_hour_y= floor(radius *sin(angle));
    int slope_spaces = (int)slope_hour_x - 1;

   /* for (int i = 1; i <= 2 * radius; i++){
        for(int circle_sp = 1; circle_sp <= radius; circle_sp++)
            printf(" ");
        printf("*");
        if(slope_hour_y > 0){
            for (int j = 1; j <= slope_spaces; j++)
                printf(" ");
        }

    }
    */

    for (int i = 1; i <= 2 * radius; i++)

    printf("The slope of x and y is %f and %f", slope_hour_x, slope_hour_y);
    //printf("The angle of hour %d is %f and %f", hour, hour_x, hour_y);

    return 0;
}
