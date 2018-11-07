// Header file for Arc Calculation
// theArc.h
// Isaac Powrie
// 2018-10-16

#define GRAV 9.8
#define PI 3.14159
#define ACCTIME 3

#define ERROR 0.00000000001
#define TIMESCALE 0.0001

#define DEC 10
#define SIGDIG 14

// Velocity
double velocity(int F, int m);

// Calculate Square Root
double squrt(double num);

// Sine
double sineOf(int angle);

// Cosine
double cosineOf(int angle);

// Assign Difference Values
void setChangeVars(double v, double sine, double cosine, double *dx, double *dy, double *dt);

// Deceleracte With Gravity
double decel(double dx, double dy, double v, double sine, double cosine);
