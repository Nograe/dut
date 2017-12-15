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

  if(L == NULL) {
    return L;
  }

  if(L->next == NULL

  L = L->next;

  free(L->prev);

  L->prev = NULL;

  return L;
}

void main () {
  List* l = NULL;

  l = ajout_tete(l, 5);
  
  reverse_display(l);

  l = supprimer_premier(l);

  display(l);
}
