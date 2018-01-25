#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct Pile Pile;
struct Pile {
  int elt;
  Pile* suivant;
};

Pile* empiler (Pile *p, int elt) {

  Pile* res = malloc(sizeof(Pile));

  res->elt = elt;
  res->suivant = NULL;

  if(p == NULL)
    return res;
  res->suivant = p;
  return res;
}

Pile* depiler(Pile* p) {

  if(p == NULL)
    return p;

  Pile *res = p->suivant;
  free(p);
  
  return res;
}

int est_vide(Pile* p) {

  if(p == NULL)
    return 1;
  return 0;
}

int sommet(Pile* p) {
  return p->elt;
}

Pile* copy(Pile* p) {
  Pile* res = NULL;
  Pile* tmp = p;
  int var;

  if(p == NULL)
    return res;

  while(!est_vide(tmp)) {
    var = sommet(tmp);
    tmp = depiler(tmp);
    res = empiler(res, var);
  }

  //printf("Etape1 :%d>%d>%d\n", res->elt, res->suivant->elt, res->suivant->suivant->elt);

  while(!est_vide(res)) {
    var = sommet(res);
    res = depiler(res);
    tmp = empiler(tmp, var);
  }

  //printf("Etape2: %d>%d>%d\n", tmp->elt, tmp->suivant->elt, tmp->suivant->suivant->elt);

  p = tmp;
  return tmp;
}

Pile* inverse(Pile *p) {
  Pile* res = NULL;
  Pile* tmp = p;
  
  if(p == NULL)
    return res;

  while(!est_vide(tmp)) {
    res = empiler(res, tmp->elt);
    tmp = tmp->suivant;
  }

  p = tmp;
  return res;
}

int verif (Pile *p) {
  
  
}

/*void main () {

  Pile *P = NULL;
  P = empiler(P, 10);
  P = empiler(P, 5);
  P = empiler(P, 2);
  //printf("%d\n", P->elt);
  //P = depiler(P);
  //printf("%d\n", P->elt);
  //printf("%d\n", est_vide(P));
  //printf("%d\n", sommet(P));
  Pile *C = copy(P);
  //printf("%d\n", C->elt);
  Pile *I = inverse(P);
  printf("%d\n", I->elt);
}*/

void main () {

  Pile *F = NULL;
  /*F = enfiler(F, 3);
    F = enfiler(F, 0);
    F = enfiler(F, 8);
    F = enfiler(F, 7);
    afficher(F);
    //F = defiler(F);
    //afficher(F);
    //printf("%d>%d>%d\n", F->elt, F->suivant->elt, F->suivant->suivant->elt);

    File *C = copy(F);
    afficher(C);*/

  char chain[100];
  scanf("%s", chain);

  int i = 0;
  while(chain[i] != '\0') {
    if(chain[i] == '(')
      empiler(F, 1);
    if(chain[i] == ')')
      empiler(F, 2);
    if(chain[i] == '[')
      empiler(F, 3);
    if(chain[i] == ']')
      empiler(F, 4);
    if(chain[i] == '{')
      empiler(F, 5);
    if(chain[i] == '}')
      empiler(F, 6);
    verif(P);
    i++;
  }
}
