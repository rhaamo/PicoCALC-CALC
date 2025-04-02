#ifndef UTILS_H
#define UTILS_H

#include <malloc.h>
#include <stdint.h>

extern char __StackLimit, __bss_end__;

uint32_t get_total_heap(void);
uint32_t get_free_heap(void);

#endif