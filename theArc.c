// Calculates the Arc of a Projectile
// theArc.c
// Isaac Powrie
// 2018-10-16

#include <stdio.h>
#include "functions.h"

/* #define GRAV 9.8
#define PI 3.14159
#define ACCTIME 3

#define ERROR 0.00000000001
#define TIMESCALE 0.01 */

int main(void)
{
	int angle, m, F;
	double sine, cosine, v, dy, dx;
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
		setChangeVars(v, sine, cosine, &dx, &dy);
	}

	// Calculate Points of Arc
	{
		do {
			printf("(%lf, %lf) ", height, distance);
			dx = decel(dx, dy, v, sine, cosine);
			height += dx;
			distance += dy;
			maxHeight = maxHeight < height ? height : maxHeight;
		} while (height >= 0);
	}

	printf("\nTotal Distance: %.2lf\n", distance);
	printf("\nMaximum Height: %.2lf\n", maxHeight);

	return 0;
}
