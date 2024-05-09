#ifndef __HOST_MESSAGING__
#define __HOST_MESSAGING__

#include <stdio.h>
#include <stddef.h>
#include <stdint.h>
#include <string.h>
#include <stdarg.h>

// Macro definitions to print the specified format for error messages
#define print_error(...) printf("%%error: "); printf(__VA_ARGS__); printf("%%\n"); fflush(stdout)

// Macro definitions to print the specified format for debug messages
#define print_debug(...) printf("%%debug: "); printf(__VA_ARGS__); printf("%%\n"); fflush(stdout)

// Macro definitions to print the specified format for info messages
#define print_info(...) printf("%%info: "); printf(__VA_ARGS__); printf("%%\n"); fflush(stdout)

// Macro definition to print the specified format for ack messages
#define print_ack() printf("%%ack%%\n"); fflush(stdout)

#endif

