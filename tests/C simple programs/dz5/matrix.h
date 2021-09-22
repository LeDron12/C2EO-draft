#include <stdio.h>
#include <stdlib.h>

enum{
	READ_SUCCESS,
	READ_ERR_OPEN,
	READ_ERR_READ
};

double f(int, int, int, int, int);

void init_matrix(double*, int, int, int);
int read_matrix(double*, int, int, const char*);
void print_matrix(double*, int, int, int);

int sgn(double x);
double abs_(double x);
void swap_col(double* a, int n, int m, int i, int j);
void swap_row(double* a, int m, int i, int j);

double task01(double *, int, int);
double task02(double *, int, int);
double task03(double *, double *, double *, int , int);
double task04(double *, double *, double *, int , int);
double task05(double *, double *, int , int);
double task06(double *, double *, int , int);
double task07(double *, int, int);
double task08(double *, int, int);
double task09(double *, int, int);
double task10(double *, int, int);
double task11(double *, int, int);