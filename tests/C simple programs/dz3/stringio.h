#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stddef.h>

#define ERROR_OPEN (-1)
#define ERROR_READ (-2)
#define ERROR_MEM (-3)
#define ERROR_SUCCESS (0)
#define LEN 2000

int strcmp_ (const char *s1, const char * s2);
size_t strlen_ (const char *string);

char *strcpy_ (char *, const char *);
void print_array(char **, int , int);
void free_array(char **, int );
int read_array(char **, int , const char *);