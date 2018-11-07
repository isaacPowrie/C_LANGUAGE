// Functions for Arc Calculation
// functions.c
// Isaac Powrie
// 2018-11-06

#include <stdio.h>

#include "theArc.h"

// Velocity
double velocity(int F, int m)
{
	double a, v;
	a = F / m;
	v = a * ACCTIME;

	return v;
}

// Calculate Square Root
double squrt(double num)
{
	int i = 0;
	double search, root, check;
	double first_sig = 1;

	search = num;
	if (search >= 1) {
		search /= DEC;
		while (search > 1) {
			search /= DEC;
			first_sig *= DEC;
		}
	} else if (search < 1) {
		while (search < 1) {
			search *= DEC;
			first_sig /= DEC;
		}
	} else {
		first_sig = 0;
	}

	search = first_sig;
	root = num;
	if (root * root != num && root > 1) {
		do {
			root -= search;
		} while (root * root > num);

		while (root * root != num && i < SIGDIG) {
			root += search;
			search /= DEC;
			i++;
			do {
				root -= search;
			} while (root * root > num);
		}
	} else {
		root = search;
		while (root * root < num) {
			root += search;
		}

		while (root * root != num && i < SIGDIG) {
			root -= search;
			search /= DEC;
			i++;
			do {
				root += search;
			} while (root * root < num);
		}
	}

	return root;
}

// Sine
double sineOf(int angle)
{
	double rads, expnt, diff, cur_val;
	int count, start, sign, i, denom;

	//Calculate Rads
	//
	rads = angle * PI / 180;

	//Calculate Sine
	//
	count = 1;
	start = 1;
	sign = 1;
	cur_val = 0;
	do {
		denom = 1;
		for (i = 1; i <= start; i++) {
			denom = denom * i;
		}
		expnt = 1;
		for (i = 1; i <= start; i++) {
			expnt = expnt * rads;
		}

		diff = sign * expnt / denom;
		cur_val += diff;

		sign = -1 * sign;
		start += 2;
		count += 1;
	} while (diff > ERROR || -diff > ERROR);

	// Round Output
	//
	cur_val = cur_val + (5 * ERROR / 10);
	cur_val = cur_val / ERROR;
	cur_val = (long long)cur_val;
	cur_val = cur_val * ERROR;

	return cur_val;
}

// Cosine
double cosineOf(int angle)
{
	double rads, expnt, diff, cur_val;
	int count, start, sign, i, denom;

	//Calculate Rads
	//
	rads = angle * PI / 180;

	//Calculate Sine
	//
	count = 1;
	start = 1;
	sign = 1;
	cur_val = 0;
	do {
		denom = 1;
		for (i = 1; i <= start; i++) {
			denom = denom * i;
		}
		expnt = 1;
		for (i = 1; i <= start; i++) {
			expnt = expnt * rads;
		}

		diff = sign * expnt / denom;
		cur_val += diff;

		sign = -1 * sign;
		start += 2;
		count += 1;
	} while (diff > ERROR || -diff > ERROR);

	// Calculate Cosine
	//
	cur_val = 1 - cur_val * cur_val;
	cur_val = squrt(cur_val);

	// Round Output
	//
	cur_val = cur_val + (5 * ERROR / 10);
	cur_val = cur_val / ERROR;
	cur_val = (long long)cur_val;
	cur_val = cur_val * ERROR;

	return cur_val;
}

// Assign Difference Values
void setChangeVars(double v, double sine, double cosine, double *dx, double *dy, double *dt)
{
	double yPerSec, xPerSec;

	yPerSec = v * cosine;
	xPerSec = v * sine;
	*dt = TIMESCALE;
	*dy = yPerSec * TIMESCALE;
	*dx = xPerSec * TIMESCALE;

	return;
}

// Deceleracte With Gravity
double decel(double dx, double dy, double v, double sine, double cosine)
{
	double grav, xPerSec, yPerSec;

	yPerSec = v * cosine;
	xPerSec = dx / TIMESCALE;
	xPerSec -= GRAV * TIMESCALE;

	dx = xPerSec * TIMESCALE;

	return dx;
}
