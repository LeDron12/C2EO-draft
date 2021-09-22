#include "functions.h"

#include <stdio.h>
#include <stdlib.h>

#define LEN 1001

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

int cmp_1(char a, const char *s, size_t *j) {
    if (a == '^') {
        if (s[0] == '\\' && s[1] == '^') {
            *j = *j + 1;
            return 1;
        }
        else return 0;
    }
    if (a == '\\') {
        if (s[0] == '\\' && s[1] == '\\') {
            *j = *j + 1;
            return 1;
        }
        else return 0;
    }
    if (a == s[0]) {
        return 1;        
    }
    return 0;
}
int cmp_2(char a, const char *s, size_t *j) {
    if (a == '$') {
        if (s[0] == '\\' && s[1] == '$') {
            *j = *j + 1;
            return 1;
        }
        else return 0;
    }
    if (a == '\\') {
        if (s[0] == '\\' && s[1] == '\\') {
            *j = *j + 1;
            return 1;
        }
        else return 0;
    }
    if (a == s[0]) {
        return 1;        
    }
    return 0;
}

size_t strlen_(const char *s) {
    size_t i = 0;
    while (s[i]) i++;
    return i;
}
char *strstr_ (const char *string1, const char *string2) {
    size_t i, j;
    if (!string2[0]) return (char*)(string1);
    for (i = 0; string1[i]; i++) {
        if (string1[i] == string2[0]) {
            for (j = 0; string2[j] && string1[i + j] == string2[j]; j++); 
            if (string2[j] == 0)
                return (char*)(string1 + i);
        }
    }
    return 0;
}
char *strstr_p_ (const char *string1, const char *string2, int(*cmp)(char, const char*, size_t*)) {
    size_t i, j, h;
    if (!string2[0]) return (char*)(string1);
    for (i = 0; string1[i]; i++) {
        j = 0; h = 0;
        if (cmp(string1[i], string2, &j)) {
            for (j = 0, h = 0; string2[j] && cmp(string1[i + h], string2 + j, &j); j++, h++);
            if (string2[j] == 0) 
                return (char*)(string1 + i);
        }
    }
    return 0;
}
char *strstr_begin_ (const char *string1, const char *string2, int(*cmp)(char, const char*, size_t*)) {
    size_t i = 0, j, h;
    for (j = 0, h = 0; string2[j] && cmp(string1[i + h], string2 + j, &j); j++, h++);
    if (string2[j] == 0) 
        return (char*)(string1 + i);
    return 0;
}
char *strstr_end_ (const char *string1, const char *string2, int(*cmp)(char, const char*, size_t*)) {
    size_t i, j, h;
    if (!string2[0]) return (char*)(string1);
    for (i = 0; string1[i]; i++) {
        j = 0; h = 0;
        if (cmp(string1[i], string2, &j)) {
            for (j = 0, h = 0; string2[j] && cmp(string1[i + h], string2 + j, &j); j++, h++); 
            if (string1[i + h] == 0 && string2[j] == 0)
                return (char*)(string1 + i);
        }
    }
    return 0;
}
char *strstr_word_3 (const char *string1, const char *string2, int *del) {
    size_t i, j;
    if (!string2[0]) return (char*)(string1);
    for (i = 0; string1[i]; ) {
        for ( ; string1[i] && (del[string1[i] >> 5]) & (1 << (string1[i] & 31)); i++);
        if (string1[i] == string2[0]) {
            for (j = 0; string2[j] && string1[i + j] == string2[j]; j++);
            if (string2[j] == 0) 
                return (char*)(string1 + i);
        }
        for ( ; string1[i] && !( (del[string1[i] >> 5]) & (1 << (string1[i] & 31)) ); i++);
    }
    return 0;
}
char *strstr_word_4 (const char *string1, const char *string2, int *del) {
    size_t i, j;
    if (!string2[0]) return (char*)(string1);
    for (i = 0; string1[i]; i++) {
        if (string1[i] == string2[0]) {
            for (j = 0; string2[j] && string1[i + j] == string2[j]; j++);
            if (string2[j] == 0 && ((del[string1[i + j] >> 5]) & (1 << (string1[i + j] & 31)) || string1[i + j] == 0)) 
                return (char*)(string1 + i);
        }
    }
    return 0;
}
int str_word_eq (const char *string1, const char *string2, int *del) {
    size_t i, j, h; 
    if (!string2[0]) return 0;
    for (i = 0; string1[i]; ) {
        for ( ; string1[i] && (del[string1[i] >> 5]) & (1 << (string1[i] & 31)); i++);
        for (j = 0; string2[j]; ) {
            for ( ; string2[j] && (del[string2[j] >> 5]) & (1 << (string2[j] & 31)); j++);  
            if (string1[i] == string2[j] && string1[i]) {
                for (h = 0; string2[j + h] && !((del[string2[j + h] >> 5]) & (1 << (string2[j + h] & 31))) && string1[i + h] == string2[j + h]; h++);
                if ( (((del[string2[j + h] >> 5]) & (1 << (string2[j + h] & 31))) || !string2[j + h]) && (((del[string1[i + h] >> 5]) & (1 << (string1[i + h] & 31))) || !string1[i + h]) )
                    return 1;
            }
            for ( ; string2[j] && !((del[string2[j] >> 5]) & (1 << (string2[j] & 31))); j++);      
        }
        for ( ; string1[i] && !((del[string1[i] >> 5]) & (1 << (string1[i] & 31))); i++);
    }
    return 0;
}
int f1(const char *f_in, const char *f_out, const char* str) {
    FILE *fin, *fout;
    int i, k = 0;
    char buf[LEN];
    int (*cmp)(char, const char*, size_t*);

    cmp = cmp_1;
    fin = fopen(f_in, "r");
    fout = fopen(f_out, "w");

    if (!fin || !fout) 
        return -1;
    while (fgets(buf, LEN, fin)) {
        for (i = 0; buf[i]; i++) {
            if (buf[i] == '\n') {
                buf[i] = 0;
                break;
            }
        }
        
        if (str[0] == '^') {
            if (strstr_begin_(buf, str + 1, cmp)) {
                fprintf(fout, "%s\n", buf);
                k++;
            }
        }
        else {
            if (strstr_p_(buf, str, cmp)) {
                fprintf(fout, "%s\n", buf);
                k++;
            }
        }
    }
    if (!feof(fin)) {
        fclose(fin);
        fclose(fout);
        return -2;
    }
    fclose(fin);
    fclose(fout);
    return k;
}
int f2(const char *f_in, const char *f_out, char* str) {
    FILE *fin, *fout;
    int i, k = 0, k_s = 0;
    size_t len_s = strlen_(str);
    char buf[LEN];
    char end_s = str[len_s - 1];
    int (*cmp)(char, const char*, size_t*);

    cmp = cmp_2;
    fin = fopen(f_in, "r");
    fout = fopen(f_out, "w");

    if (!fin || !fout) 
        return -1;
    if (end_s == '$') {
        for (i = len_s - 2; i >= 0 && str[i] == '\\'; i--, k_s++);
        if (k_s % 2 == 0) {
            str[len_s - 1] = 0;
            while (fgets(buf, LEN, fin)) {
                for (i = 0; buf[i]; i++) {
                    if (buf[i] == '\n') {
                        buf[i] = 0;
                        break;
                    }
                }
                if (strstr_end_(buf, str, cmp)) {
                    fprintf(fout, "%s\n", buf);
                    k++;
                }         
            }  
            if (!feof(fin)) {
                fclose(fin);
                fclose(fout);
                return -2;
            }
            fclose(fin);
            fclose(fout);
            return k;
        }
    }
    while (fgets(buf, LEN, fin)) {
        for (i = 0; buf[i]; i++) {
            if (buf[i] == '\n') {
                buf[i] = 0;
                break;
            }
        }
        if (strstr_p_(buf, str, cmp)) {
            fprintf(fout, "%s\n", buf);
            k++;
        }
    }
    if (!feof(fin)) {
        fclose(fin);
        fclose(fout);
        return -2;
    }
    fclose(fin);
    fclose(fout);
    return k;
}
int f3(const char *f_in, const char *f_out, const char* str, const char* tr) {
    FILE *fin, *fout;
    int i, j, k = 0, flag = 0;
    char buf[LEN], s_copy[LEN];
    int del[8];

    for (i = 0; i < 8; i++) del[i] = 0;
    for (i = 0; tr[i]; i++) {
        del[tr[i] >> 5] |= (1 << (tr[i] & 31));
    }

    fin = fopen(f_in, "r");
    fout = fopen(f_out, "w");
    if (!fin || !fout) 
        return -1;

    s_copy[0] = 0;
    if (str[0] == '\\' && str[1] == '<') { 
        if (!((del[str[2] >> 5]) & (1 << (str[2] & 31)))) {
            flag = 1; i = 2; }
        else flag = -1;
    }
    else i = 0;
    for (j = 0; str[i]; i++, j++) {
        if (str[i] == '\\' && str[i + 1] == '<') {
            if ( ((del[str[i - 1] >> 5]) & (1 << (str[i - 1] & 31))) && (!((del[str[i + 2] >> 5]) & (1 << (str[i + 2] & 31))) && str[i + 2]) ) {
                s_copy[j] = str[i + 2];
                i += 2;            
            }
            else {
                flag = -1; break;
            }
        }
        else s_copy[j] = str[i];
    }
    s_copy[j] = 0;
    if (flag == -1) {
        fclose(fin); fclose(fout);
        return 0;
    }
    if (flag) {
        while (fgets(buf, LEN, fin)) {
            for (i = 0; buf[i]; i++) {
                if (buf[i] == '\n') {
                    buf[i] = 0;
                    break;
                }
            }
            if (strstr_word_3(buf, s_copy, del)) {
                fprintf(fout, "%s\n", buf);
                k++;
            }
        }
    }
    else {
        while (fgets(buf, LEN, fin)) {
            for (i = 0; buf[i]; i++) {
                if (buf[i] == '\n') {
                    buf[i] = 0;
                    break;
                }
            }
            if (strstr_(buf, s_copy)) {
                fprintf(fout, "%s\n", buf);
                k++;
            }
        }
    }
    if (!feof(fin)) {
        fclose(fin);
        fclose(fout);
        return -2;
    }
    fclose(fin);
    fclose(fout);
    return k;
}
int f4(const char *f_in, const char *f_out, char* str, const char* tr) {
    FILE *fin, *fout;
    int i, j, k = 0, flag = 0;
    char buf[LEN], s_copy[LEN];
    int del[8];

    for (i = 0; i < 8; i++) del[i] = 0;
    for (i = 0; tr[i]; i++) {
        del[tr[i] >> 5] |= (1 << (tr[i] & 31));
    }

    fin = fopen(f_in, "r");
    fout = fopen(f_out, "w");
    if (!fin || !fout) 
        return -1;

    s_copy[0] = 0;
    for (j = 0, i = 0; str[i]; i++, j++) {
        if (str[i] == '\\' && str[i + 1] == '>') {
            if (i == 0 || ((del[str[i - 1] >> 5]) & (1 << (str[i - 1] & 31))) || (!((del[str[i + 2] >> 5]) & (1 << (str[i + 2] & 31))) && str[i + 2])) {
                flag = -1; break; }
            else if (str[i + 2]) {
                s_copy[j] = str[i + 2];
                i += 2;
            }
            else {
                flag = 1; break; }
        }
        else s_copy[j] = str[i];
    }
    s_copy[j] = 0;
    if (flag == -1) {
        fclose(fin); fclose(fout);
        return 0;
    }
    if (flag) {
        while (fgets(buf, LEN, fin)) {
            for (i = 0; buf[i]; i++) {
                if (buf[i] == '\n') {
                    buf[i] = 0;
                    break;
                }
            }
            if (strstr_word_4(buf, s_copy, del)) {
                fprintf(fout, "%s\n", buf);
                k++;
            }
        }
    }
    else {
        while (fgets(buf, LEN, fin)) {
            for (i = 0; buf[i]; i++) {
                if (buf[i] == '\n') {
                    buf[i] = 0;
                    break;
                }
            }
            if (strstr_(buf, s_copy)) {
                fprintf(fout, "%s\n", buf);
                k++;
            }
        }
    }
    if (!feof(fin)) {
        fclose(fin);
        fclose(fout);
        return -2;
    }
    fclose(fin);
    fclose(fout);
    return k;
}
int f5(const char *f_in, const char *f_out, const char* str, const char* tr) {
    FILE *fin, *fout;
    int i, k = 0;
    char buf[LEN];
    int del[8];

    for (i = 0; i < 8; i++) del[i] = 0;
    for (i = 0; tr[i]; i++) {
        del[tr[i] >> 5] |= (1 << (tr[i] & 31));
    }
    fin = fopen(f_in, "r");
    fout = fopen(f_out, "w");

    if (!fin || !fout) 
        return -1;
    while (fgets(buf, LEN, fin)) {
        for (i = 0; buf[i]; i++) {
            if (buf[i] == '\n') {
                buf[i] = 0;
                break;
            }
        }
        if (str_word_eq(buf, str, del)) {
            fprintf(fout, "%s\n", buf);
            k++;
        }
    }
    if (!feof(fin)) {
        fclose(fin);
        fclose(fout);
        return -2;
    }
    fclose(fin);
    fclose(fout);
    return k;
}


