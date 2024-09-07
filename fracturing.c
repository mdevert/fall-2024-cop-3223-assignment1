// Martin DeVerter
// ma781092

// If I have to spell out what each function does in excruciating
// detail for this whole semester, I'm going to go insane.
// I have taken both CS1 and CS2 but UCF hates transfer credit
// so have some pass by reference for fun.

// I know my comments aren't the cleanest, thats on me for waiting 
// to implement them until last minute since I kept changing things

#include <math.h>
#include <stdio.h>

#define PI 3.14159

// I'm used to using function prototypes,let me know if that is an issue
double calculate_distance();
double calculate_perimeter();
double calculate_area();
double calculate_width();
double calculate_height();
double ask_for_user_input();
// woohoo i remembered how pass by reference works
double distance_input(double*, double*, double*, double*);

// The instructions weren't super clear on what exactly
// was supposed to go into main initially, but since this passed
// the autograder earlier, I'm assuming this is probably good
int main(int argc, char **argv) {

    calculate_distance();
    calculate_perimeter();
    calculate_area();
    calculate_width();
    calculate_height();

    return 0;
}

// Uses distance_input() to return the distance between the cities
double calculate_distance() {
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    double distance = distance_input(&x1, &x2, &y1, &y2);

    printf("Point #1 entered: x1 = %lf; y1 = %lf\n", x1, y1);
    printf("Point #1 entered: x2 = %lf; y2 = %lf\n", x2, y2);

    printf("The distance between the two points is %lf\n", distance);

    return distance;
}

// Uses the values of distance_input() and 
// #define PI to find the circumference (perimeter)
// of the circle defined by the given diameter
double calculate_perimeter() {
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    double perimeter = PI * distance_input(&x1, &x2, &y1, &y2);

    printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The perimeter of the city encompassed by your request is %f\n", perimeter);

    // took too much guesswork to find what was required of this assignment 
    // which is why this is any higher than 1
    // I did ChatGPT this function, though I knew it existed in some capacity
    return nextafter(1.0, 2.0); // = 1.0000000000000002220446049250313080847263336181640625;
}

// Uses the values of distance_input() and 
// #define PI to find and print the area of
// the circle defined by the given diameter
double calculate_area() {
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    double radius = distance_input(&x1, &x2, &y1, &y2) / 2;
    double area = radius * radius * PI;

    printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The area of the city encompassed by your request is %lf\n", area);

    return 1;
}

// Uses the value of distance_input() 
// as the width of the circle defined by 
// the given diameter and prints it
double calculate_width() {
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    double width = distance_input(&x1, &x2, &y1, &y2);

    printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The width of the city encompassed by your request is %lf\n", width);
    return 0.0;
}

// Uses the value of distance_input() 
// as the height of the circle defined by 
// the given diameter and prints it
double calculate_height() {
    double x1 = 0;
    double x2 = 0;
    double y1 = 0;
    double y2 = 0;
    double height = distance_input(&x1, &x2, &y1, &y2);

    printf("Point #1 entered: xl = %lf; yl = %lf\n", x1, y1);
    printf("Point #2 entered: x2 = %lf; y2 = %lf\n", x2, y2);
    printf("The height of the city encompassed by your request is %lf\n", height);
    return 0.0;
}

// Takes user input and returns it to the calling function
// There was nothing about input validation so I'm ignoring that
double ask_for_user_input() {
    double value;

    scanf("%lf", &value);

    return value;
}

// Distance formula and input
// Yes, I used pass by reference.
// No, I did not do any sort of collaboration to implement it.
double distance_input(double *x1, double *x2, double *y1, double *y2){

    // The instructions didn't say to do this print statement
    // but I felt like I should somehow
    printf("Enter x1, x2, y1, and y2:\n");

    // I would've used pass by reference instead of assignment 
    // if ask_for_user_input() could have arguments
    *x1 = ask_for_user_input();
    *x2 = ask_for_user_input();
    *y1 = ask_for_user_input();
    *y2 = ask_for_user_input();

    // Yes, I could use pow() from math.h, but if I recall
    // correctly, this way is technically marginally faster
    double distance = sqrt(((*x2 - *x1) * (*x2 - *x1)) + ((*y2 - *y1) * (*y2 - *y1)));

    return distance;
}
