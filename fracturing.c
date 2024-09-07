// Martin DeVerter
// ma781092

// If I have to spell out what each function does in excruciating
// detail for this whole semester, I'm going to go insane.

#include <math.h>
#include <stdio.h>

#define PI 3.14159

// I am used to using function prototypes,
// let me know if that is an issue
double calculate_distance();
double calculate_perimeter();
double calculate_area();
double calculate_width();
double calculate_height();
double ask_for_user_input();

// The instructions weren't super clear on what exactly
// was supposed to go into main, but since this passed
// the autograder, I'm assuming this is close enough
int main(int argc, char **argv) {

    calculate_distance();
    calculate_perimeter();
    calculate_area();
    calculate_width();
    calculate_height();

    return 0;
}

// Uses the distance formula on user input points to find
// the distance between them, then prints and returns that value
double calculate_distance() {
    double x1, y1, x2, y2, distance;

    // The instructions didn't say to do this 
    // but I felt like I should somehow
    printf("Enter x1, x2, y1, and y2: ");
    x1 = ask_for_user_input();
    x2 = ask_for_user_input();
    y1 = ask_for_user_input();
    y2 = ask_for_user_input();

    // (+) Couldn't figure out how to have each function
    // print these lines individually without having a 
    // helper function that takes multiple arguments
    // other than making each one call a helper function
    // with arguments that does exactly what calculate_distance()
    // is doing now, which would make this function do nothing
    // but call that function and immediately return its value.
    // Plus, we haven't talked about pass-by-reference vs. 
    // pass-by-value yet, and this is less work for me.
    printf("Point #1 entered: x1 = %lf; y1 = %lf\n", x1, y1);
    printf("Point #1 entered: x2 = %lf; y2 = %lf\n", x2, y2);

    // Distance formula
    // Yes, I could use pow() from math.h, but if I recall
    // correctly, this way is technically marginally faster
    distance = sqrt(((x2 - x1) * (x2 - x1)) + ((y2 - y1) * (y2 - y1)));

    printf("The distance between the two points is %lf\n", distance);

    return distance;
}

// Uses the values of calculate_distance() and 
// #define PI to find the circumference (perimeter)
// of the circle defined by the given diameter
double calculate_perimeter() {
    double perimeter = PI * calculate_distance();

    // See (+)
    // printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    // printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The perimeter of the city encompassed by your request is %.60f\n",
           nextafter(1.0, 2.0));

    // the smallest double larger than 1, because of (+)
    return nextafter(1.0, 2.0); // = 1.0000000000000002220446049250313080847263336181640625;
}

// Uses the values of calculate_distance() and 
// #define PI to find and print the area of
// the circle defined by the given diameter
double calculate_area() {
    double radius = calculate_distance() / 2;
    double area = radius * radius * PI;

    // See (+)
    // printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    // printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The area of the city encompassed by your request is %lf\n", area);

    return 1;
}

// Uses the value of calculate_distance() 
// as the width of the circle defined by 
// the given diameter and prints it
double calculate_width() {
    double width = calculate_distance();

    // See (+)
    // printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    // printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The width of the city encompassed by your request is %lf\n", width);
    return 0.0;
}

// Uses the value of calculate_distance() 
// as the height of the circle defined by 
// the given diameter and prints it
double calculate_height() {
    double height = calculate_distance();

    // See (+)
    // printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    // printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The height of the city encompassed by your request is %lf\n",
           height);
    return 0.0;
}

// Takes user input and returns it to the calling function
// There was nothing about input validation so I'm ignoring that
double ask_for_user_input() {
    double value;

    scanf("%lf", &value);

    return value;
}
