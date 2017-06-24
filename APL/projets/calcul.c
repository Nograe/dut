#include <stdio.h>

void fill(int tab[]){

  char var;
  int i=0;

  scanf("%c", &var);
  while(var >= '0' && var <= '9'){   
    tab[i]=var - '0';
    scanf("%c", &var);
    i++;
  }

}

void printtab(int tab[]){
  int i;
  for(i=0; i<99; i++){
    printf("%d", tab[i]);
  }
}

void main(){
  
  int tab1[100]={0};
  int tab2[100]={0};
  int tab3[100]={0};

  fill(tab1);
  fill(tab2);
  fill(tab3);
  
  printtab(tab1);
  printf("\n");
  printtab(tab2);
  printf("\n");
  printtab(tab3);
}
