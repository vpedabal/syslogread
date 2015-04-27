#ifndef _SYSLOG_H_
#define _SYSLOG_H_

#include "util.h"

uint64_t get_total_lines(char *filename);
void get_line(char *filename, uint64_t line);

#endif

