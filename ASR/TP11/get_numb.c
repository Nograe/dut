#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>

int main (int argc, char* argv[]){
  int fd,n,x, i, offset;
  off_t l;

  if(argc<3){
    fprintf(stderr, "Usage: %s <file_name> <offset>\n", argv[0]);
    exit(1);
  }
  fd= open(argv[1], O_RDONLY);
  if(fd==-1){
    perror("open fails");
    exit(2);
  }
  i=strtol(argv[2], NULL,0);
  offset = i * sizeof(int);
  /* (*) On peut utiliser pour cela la fonction strtol (string to long)
     i=strtol(argv[2](la chaine de caractère à convertir), NULL,0(3ème argument de strtol: la base dans laquelle il aut lire ce qu'on doit convertir)) 
  */

  //Deplacement
  l=lseek(fd, offset, SEEK_SET);
  if(l==-1){
    perror("lseek fails");
    exit(3);
  }
  n=read(fd, &x, sizeof(int));
  if(n==-1){
    perror("read fails");
    exit(4);
  }
  if(n==0){
    printf("offset is out of range!\n");
  }
  else{
    printf("The number at offset %d\n is 0x%08x --> %d\n",i,x,x);
  }
  exit(0);
}
