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
            printf("%10.2e", a[i * m + j]);
        }
        printf("\n");
	}
}



int task01(double* a, int n){
    int i = 0, j = 0;
    for(i = 0; i < n ; ++i){
        for(j = 0; j < i; ++j){
            if (a[i * n + j] < a[j * n + i] || a[i * n + j] > a[j * n + i]){
                return 0;
            }
        }
    }
    return 1;
}

double task02(double* a, int n){
    double trace = 0;
    for(int i = 0; i < n; ++i){
        trace += a[i * n + i];
    }
    return trace;
}

void task03(double* a, int n){
    double tmp = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; ++i){
        for(j = 0; j < i; ++j){
            tmp = a[i * n + j];
            a[i * n + j] = a[j * n + i];
            a[j * n + i] = tmp;
        }
    }
}


void task04(double* a, int n){
    double tmp = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; ++i){
        for(j = 0; j < i; ++j){
            tmp = (a[i * n + j] + a[j * n + i]) / 2;
            a[i * n + j] = tmp;
            a[j * n + i] = tmp;
        }
    }
}

void task05(double* a, int n){
    double tmp = 0;
    int i = 0, j = 0;
    for(i = 0; i < n; ++i){
        for(j = 0; j < i; ++j){
            tmp = (a[i * n + j] - a[j * n + i]) / 2;
            a[i * n + j] = tmp;
            a[j * n + i] = -tmp;
        }
    }
    for(i = 0; i < n; ++i){
        a[i * n + i] = 0;
    }
}

void task06(double* a, int m, int i, int j){
    int k = 0;
    double tmp = 0;
    i--;
    j--;
    for(k = 0; k < m; ++k){
        tmp = a[i * m + k];
        a[i * m + k] = a[j * m + k];
        a[j * m + k] = tmp;
    }
}

void task07(double* a, int n, int m, int i, int j){
    int k = 0;
    double tmp = 0;
    i--;
    j--;
    for(k = 0; k < n; ++k){
        tmp = a[k * m + i];
		a[k * m + i] = a[k * m + j];
		a[k * m + j] = tmp;
    }
}

void task08(double* a, int m, int i, int j, double g){
    int k = 0;
    i--;
    j--;
    for(k = 0; k < m; ++k){
        a[j * m + k] += g * a[i * m + k];
    }
}

void task09(double* a, double* b, double* c, int n, int m){
    int i = 0;
    int j = 0;
    double sum;
    for(i = 0; i < n; ++i){
        sum = 0;
        for(j = 0; j < m; ++j){
            sum += a[i * m + j] * b[j];
        }
        c[i] = sum;
    }
}

void task10(double* a, double* b, double* c, int n, int m, int k){
    int i = 0;
    int j = 0;
    for(i = 0; i < n; ++i){
        for(j = 0; j < k; ++j){
            int l = 0;
            double sum = 0;
            for(l = 0; l < m; ++l){
                sum += a[i * m + l] * b[l * k + j];
            }
            c[i * k + j] = sum;
        }
    }
}
