#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

//copy.c
int main(int argc, char* argv[]){
  int fd, fdd, n;
  char buf[256];
  if(argc < 3){
    fprintf(stderr, "Usage: %s\n <src-file-name> <Dest-file-name>\n", argv[0]);
    exit(1);
  }
  //opening Src file...
  fd=open(argv[1],O_RDONLY); //rondly= read only
  if(fd==-1){
    perror("Opening Src File fails");
    exit(2);
  }
  //Opening Dest File
  fdd=open(argv[2],O_WRONLY|O_CREAT|O_TRUNC,0600);
  if(fdd==-1){
    perror("Opening Dest File Fails");
    exit(2);
  }
  while((n=read(fd,buf,256))!=0){
    if(n==-1){
      perror("read fails");
      exit(3);
    }
    write(fdd,buf,n);
  }
  exit(0);
}
//fin main
