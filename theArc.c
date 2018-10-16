// Calculates the Arc of a Projectile
// theArc.c
// Isaac Powrie
// 2018-10-16

#include <stdio.h>
#include "functions.h"

#define GRAV 9.8
#define PI 3.14159
#define ACCTIME 3

#define ERROR 0.00000000001
#define TIMESCALE 1

int main(void)
{
  int angle, m, F;
  double sine, cosine, x, y, v, dy, dx, secs;
  double height = 0;
  double distance = 0;
  double maxHeight = 0;

  // Initialize User Inputs
  {
    printf("What is the mass of the projectile? ");
    scanf("%d", &m);

    printf("\n What is the force of the acceleration? ");
    scanf("%d", &F);

    printf("\n What is the angle of trajectory (degrees)? ");
    scanf("%d", &angle);
  }

  // Prelimenary Calculations
  {
    v = velocity(F, m);
    sine = sineOf(angle);
    cosine = cosineOf(angle);
    setChangeVars(v, sine, cosine, &dx, &secs);
  }

  // Calculate Points of Arc
  {
    do {
      printf("(%lf, %lf) ", height, distance);
      height += dx;
      distance+= TIMESCALE;
      maxHeight = maxHeight < height ? height : maxHeight;
      dx = Decel(dx, secs);
    } while (height >= 0);
  }

  printf("\nTotal Distance: %.2lf\n", distance);
  printf("\nMaximum Height: %.2lf\n", maxHeight);

  return 0;
}
