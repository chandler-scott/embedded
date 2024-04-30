#include "formatted_print.h"
#include <stdio.h>
#include <stdarg.h>

void printFormatted(const char *format, ...) {
    va_list args;
    va_start(args, format);
    vprintf(format, args);
    va_end(args);
}

