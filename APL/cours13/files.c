#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct File File;
struct File {
  int elt;
  File* suivant;
};

void afficher (File *f) {

  while(f != NULL) {
    printf("%d", f->elt);
    f = f->suivant;
    if(f != NULL)
      printf(">");
  }
  printf("\n");
}

File* enfiler (File *f, int elt) {

  File* res = malloc(sizeof(File));

  res->elt = elt;
  res->suivant = NULL;

  if(f == NULL)
    return res;

  res->suivant = f;
  return res;
}

File* defiler (File *f) {

  if(f == NULL)
    return NULL;

  if(f->suivant == NULL) {
    free(f);
    return NULL;
  }

  File* tmp = f;
  File* last = NULL;

  while(f->suivant != NULL) {
    last = f;
    f = f->suivant;
  }

  free(f);
  last->suivant = NULL;

  return tmp;
}

int est_vide (File *f) {

  if(f == NULL)
    return 1;
  return 0;
}

int dernier (File* f) {

  while(f->suivant != NULL)
    f = f->suivant;

  return f->elt;
}

File* copy (File* f) {
  File* res = NULL;
  File* tmp = f;
  int var;

  if(f == NULL)
    return res;

  while(!est_vide(tmp)) {
    var = dernier(tmp);
    tmp = defiler(tmp);
    res = enfiler(res, var);
  }

  //printf("Etape1 :%d>%d>%d\n", res->elt, res->suivant->elt, res->suivant->suivant->elt);

  while(!est_vide(res)) {
    var = dernier(res);
    res = defiler(res);
    tmp = enfiler(tmp, var);
  }

  //printf("Etape2: %d>%d>%d\n", tmp->elt, tmp->suivant->elt, tmp->suivant->suivant->elt);

  f = tmp;
  return tmp;
}

File* inverse(File *f) {
  File* res = NULL;
  File* tmp = f;
  
  if(f == NULL)
    return res;

  while(!est_vide(tmp)) {
    res = enfiler(res, tmp->elt);
    tmp = tmp->suivant;
  }

  f    = tmp;
  return res;
}

void main () {

  File *F = NULL;
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
      emfiler(F, 1);
    if(chain[i] == ')')
      emfiler(F, 2);
    if(chain[i] == '[')
      emfiler(F, 3);
    if(chain[i] == ']')
      empiler(F, 4);
    if(chain[i] == '{')
      empiler(F, 5);
    if(chain[i] == '}')
      empiler(F, 6);
  }
}
