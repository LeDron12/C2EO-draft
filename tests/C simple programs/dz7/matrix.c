#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "matrix.h"
const double epsilon = 1.0e-15;

double f(int k, int n, int m, int i, int j){
    switch (k)
        {
            case 1:
                return ((n > m ? n : m) - (i > j ? i : j) + 1);
            case 2:
                return (i > j ? i : j);
            case 3:
                return (i > j ? i - j : j - i); 
            case 4:
                return (1.0 / (i + j - 1));
        }
    return 0;
}

void init_matrix (double* a, int n, int m, int k){
    int i = 0, j = 0;
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            a[i * m + j] = f(k, n, m, i + 1, j + 1);
        }
    }
}

int read_matrix(double* a, int n, int m, const char* name){
    FILE* fp;
    int i = 0, j = 0;
    if(!(fp = fopen(name, "rt"))){
        return READ_ERR_OPEN;
    }
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            if(fscanf(fp, "%lf", a + i * m + j) != 1){
                fclose(fp);
                return READ_ERR_READ;
            }
        }
    }
    fclose(fp);
    return READ_SUCCESS;
}

void print_matrix (double* a, int n, int m, int p)
{
	int n1 = (n > p ? p : n);
	int m1 = (m > p ? p : m);
	int i = 0, j = 0;
	for (i = 0; i < n1; ++i){
        for(j = 0; j < m1; ++j){
            printf(" %10.3e", a[i * m + j]);
        }
        printf("\n");
	}
}

void mult1(double* a, double* x, double* x1, int n){
    double* addr;
    int i,j;
    for(i = 0; i < n; ++i){
        addr = a + i * n;
        x1[i] = 0;
        for(j = 0; j < n; ++j){
            x1[i] += addr[j] * x[j];
        }
    }
}

double scalar(double* x, double* x1, int n){
    double res = 0;
    for(int i = 0; i < n; ++i){
        res += x[i] * x1[i];
    }
    return res;
}

double r2_1(double* a, double* x, int n, double r1){
    double tmp;
    double sum1 = 0, sum2 = 0;
    double res = 0;
    int i,j;
    double* addr;
    for(i = 0; i < n; ++i){
        addr = a + i * n;
        tmp = 0;
        for(j = 0; j < n; ++j){
            tmp += addr[j] * x[j];
        }
        tmp -= r1 * x[i];
        sum1 += fabs(tmp);
        sum2 += fabs(x[i]);
    }
    res = sum1 / sum2;
    return res;
}

double task01(double* a, double* x0, double* x, int n, int m){
    double* tmp;
    double* init = x;
    double denum = 0;
    double res = 0;
    for(int i = 0; i <= m; ++i){
        mult1(a, x0, x, n);
        tmp = x0;
        x0 = x;
        x = tmp;
    }
    denum = scalar(x, x, n);
    if(denum > 0 || denum < 0){
        res = scalar(x0, x, n) / denum;
    }
    tmp = x;
	x = x0;
    x0 = tmp;
	if (x != init) {
		for(int i = 0; i < n; i++) {
			init[i] = x[i];
		}
	}
    return res;
}

double f_r1(double* a, double* b, double* x, int n){
    int i,j;
    double tmp;
    double sum1 = 0, sum2 = 0;
    double* addr;
    for(i = 0; i < n; ++i){
        tmp = 0;
        addr = a + i * n;
        for(j = 0; j < n; ++j){
            tmp += addr[j] * x[j];
        }
        tmp -= b[i];
        sum1 += fabs(tmp);
        sum2 += fabs(b[i]);
    }
    return (sum1 / sum2);
}

double f_r2(double* x, int n){
    int i;
    double tmp = 0;
    for(i = 0; i < n; ++i){
        tmp += fabs(x[i] - ((i + 1) & 1));
    }
    return tmp;
}

void mult2(double* a, double* x0, double* x, int n){
    int i,j;
    double* addr;
    double tmp;
    for(i = 0; i < n; ++i){
        addr = a + i * n;
        tmp = 0;
        for(j = 0; j < n; ++j){
            tmp += addr[j] * x0[j];
        }
        x[i] = tmp;
    }
}

void make_b(double* a, double* b, int n){
    int i, j;
    double* addr;
    double tmp;
    for(i = 0; i < n; ++i){
        addr = a + i * n;
        tmp = 0;
        for(j = 0; j < n; j += 2){
            tmp += addr[j];
        }
        b[i] = tmp;
    }
}

void task02(double* a, double *b, double* x, double* x0, int n, int m, double t){
    int i, j;
	double *tmp = x; 
    double* init = x;
	for(i = 0; i < m; ++i){
		mult2(a, x0, x, n);
		for(j = 0; j < n; ++j){
			x[j] = (b[j] - x[j]) * t + x0[j];
		}
		tmp = x;
		x = x0;
		x0 = tmp;
	}
	tmp = x;
	x = x0;
    x0 = tmp;
	if (x != init) {
		for(i = 0; i < n; i++) {
			init[i] = x[i];
		}
	}
}


void task03(double* a, double* b, double* x, double* x0, double* r, int m, int n){
    int i, j;
    double numer, denom;
    double norm = 0;
    double eps = 0;
    double t = 0;
    mult2(a, x0, x, n);
    for(i = 0; i < n; ++i){
        double tmp = b[i];
        norm += fabs(tmp);
        r[i] = x[i] - tmp;
        x[i] = x0[i];
    }
    eps = epsilon * epsilon * norm * norm;
    for(i = 0; i < m; ++i){
        numer = 0;
        denom = 0;
        mult2(a, r, x0, n);
        for(j = 0; j < n; ++j){
            double tmp1 = r[j];
            double tmp2 = x0[j];
            numer += tmp1 * tmp1;
            denom += tmp1 * tmp2;
        }
        if(fabs(numer) < eps || fabs(denom) < eps){
            break;
        }
        t = numer / denom;
        for(j = 0; j < n; ++j){
            x[j] -= t * r[j];
            r[j] -= t * x0[j];
        }
    }
}

void task04(double* a, double* b, double* x, double* x0, double* r, int m, int n){
    int i, j;
    double numer, denom;
    double norm = 0;
    double eps = 0;
    double t = 0;
    mult2(a, x0, x, n);
    for(i = 0; i < n; ++i){
        double tmp = b[i];
        norm += fabs(tmp);
        r[i] = x[i] - tmp;
        x[i] = x0[i];
    }
    eps = epsilon * epsilon * norm * norm * norm;
    for(i = 0; i < m; ++i){
        numer = 0;
        denom = 0;
        mult2(a, r, x0, n);
        for(j = 0; j < n; ++j){
            double tmp1 = r[j];
            double tmp2 = x0[j];
            numer += tmp1 * tmp2;
            denom += tmp2 * tmp2;
        }
        if(fabs(numer) < eps || fabs(denom) < eps){
            break;
        }
        t = numer / denom;
        for(j = 0; j < n; ++j){
            x[j] -= t * r[j];
            r[j] -= t * x0[j];
        }
    }
}

int equal_zero(double x){
    if(x < 0 || x > 0){
        return 0;
    }
    return 1;
}

void task05(double* a, double* b, double* x, double* x0, double* r, int m, int n){
    int i, j;
    double numer, denom;
    double norm = 0;
    double eps = 0;
    double t = 0;
    double tmp;
    for(i = 0; i < n; ++i){
        tmp = a[i * n + i];
        if(equal_zero(tmp) == 1){
            return;
        }
    }
    for(i = 0; i < n; ++i){
        x[i] = x0[i];
    }

    mult2(a, x, x0, n);
    for(i = 0; i < n; ++i){
        tmp = b[i];
        r[i] = (x0[i] - tmp);
        norm += fabs(b[i]);
    }
    eps = epsilon * epsilon * norm * norm;
    for(i = 0; i < m; ++i){
        numer = 0;
        denom = 0;
        for(j = 0; j < n; ++j){
           numer += r[j] *  (x0[j] = r[j] / a[j * n + j]);
        }
        mult2(a, x0, r, n);
        for(j = 0; j < n; ++j){
            denom += x0[j] * r[j];
        }
        if(fabs(numer) < eps || fabs(denom) < eps){
            break;
        }
        t = numer / denom;
        for (j = 0; j < n; ++j){
			x[j] -= t * x0[j];	
			x0[j] *= a[j * n + j];				
			r[j] = x0[j] - t * r[j];
        }
    }
}

void task06(double* a, double* b, double* x, double* x0, double* r, int m, int n){
    int i, j;
    double numer, denom;
    double norm = 0;
    double eps = 0;
    double t = 0;
    double tmp1, tmp2;
    for(i = 0; i < n; ++i){
        tmp1 = a[i * n + i];
        if(equal_zero(tmp1) == 1){
            return;
        }
    }
    for(i = 0; i < n; ++i){
        x[i] = x0[i];
    }
    mult2(a, x, x0, n);
    for(i = 0; i < n; ++i){
        tmp1 = b[i];
        norm += fabs(tmp1);
        r[i] = x0[i] - tmp1;
    }
    eps = epsilon * epsilon * norm * norm;
    for(i = 0; i < m; ++i){
        numer = 0;
        denom = 0;
        for(j = 0; j < n; ++j){
            r[j] /= a[j * n + j];
        }
        mult2(a, r, x0, n);
        for(j = 0; j < n; ++j){
            tmp1 = (r[j] *= a[j * n + j]);
            tmp2 = x0[j];
            numer += tmp1 * tmp2;
            denom += tmp2 * tmp2;
        }
        if(fabs(numer) < eps || fabs(denom) < eps){
            break;
        }
        t = numer / denom;
        for(j = 0; j < n; ++j){
            x[j] -= t * (r[j] / a[j * n + j]);
            r[j] -= t * x0[j];
        }
    }
}

void task07(double* a, double* b, double* x, double* x0, double* r, int m, int n, double t){
    int i, j;
    double tmp;
    for(i = 0; i < n; ++i){
        tmp = a[i * n + i];
        if(equal_zero(tmp) == 1){
            return;
        }
    }
    for(i = 0; i < n; ++i){
        x[i] = x0[i];
    }
    mult2(a, x, x0, n);
    for(i = 0; i < n; ++i){
        r[i] = x0[i] - b[i];
    }
    for(i = 0; i < m; ++i){
        for(j = 0; j < n; ++j){
            x0[j] = r[j] / a[j * n + j];
        }
        mult2(a, x0, r, n);
        for (j = 0; j < n; ++j){
			x[j] -= t * x0[j];			
			r[j] = x0[j] * a[j * n + j] - t * r[j];
        }
    }
}

