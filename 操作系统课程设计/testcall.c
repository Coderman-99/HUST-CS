#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(void) {
  printf("\nDone dmesg to see Hello world\n");
  syscall(333);
  return 0;
}