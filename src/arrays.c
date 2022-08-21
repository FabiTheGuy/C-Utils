/* File: arrays.h
 * Author: Fabian, Doeller
 * E-Mail: fabian.doeller@mailfence.com
 * Description: utilities which should help to improve the workflow with arrays
 */
#include <stdlib.h>

#include "../includes/arrays.h"


static void switch_values(int* val1, int* val2);


/* Description: Fills the array with the filler
 * Parameters:
 *  - int* array: the first entry of the array
 *  - size_t array_size: size of the complete array
 *  - int filler: the value you want to fill the array with
 * Returns: -
 */
void array_fill(int* array, size_t array_size, int filler)
{
    unsigned int i;
    for (i = 0; i < array_size; i++)
    {
        array[i] = filler;
    }
}


/* Description: Reverses the array so the first entry ist the last and the last entry is
 * the first
 * Parameters:
 *  - int* array: the first entry of the array
 *  - size_t array_size: size of the complete array
 * Returns: -
 */
void array_reverse(int* array, size_t array_size)
{
    unsigned int i, temp_size;
    temp_size = (int) array_size / 2;
    for (i = 0; i < temp_size; i++)
    {
        switch_values((array + i), (array + (array_size - 1) - i));
    }
}


/* Description: Replaces a specific value in the array with another value
 * Parameters:
 *  - int* array: the first entry of the array
 *  - size_t array_size: size of the complete array
 *  - int replaceable: the value which should be replaced
 *  - int replacer: the value with which the replaceable will be replaced
 *  - int repeats: how often a value will be replaced (0 means all)
 * Returns: -
 */
void array_replace(int* array, size_t array_size, int replaceable, int replacer, int repeats)
{
    unsigned int i;
    int repeats_counter = 0;
    for (i = 0; i < array_size; i++)
    {
        if (array[i] == replaceable && (repeats_counter < repeats || repeats == 0))
        {
            array[i] = replacer;
            repeats_counter++;
        }
    }
}


/* Description: Compares the to given arrays. If the arrays have different sizes they will 
 * only compared to the array with the smaller size.
 * Parameters:
 *  - int* array1: the first entry of the array
 *  - size_t array_size1: size of the complete array
 *  - int* array2: the first entry of the array
 *  - size_t array_size2: size of the complete array
 * Returns:
 *  - int: 1 = the arrays are equals
 *  - int: 0 = the arrays are not equals
 */
int array_compare(int* array1, int* array2, size_t array1_size, size_t array2_size)
{
    unsigned int i, temp_size;
    if (array1_size != array2_size)
    {
        temp_size = (array1_size > array2_size) ? array2_size : array1_size;
    } else
    {
        temp_size = array1_size;
    }
    for (i = 0; i < temp_size; i++)
    {
        if (array1[i] != array2[i])
        {
            return(0);
        }
    }
    return(1);
}


/* Description: Creates a clone of the given array
 * Parameters:
 *  - int* array: the first entry of the array
 *  - size_t array_size: size of the complete array
 * Returns:
 *  - int*: x = returns the first index of the cloned array
 */
int* array_clone(int* array, size_t array_size)
{
    unsigned int i;
    int* local_array = malloc(array_size * sizeof(int));
    for (i = 0; i < array_size; i++)
    {
        local_array[i] = array[i];
    }
    return local_array;
}


/* -----internal functions----- */


/* Description: Switch the values of the given pointer 
 * Parameters:
 *  - int* val1: pointer 1
 *  - int* val2: pointer 2
 * Returns: -
 */
static void switch_values(int* val1, int* val2)
{
    int temp = *val1;
    *val1 = *val2;
    *val2 = temp;    
}