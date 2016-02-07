#ifndef _CCC_MESSAGE_H_
#define _CCC_MESSAGE_H_

#include <stdio.h>
#include <string.h>
#include <stdarg.h>



void *__cc_message(char* file, int line, char* type, int count, ...)
{
    va_list ap;

    va_start(ap, count);

    fprintf(stderr, "\n[ CCC ] From %s:%d:", file, line);
    fprintf(stderr, "\n[ CCC ] %s: ", type);

    while (count--)
        fprintf(stderr, "%s%s", va_arg(ap, char*), count ? " " : "\n");

    va_end(ap);

    return NULL;
}



/* CCC Warning (print the warning message if CCC_MESSAGE is set) */


#ifdef CCC_MESSAGE
    #define __cc_warning_dllst_is_empty(_cc_dllst_object)                  \
        __cc_message(__FILE__, __LINE__, "WARNING", 3,                     \
                     "dllst:", #_cc_dllst_object, "is empty.")
#else
    #define __cc_warning_dllst_is_empty(_cc_dllst_object) NULL
#endif


#ifdef CCC_MESSAGE
    #define __cc_warning_dllst_iter_is_invalid(_cc_dllst_iter)             \
        __cc_message(__FILE__, __LINE__, "WARNING", 3,                     \
                     "dllst iterator:", #_cc_dllst_iter, "is invalid.")
#else
    #define __cc_warning_dllst_iter_is_invalid(_cc_dllst_iter) NULL
#endif



#endif