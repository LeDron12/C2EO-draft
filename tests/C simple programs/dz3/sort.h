#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int cmp_len_inc(char*, char*);
int cmp_len_dec(char*, char*);
int cmp_lex_inc(char*, char*);
int cmp_lex_dec(char*, char*);

int sort01(char ** a, int n, char * x, int (*cmp)(char *, char *));
void sort02(char ** a, char ** b, char ** c, int n, int m, int (*cmp)(char *, char *));
int sort03(char ** a, int n, char * x, int (*cmp)(char *, char *));
void sort04(char** a, int n, int (*cmp) (char*, char*));
void sort05(char** a, int n, int (*cmp) (char*, char*));
void sort06(char** a, int n, int (*cmp) (char*, char*));
void sort07(char** a, int n, int (*cmp) (char*, char*));
void sort08(char** a, char** b, int n, int (*cmp) (char*, char*));
int sort03_1(char ** a, int n, char * x, int (*cmp)(char *, char *));
void sort09(char** a, int n, int (*cmp) (char*, char*));