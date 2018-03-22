#include <stdio.h>
#include <stdlib.h>
#include <fcntl.h>

int main(int argc,char* argv[]){
  if(argc < 4){
    fprintf(stderr,"Usage: %c <or_bitwise_compose> <src_file_name> <dest_file_name> <32-bit int in hex>\n",argv[0]);
    exit(1);
  }

  int fd,fdd,n,x;
  unsigned int hex;
  fd = open(argv[1],O_RDONLY);
  if(fd == -1){
    perror("open 1 fails");
    exit(2);
  }

  fdd = open(argv[2],O_WRONLY | O_CREAT | O_TRUNC,0600);
  if(fdd == -1){
    perror("open 2 fails");
    exit(2);
  }

  hex = (unsigned int) strtol(argv[3],NULL,16);

  while(n = read(fd,&x,sizeof(int))){
    if(n == -1){
      perror("Read in file fails");
      exit(2);
    }

    x = x | hex;
    
    n = write(fdd,&x,sizeof(int));
    if(n == -1){
      perror("Write in file fails");
      exit(3);
    }
  }  

  exit(0);
}