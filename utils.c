#include <utils.h>

// Returns: bytes
uint32_t get_total_heap(void) {
  return &__StackLimit - &__bss_end__;
}

// Returns: bytes
uint32_t get_free_heap(void) {
  size_t total_heap = &__StackLimit - &__bss_end__;
  struct mallinfo info = mallinfo();
  return total_heap - info.uordblks;
}
