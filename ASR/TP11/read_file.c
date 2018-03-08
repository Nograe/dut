#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>


int main (int argc, char *argv[]) {
  
  if(argc < 2) {
    fprintf(stderr, "Usage: %s <file_name>\n", argv[0]);
    exit(1);
  }
  
  int fd = open(argv[1], O_RDONLY);
  
  if(fd == -1) {
    perror("opening of file fails");
    exit(2);
  }

  char buffer[256];
  int n = read(fd, buffer, 256);
  while(n) {
    if(n == -1) {
      perror("read of file fails");
      exit(3);
    }
    write(1, buffer, n);
    n = read(fd, buffer, 256);
  }
  exit(0);
}
