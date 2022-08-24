/* File: dyn-string.h
 * Author: Fabian, Doeller
 * E-Mail: fabian.doeller@mailfence.com
 * Description: header file of dyn-string.c
 */
#ifndef H_DYN_STRING
#define H_DYN_STRING

#include <stdlib.h>
#include <string.h>

 struct dString
 {
    char* p;
    int len;
 };

void init_dString(struct dString* str);
int append_dString(struct dString* str, char *inp_str, int str_size);
void free_dString(struct dString* str);

#endif