#include <stdio.h>

void except(int exc){
  if(exc==1)printf("onze\n");
  if(exc==2)printf("douze\n");
  if(exc==3)printf("treize\n");
  if(exc==4)printf("quatorze\n");
  if(exc==5)printf("quinze\n");
  if(exc==6)printf("seize\n");
  return;
}

void decimale(int uni){
  if(uni==0)printf("zéro");
  if(uni==1)printf("un");
  if(uni==2)printf("deux");
  if(uni==3)printf("trois");
  if(uni==4)printf("quatre");
  if(uni==5)printf("cinq");
  if(uni==6)printf("six");
  if(uni==7)printf("sept");
  if(uni==8)printf("huit");
  if(uni==9)printf("neuf");
  return;
}

void dizaine(int diz){
  if(diz==1)printf("dix");
  if(diz==2)printf("vingt");
  if(diz==3)printf("trente");
  if(diz==4)printf("quarante");
  if(diz==5)printf("cinquante");
  if(diz==6)printf("soixante");
  if(diz==7)printf("soixante-dix");
  if(diz==8)printf("quatre-vingt");
  if(diz==9)printf("quatre-vingt-dix");
  return;
}

void convert(ent){
  int deci=ent%10;
  int diz=ent/10;
  if(ent==10){printf("dix\n");}
  if(ent==80){printf("quatre-vingts\n"); return;}
  if(diz==0){decimale(deci); printf("\n"); return;}
  if(diz==1 && deci<=6){except(deci); return;}
  if(deci==0){dizaine(diz); printf("\n"); return;}
  // Exception dizaines suivie de 1 a partir de 60
  if(deci==1 && diz>6){if(diz==7){printf("soixante et onze\n"); return;}if(diz==8){printf("quatre-vingt-un\n"); return;}if(diz==9){printf("quatre-vingt-onze\n"); return;}}
  // Exception dizaines suivie de 1
  if(deci==1){dizaine(diz); printf(" et "); decimale(deci); printf("\n");  return;}
  // Exception à partir de 71
  if(diz==7 && deci<7){dizaine(diz-1); printf("-"); except(deci); return;}
  if(diz==9 && deci>1 && deci<7){dizaine(diz-1); printf("-"); except(deci); return;}
  dizaine(diz); printf("-"); decimale(deci); printf("\n");  return;
  return;
}

void main() {
  int ent=0;
  scanf("%d",&ent);
  convert(ent);
  return;
}
