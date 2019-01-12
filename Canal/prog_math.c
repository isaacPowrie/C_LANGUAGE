/*
File: prog_math.c
Creator: Isaac Powrie
Date: 2019-01-04

This file contains general math functions for use in
the canal program. These functions are highly modular
and can be used in other programs if so desired.
*/

#include <stdio.h>
#include "window.h"
#include "prog_direction.h"
#include "prog_math.h"
#include "helpers.h"

// sort a list of numbers from highest to lowest
void sort_nums(double obs[], int num_obs) {
	int i, j, switch_index;
	double next_val, temp;

	for (i = num_obs - 1; i >= 0; i--) {
		next_val = min(obs, num_obs - i);
		if (obs[i] != next_val) {
			// find index of minimum value
			for (j = num_obs - i; j >= 0; j--) {
				if (obs[j] == next_val) {
					switch_index = j;
					j = -1;
				}
			}
			// switch minimum to place in sorted array
			temp = obs[i];
			obs[i] = next_val;
			obs[switch_index] = temp;
		}
	}
}

// determine product given exponenet and base
double exp(double base, int exp) {
	double power = 1.0;
	int i;

	for (i = 1; i <= exp; i++) {
		power *= base;
	}

	return power;
}

// determine square root of a double which returns a double
double sqrt(double square) {
	double est = 1;
	double dec_factor;
	int i;

	// determine est(imate) such that est - root <= 1
	while (est * est <= square) {
		est += 1;
	}
	est -= 1.0;

	// determine root to tenth decimal place
	for (i = 1; i <= 10; i++) {
		dec_factor = exp(10, i);
		while (est * est <= square) {
			est += 1.0 / dec_factor;
		}
		est -= 1.0 / dec_factor;
	}

	return est;
}

// determine minimum given array of numerical observations
double min(double obs[], int num_obs) {
	double min = obs[0];
	int i;
	for (i = 1; i < num_obs; i++) {
		if (obs[i] < min) {
			min = obs[i];
		}
	}

	return min;
}

// determine maximum given array of numerical observations
double max(double obs[], int num_obs) {
	double max = obs[0];
	int i;

	for (i = 1; i < num_obs; i++) {
		if (obs[i] > max) {
			max = obs[i];
		}
	}

	return max;
}

// determine range given minimum and maximum
double range(double max, double min) {
	double range;

	range = max - min;

	return range;
}

// determine mean given array of numerical observations
double mean(double obs[], int num_obs) {
	double total = 0;
	double mean;
	int i;

	for (i = 0; i < num_obs; i++) {
		total += obs[i];
	}

	mean = total / num_obs;

	return mean;
}

// determine median given array of numerical observations
double median(double obs[], int num_obs) {
	double median;
	int median_index = num_obs / 2;

	sort_nums(obs, num_obs);

	if (num_obs % 2 != 0) {
		median = obs[median_index];
	} else {
		median = obs[median_index] + obs[median_index - 1];
		median /= 2;
	}

	return median;
}

// determine mode given array of numerical observations
double mode(double obs[], int num_obs) {
	double mode;
	double last_ob;
	int i, mode_index;
	int count = 1;
	int max_count = 0;

	sort_nums(obs, num_obs);

	last_ob = obs[0];
	mode_index = 0;
	for (i = 1; i < num_obs; i++) {
		if (obs[i] == last_ob) {
			count += 1;
		} else {
			if (max_count < count) {
				max_count = count;
				mode_index = i;
			}
			count = 1;
			last_ob = obs[i];
		}
	}
	mode = obs[mode_index];

	return mode;
}

// determine population variance given an array of numerical
// observations
double variance(double obs[], int num_obs) {
	double variance = 0;
	double loc_mean, diff, square;
	int i;

	loc_mean = mean(obs, num_obs);
	for (i = 0; i < num_obs; i++) {
		diff = obs[i] - loc_mean;
		square = diff * diff;
		variance += square;
	}
	variance /= num_obs;

	return variance;
}

// determine population standard deviation given an array of
// numerical observations
double stddev(double obs[], int num_obs) {
	double stddev, loc_var;
	loc_var = variance(obs, num_obs);
	stddev = sqrt(loc_var);

	return stddev;
}

// determine sample variance given an array of numerical observations
double s_variance(double obs[], int num_obs) {
	double variance = 0;
	double loc_mean, diff, square;
	int i;

	loc_mean = mean(obs, num_obs);
	for (i = 0; i < num_obs; i++) {
		diff = obs[i] - loc_mean;
		square = diff * diff;
		variance += square;
	}
	variance /= num_obs - 1;

	return variance;
}

// determine sample standard deviation given an array of numerical observations
double s_stddev(double obs[], int num_obs) {
	double stddev, loc_var;
	loc_var = s_variance(obs, num_obs);
	stddev = sqrt(loc_var);

	return stddev;
}