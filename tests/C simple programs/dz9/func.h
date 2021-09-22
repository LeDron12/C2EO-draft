#include <stdio.h>
#include <stdlib.h>
#include <math.h>

enum{
    ERROR_SUCCESS,
    ERROR_OPEN,
    ERROR_READ,
    ERROR_EQUAL,
};

int read_arrays(double*, double*, int, const char*);

double task01(double x0, int n, double* x, double* y);
double task02(double x0, int n, double* x, double* y);
double task03(double x0, int n, double* x, double* y);


double tsin(double x, double e);
double tcos(double x, double e);

double task05(double x, double e);
double task06(double x, double e);
double task07(double x, double e);
double task08(double x, double e);