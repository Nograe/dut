#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>

typedef struct List List;

struct List {
  int elt;
  List *next;
  List *prev;
};

List* ajout_tete (List* L, int elt) {

  List *tmp = malloc(sizeof(List));

  tmp->next = L;
  tmp->prev = NULL;
  tmp->elt = elt;

  if(L != NULL)
    L->prev = tmp;
  
  return tmp;
}

List* ajout_queue (List* L, int elt) {

  List *tmp = malloc(sizeof(List));

  if(L == NULL) {
    tmp->elt = elt;
    tmp->prev = NULL;
    tmp->next = NULL;
    return tmp;
  } 

  List *temp = L;

  while(temp->next != NULL)
    temp = temp->next;

  tmp->next = NULL;
  tmp->prev = temp;
  tmp->elt = elt;
  temp->next = tmp;
  
  return L;
}

List* insertion (List* L, int elt, int p) {
  List *tmp = L;

  if(p < 1 || L == NULL) {
    return ajout_tete(L, elt);
  }

  int i;
  for(i = 0 ; i < p ; i++) {
    tmp = tmp->next;
    if(tmp == NULL) {
      return ajout_queue(L, elt);
    }
  }

  List *res = malloc(sizeof(List));
  res->elt = elt;

  res->prev = tmp->prev;
  tmp->prev->next = res;
  tmp->prev = res;
  res->next = tmp;

  return L;
}

void display (List* L) {

  if(L == NULL) {
    printf("[]\n");
    return;
  }

  List *tmp = L;

  printf("[");

  while(tmp != NULL) {
    printf("%d", tmp->elt);
    if(tmp->next != NULL)
      printf(",");
    tmp = tmp->next;
  }

  printf("]\n");
}

void reverse_display (List *L) {

  if(L == NULL) {
    printf("[]\n");
    return;
  }

  List *tmp = L;

  while(tmp->next != NULL)
    tmp = tmp->next;

  printf("[");

  while(tmp != NULL) {
    printf("%d", tmp->elt);
    if(tmp->prev != NULL)
      printf(",");
    tmp = tmp->prev;
  }

  printf("]\n");
}

List *supprimer_premier (List *L) {

  //La liste est vide
  if(L == NULL) {
    return L;
  }

  //La liste contient 1 élément
  if(L->next == NULL) {
    free(L);
    return NULL;
  }

  L = L->next;

  free(L->prev);

  L->prev = NULL;

  return L;
}

List *supprimer_dernier (List *L) {

  //La liste est vide
  if(L == NULL) {
    return L;
  }

  //La liste contient 1 élément
  if(L->next == NULL) {
    return supprimer_premier(L);
  }

  List *tmp = L;

  while(tmp->next != NULL)
    tmp = tmp->next;

  tmp->prev->next = NULL;

  free(tmp);

  return L;
}

List* supprimer (List *L, int p) {

  if(p < 0)
    return L;

  //La liste est vide
  if(L == NULL) {
    return L;
  }

  if(p == 0) {
    return supprimer_premier(L);
  }

  List *tmp = L;

  int i;
  for(i = 0 ; i < p ; i++) {
    tmp = tmp->next;
    if(tmp == NULL)
      return L;
  }

  if(tmp->next == NULL)
    tmp->prev->next = NULL;
  else {
    tmp->prev->next = tmp->next;
    tmp->next->prev = tmp->prev;
  }

  free(tmp);

  return L;
}

int nb_occ (List* L, int elt) {

  //La liste est vide
  if(L == NULL) {
    return 0;
  }

  if(L->next == NULL && L->elt == elt) {
    return 1;
  }

  List *tmp = L;
  int count = 0;

  while(tmp != NULL) {
    if(tmp->elt == elt)
      count++;
    tmp = tmp->next;
  }

  return count;
}

int first_occ (List *L, int elt) {

  //La liste est vide
  if(L == NULL) {
    return -1;
  }

  List *tmp = L;
  int count = -1;

  while(tmp != NULL) {
    count ++;
    if(tmp->elt == elt)
      return count;
    tmp = tmp->next;
  }

  return (-1);
}

List* supprimer_tout(List* L, int elt) {

  //La liste est vide
  if(L == NULL) {
    return L;
  }

  while(nb_occ(L, elt) != 0)
    L = supprimer(L, first_occ(L, elt));

  return L;
}

List* trier(List* L) {

  if(L == NULL || L->next == NULL) {
    return L;
  }

  List *tmp = L;
  int temp = 0;
  int count = 0;

  while(tmp->next != NULL) {
    if(tmp->elt > tmp->next->elt) {
      temp = tmp->elt; 
      tmp->elt = tmp->next->elt;
      tmp->next->elt = temp;
    }
    tmp = tmp->next;
  }

  tmp = L;
  while(tmp->next != NULL) {
    if(tmp->elt > tmp->next->elt)
      return trier(L);
    tmp = tmp->next;
  }

  return L;
}

void main () {
  List* l = NULL;

  l = ajout_tete(l, 7);
  l = ajout_tete(l, 6);
  l = ajout_tete(l, 8);
  
  printf("init:"); display(l);

  l = trier(l);

  printf("end:"); display(l);
}
