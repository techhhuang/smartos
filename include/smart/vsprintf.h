#ifndef _VSPRINTF_H
#define _VSPRINTF_H

#include <stdarg.h>

// void printf(const char *format, ...);
int vsprintf(char *str, const char *fmt, va_list ap);


#endif
