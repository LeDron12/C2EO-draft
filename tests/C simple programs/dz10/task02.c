#include <time.h>
#include <stdio.h>

#include "func.h"

#define TASK_NUM 2

int main(int argc, char *argv[]) {
    double x0 = 0, e = 0;
    int k = 0;
    double x = 0;
    double (*f)(double);
    double (*df)(double);
    double res = 0;
    double t = 0;
    int count_iter = 0, count_f = 0;

    if (!(argc == 4 && sscanf(argv[1], "%lf", &x0) == 1 
        && sscanf(argv[2], "%lf", &e) == 1
        && sscanf(argv[3], "%d", &k) == 1 && e > 0
        && e > 0)){
            printf("Usage: %s a b e k\n", argv[0]);
            return 1;
    }

    switch (k){
        case 0: 
            f = f0;
            df = df0;
            break;
        case 1: 
            f = f1;
            df = df1;
            break;
        case 2: 
            f = f2; 
            df = df2;
            break;
        case 3: 
            f = f3; 
            df = df3;
            break;
        case 4: 
            f = f4; 
            df = df4;
            break;
        case 5: 
            f = f5; 
            df = df5;
            break;
        case 6: 
            f = f6; 
            df = df6;
            break;
        default: 
            printf("Wrong k\n");
            return 2;
    }

    t = clock();
    count_iter = task02(f, df, x0, e, &x);
    t  = (clock() - t);

    if (count_iter < 0){
        printf("Root was not found\n");
        return 3;
    }
    count_f = getCount();

    res = (*f)(x);

    printf ("%s : Task = %d X = %e Res = %e Its = %d Count = %d T = %.2f\n", argv[0], TASK_NUM, x, res, count_iter, count_f, t);
    return 0;
}

