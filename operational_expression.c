#include <math.h>
double sqrt(double x);

#define _CRT_SECURE_NO_WARNINGS 1
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Helper Functions
double get_leg_value();

int main(void) 
{
    /* insert initialize variables here */
    
    double a, b, c= 0;
    /* insert input values and assign to variables here */
    printf("Please input the first leg (A)\n");
    a = get_leg_value();

    printf("Please input the second leg (B)\n");
    b = get_leg_value();

    printf("Leg A: %.2lf\n", a);
    printf("Leg B: %.2lf\n", b);

    if(isnan(a) || isnan(b)) {
        c = NAN;
    }
    else {
        c = sqrt((a * a) + (b *b));
    }

    printf("Hypotenuse: %.2lf\n", c);
    return 0;
}

double get_leg_value() {
    char buffer[128] = {0};
    if(fgets(buffer, sizeof(buffer), stdin) != NULL) {
        double leg_value = strtod(buffer, NULL);
        if(leg_value > 0.0) {
            return leg_value;
        }
    }

    return NAN;
}