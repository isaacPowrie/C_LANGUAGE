// Functions for Arc Calculation
// functions.h
// Isaac Powrie
// 2018-10-16

#define GRAV 9.8
#define PI 3.14159
#define ACCTIME 3

#define ERROR 0.00000000001
#define TIMESCALE 1

// Velocity
double velocity(int F, int m)
{
	double a, v;
	a = F / m;
	v = a * ACCTIME;

	return v;
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

	// Round Output
	//
	cur_val = cur_val + (5 * ERROR / 10);
	cur_val = cur_val / ERROR;
	cur_val = (long long)cur_val;
	cur_val = cur_val * ERROR;

	return cur_val;
}

// Assign Difference Values
void setChangeVars(double v, double sine, double cosine, double *dx, double *dy)
{
	double yPerSec, xPerSec;

	yPerSec = v * cosine;
	xPerSec = v * sine;
	*dy = TIMESCALE;
	*dx = (xPerSec / yPerSec) * TIMESCALE;

	return;
}

// Deceleracte With Gravity
double decel(double dx, double dy, double v, double sine, double cosine)
{
	double grav, xPerSec, yPerSec;

	yPerSec = v * cosine;
	xPerSec = (dx * yPerSec) / TIMESCALE;
	xPerSec -= GRAV * TIMESCALE;

	dx = (xPerSec / yPerSec) * TIMESCALE;

	return dx;
}
