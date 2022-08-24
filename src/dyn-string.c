/* File: dyn-string.c
 * Author: Fabian, Doeller
 * E-Mail: fabian.doeller@mailfence.com
 * Description: 
 */
#include<stdlib.h>
#include<string.h>

#include "../includes/dyn-string.h"


/* Description: Initializes the dString struct with the values of NULL and 0.
 * Parameters:
 *  - struct dString* str: the dString struct
 * Returns: -
 */
void init_dString(struct dString* str)
{
    str->p = NULL;
    str->len = 0;
}


/* Description: Appends the given String to the dString struct
 * Parameters:
 *  - struct dString* str: the dString struct
 *  - char* inp_str: the string which should be appended
 *  - int str_size: the size of the string which should be appended
 * Returns:
 *  - int: 0 = successful
 *  - int: -1 = error
 */
int append_dString(struct dString* str, char* inp_str, int str_size)
{
    int i;
    char* new_str = realloc(str->p, str->len + str_size);
    if (new_str == NULL) { return -1; }
    for (i = 0; i < str->len; i++)
    {
        *(new_str + i) = *(str->p + i); 
    }
    for (i = str->len; i < str->len + str_size; i++)
    {
        *(new_str + i) = *(inp_str - str->len + i);
    }
    str->p = new_str;
    str->len += str_size;
    return 0;
}


/* Description: Frees the content of the given struct and replace that with an
 * void-Pointer.
 * Parameters:
 *  - struct dString* str: the dString struct
 * Returns: -
 */
void free_dString(struct dString* str)
{
    free(str->p);
    str->p = NULL;
}