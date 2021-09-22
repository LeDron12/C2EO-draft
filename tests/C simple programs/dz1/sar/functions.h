#include <stdio.h>

size_t strlen_(const char *s);
char *strstr_ (const char *string1, const char *string2);
char *strstr_p_ (const char *string1, const char *string2, int(*cmp)(char, const char*, size_t*));
char *strstr_begin_ (const char *string1, const char *string2, int(*cmp)(char, const char*, size_t*));
char *strstr_end_ (const char *string1, const char *string2, int(*cmp)(char, const char*, size_t*));
char *strstr_word_3 (const char *string1, const char *string2, int *del);
char *strstr_word_4 (const char *string1, const char *string2, int *del);
int str_word_eq (const char *string1, const char *string2, int *del);

int cmp_1(char a, const char *s, size_t *j);
int cmp_2(char a, const char *s, size_t *j);

int f1(const char *f_in, const char *f_out, const char* str);
int f2(const char *f_in, const char *f_out, char* str);
int f3(const char *f_in, const char *f_out, const char* str, const char* tr);
int f4(const char *f_in, const char *f_out, char* str, const char* tr);
int f5(const char *f_in, const char *f_out, const char* str, const char* tr);
