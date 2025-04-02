#include <utils.h>

// Temporary for now until kbd issue solved
bool is_ascii(char c) {
  return (c>=0 && c<=127);
}

// Temporary for now until kbd issue solved
char *sanitize_command(const char *in_cmd) {
  // Workaround for now because the LVGL PicoCalc makes shift key in the textarea
  size_t length = 0;
  const char *p = in_cmd;
  while (*p) {
      if (is_ascii(*p)) length++;
      p++;
  }

  char *out = malloc(length+1);
  if (!out) return NULL;

  char *dest = out;
  while (*in_cmd) {
      if (is_ascii(*in_cmd)) {
          *dest++ = *in_cmd;
      }
      in_cmd++;
  }
  *dest = '\0';

  return out;
}
