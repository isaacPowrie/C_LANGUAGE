/*
File: prog_math.h
Creator: Isaac Powrie
Date: 2019-01-04

This file contains the header information for functionality
within the canal program which can be used by other programs,
spanning functionality in prog_math.c
*/

#ifndef PROG_MATH_H
#define PROG_MATH_H

//////////////////////////////////////
/* Function headers for prog_math.c */
//////////////////////////////////////

// sort a list of numbers from highest to lowest
void sort_nums(double obs[], int num_obs);

// determine product given exponenet and base
double exp(double base, int exp);

// determine square root of a double which returns a double
double sqrt(double square);

// determine range given minimum and maximum
double range(double max, double min);

// determine mean given array of numerical observations
double mean(double obs[], int num_obs);

// determine median given array of numerical observations
double median(double obs[], int num_obs);

// determine mode given array of numerical observations
double mode(double obs[], int num_obs);

// determine minimum given array of numerical observations
double min(double obs[], int num_obs);

// determine maximum given array of numerical observations
double max(double obs[], int num_obs);

// determine population variance given an array of numerical
// observations
double variance(double obs[], int num_obs);

// determine population standard deviation given an array of
// numerical observations
double stddev(double obs[], int num_obs);

// determine sample variance given an array of numerical observations
double s_variance(double obs[], int num_obs);

// determine sample standard deviation given an array of numerical observations
double s_stddev(double obs[], int num_obs);

#endif