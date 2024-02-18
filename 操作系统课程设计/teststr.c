#include <unistd.h>
#include <stdio.h>
#include <errno.h>

int main(int argc, char **argv) {
  printf("\nDone\n");
  long ret = syscall(334, argv[1]);
  printf("ret: %ld\n", ret);
  return 0;
}