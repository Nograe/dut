#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char* argv[]){
  int fd,n, i, offset;
  off_t l;
  long long int x;
  char buf[8];

  if(argc < 4){
    fprintf(stderr, "Usage: %s <file_name> <32_bit int in Hex> <Offset in Hex>\n", argv[0]);
    exit(1);
  }

  fd = open(argv[1], O_WRONLY);
  if(fd == -1){
    perror("open fails");
    exit(2);
  }

  x = (int)strtoll(argv[2], NULL, 16);
  i = strtol(argv[3], NULL, 16);  
  offset = i * sizeof(int);
  l = lseek(fd, 0, SEEK_END);
  if(offset > l){
    offset = l;
  }

  lseek(fd, offset, SEEK_SET);
  n = write(fd, &x, sizeof(int));

  exit(0);
}
