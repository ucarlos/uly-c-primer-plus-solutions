#include "common_header.h"
#include <math.h>
int main(int argc, char * argv[]){
    double value = atof(argv[1]);
	printf("The square root of %.3f is %.3f\n", value, sqrt(value));
	return 0;
}
