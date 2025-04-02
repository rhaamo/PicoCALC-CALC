#ifndef UTILS_H
#define UTILS_H

#include <stdbool.h>
#include <stdlib.h> // IWYU pragma: keep

bool is_ascii(char c);
char *sanitize_command(const char *in_cmd);

#endif