#include "matrix.h"

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

int sgn(double x){
    if(x < 0){
        return -1;
    }
    return 1;
}

double task01(double* a, int n, int m){
    int i = 0, j = 0;
    double sum = 0;
    double max_sum = 0;
    double tmp = 0;
    for(i = 0; i < n; ++i){
        sum = 0;
        for(j = 0; j < m; ++j){
            tmp = a[i * m + j];
            sum += sgn(tmp) * tmp;
        }
        if(sum > max_sum){
            max_sum = sum;
        }
    }
    return max_sum;
}

double task02(double* a, int n, int m){
    int i = 0, j = 0;
    double sum = 0;
    double max_sum = 0;
    double tmp = 0;
    for(j = 0; j < m; ++j){
        sum = 0;
        for(i = 0; i < n; ++i){
            tmp = a[i * m + j];
            sum += sgn(tmp) * tmp;
        }
        if(sum > max_sum){
            max_sum = sum;
        }
    }
    return max_sum;
}

double task03(double *a, double *b, double *x, int n, int m){
    int i = 0, j = 0;
    double res = 0;
    double sum = 0;
    for(i = 0; i < n; ++i){
        sum = 0;
        for(j = 0; j < m; ++j){
            sum += x[j] * a[i * m + j];
        }
        sum -= b[i];
        res += sgn(sum) * sum;
    }
    return res;
}

double task04(double *a, double *b, double *x, int n, int m){
    int i = 0, j = 0;
    double res = 0;
    double sum = 0;
    for(i = 0; i < n; ++i){
        sum = 0;
        for(j = 0; j < m; ++j){
            sum += x[j] * a[i * m + j];
        }
        sum -= b[i];
        if(res < sgn(sum) * sum){
            res = sgn(sum) * sum;
        }
    }
    return res;
}

double task05(double *a, double *b, int n, int m){
    int i = 0, j = 0, k = 0;
    double r = 0, tmp = 0;
    double res = 0;
    for(k = 0; k < n; ++k){
        r = 0;
        for(i = 0; i < n; ++i){
            tmp = 0;
            for(j = 0; j < m; ++j){
                tmp += a[k * m + j] * b[j * n + i];
            }
            r += tmp * sgn(tmp);
        }
        r--;
        if(res < r){
            res = r;
        }
    }
    return res;
}

double task06(double *a, double *b, int n, int m){
    int i = 0, j = 0, k = 0;
    double r = 0, tmp = 0;
    double res = 0;
    for(k = 0; k < n; ++k){
        r = 0;
        for(i = 0; i < n; ++i){
            tmp = 0;
            for(j = 0; j < m; ++j){
                tmp += a[i * m + j] * b[j * n + k];
            }
            r += tmp * sgn(tmp);
        }
        r--;
        if(res < r){
            res = r;
        }
    }
    return res;
}

double abs_(double x){
    if(sgn(x) < 0){
        return -x;
    }
    return x;
}

double task07(double* a, int n, int m){
    int i = 0, j = 0;
    double res = abs_(a[0]);
    double tmp = 0;
    for(j = 1; j < m; ++j){
        tmp = abs_(a[j]);
        if(res < tmp){
            res = tmp;
        }
    }
    for(i = 1; i < n - 1; ++i){
        tmp = abs_(a[j]);
        if(res < tmp){
            tmp = res;
        }
        for(j = 1; j < m - 1; ++j){
            a[i * m + j] =  (tmp = ((a[(i - 1) * m + j] + a[(i + 1) * m + j] + a[i * m + j - 1] + a[i * m + j + 1]) / 5));
            if(res < abs_(tmp)){
                res = abs_(tmp);
            }
        }
        tmp = abs_(a[i * m + m-1]);
        if (res < tmp){
            res = tmp;
        }
    }
    for (j = 0; j < m; j++) {	
        tmp =  abs_(a[(n - 1) * m + j]);	
		if (res < tmp){
            res = tmp;
        }
	}
    return res;
}

double task08(double* a, int n, int m){
    int i = 0, j = 0;
    double res = abs_(a[0]);
    double tmp = 0;
    for(j = 1; j < m; ++j){
        tmp = abs_(a[j]);
        if(res < tmp){
            res = tmp;
        }
    }
    for(i = n - 2; i > 0; --i){
        tmp = abs_(a[j]);
        if(res < tmp){
            tmp = res;
        }
        for(j = m - 2; j > 0; --j){
            a[i * m + j] =  (tmp = ((a[(i - 1) * m + j] + a[(i + 1) * m + j] + a[i * m + j - 1] + a[i * m + j + 1]) / 5));
            if(res < abs_(tmp)){
                res = abs_(tmp);
            }
        }
        tmp = abs_(a[i * m + m-1]);
        if (res < tmp){
            res = tmp;
        }
    }
    for (j = 0; j < m; j++) {	
        tmp =  abs_(a[(n - 1) * m + j]);	
		if (res < tmp){
            res = tmp;
        }
	}
    return res;
}

double task09(double* a, int n, int m){
    int i = 0, j = 0;
    double res = abs_(a[0]);
    double tmp = 0;
    for(j = 1; j < m; ++j){
        tmp = abs_(a[j]);
        if(res < tmp){
            res = tmp;
        }
    }
    for (i = 1; i < n - 1; ++i){
        tmp = abs_(a[j]);
        if(res < tmp){
            tmp = res;
        }
        for(j = m - 2; j > 0; --j){
            a[i * m + j] =  (tmp = ((a[(i - 1) * m + j] + a[(i + 1) * m + j] + a[i * m + j - 1] + a[i * m + j + 1]) / 5));
            if(res < abs_(tmp)){
                res = abs_(tmp);
            }
        }
        tmp = abs_(a[i * m + m-1]);
        if (res < tmp){
            res = tmp;
        }
    }
    for (j = 0; j < m; j++) {	
        tmp =  abs_(a[(n - 1) * m + j]);	
		if (res < tmp){
            res = tmp;
        }
	}
    return res;
}

double task10(double* a, int n, int m){
    int i = 0, j = 0;
    double res = abs_(a[0]);
    double tmp = 0;
    for(j = 1; j < m; ++j){
        tmp = abs_(a[j]);
        if(res < tmp){
            res = tmp;
        }
    }
    for(i = n - 2; i > 0; --i){
        tmp = abs_(a[j]);
        if(res < tmp){
            tmp = res;
        }
        for(j = 1; j < m - 1; ++j){
            a[i * m + j] =  (tmp = ((a[(i - 1) * m + j] + a[(i + 1) * m + j] + a[i * m + j - 1] + a[i * m + j + 1]) / 5));
            if(res < abs_(tmp)){
                res = abs_(tmp);
            }
        }
        tmp = abs_(a[i * m + m-1]);
        if (res < tmp){
            res = tmp;
        }
    }
    for(j = 0; j < m; j++) {	
        tmp =  abs_(a[(n - 1) * m + j]);	
		if (res < tmp){
            res = tmp;
        }
	}
    return res;
}

void swap_row(double* a, int m, int i, int j){
    int k = 0;
    double tmp = 0;
    double* ai = a + i * m;
    double* aj = a + j * m;
    for(k = 0; k < m; ++k){
        tmp = ai[k];
        ai[k] = aj[k];
        aj[k] = tmp;
    }
}

void swap_col(double* a, int n, int m, int i, int j){
    int k = 0;
    double tmp = 0;
    double* ai = a + i;
    double* aj = a + j;
    int ind = m * n;
    for(k = 0; k < ind; k += m){
        tmp = ai[k];
		ai[k] = aj[k];
 		aj[k] = tmp;
    }
}

double task11(double* a, int n, int m){
    int i = 0, j = 0;
    int pos_i = 0, pos_j = 0;
    double tmp = 0, res = 0;
    for(i = 0; i < n; ++i){
        for(j = 0; j < m; ++j){
            tmp = a[i * m + j];
            tmp = tmp * sgn(tmp);
            if(tmp > res){
                res = tmp;
                pos_i = i;
                pos_j = j;
            }
        }
    }
    swap_row(a, m, 0, pos_i);
    swap_col(a, n, m, 0, pos_j);
    return res;
}
