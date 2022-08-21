/* File: arrays.h
 * Author: Fabian, Doeller
 * E-Mail: fabian.doeller@mailfence.com
 * Description: header file of array.c
 */
#ifndef H_ARRAY
#define H_ARRAY

#include <stdlib.h>

void array_fill(int* array, size_t array_size, int filler);
void array_reverse(int* array, size_t array_size);
void array_replace(int* array, size_t array_size, int replaceable, int replacer, int repeats);
int array_compare(int* array1, int* array2, size_t array1_size, size_t array2_size);
int* array_clone(int* array, size_t array_size);

#endif