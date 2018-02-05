#include <stdio.h>
#include <stdlib.h>

typedef struct list list;
struct list {
  int elt;
  struct list* next;
};

void display (list* L);
list* ajout_tete (list* L, int elt);
list* copy (list* L, list* Lcopy);
struct list* join (struct list* l1, struct list* l2);

void display (list* L) {

  if(L == NULL) {
    printf("[]\n");
    return;
  }

  list *tmp = L;

  printf("[");

  while(tmp != NULL) {
    printf("%d", tmp->elt);
    if(tmp->next != NULL)
      printf(",");
    tmp = tmp->next;
  }

  printf("]\n");
}

list* ajout_tete (list* L, int elt) {

  list *tmp = malloc(sizeof(list));

  tmp->next = L;
  tmp->elt = elt;
  
  return tmp;
}

list* ajout_queue (list* L, int elt) {

  list *tmp = malloc(sizeof(list));

  if(L == NULL) {
    tmp->elt = elt;
    tmp->next = NULL;
    return tmp;
  } 

  list *temp = L;
  
  while(temp->next != NULL)
    temp = temp->next;

  tmp->elt = elt;
  tmp->next = NULL;
  temp->next = tmp;
  
  return L;
}

list* copy (list* L, list* Lcopy) {

  if(L == NULL)
    return NULL;

  while(L != NULL) {
    Lcopy = ajout_queue(Lcopy, L->elt);
    L = L->next;
  }

  return Lcopy;
}

list* firsthalf (list* L, list* Lcopy) {

  if(L == NULL)
    return NULL;

  list *tmp = L;
  int len = 0;
  while(tmp != NULL) {
    tmp = tmp->next;
    len++;
  }

  int i;
  for(i = 0; i < len/2; i++) {
    Lcopy = ajout_queue(Lcopy, L->elt);
    L = L->next;
  }

  return Lcopy;
}

list* lasthalf (list* L, list* Lcopy) {

  if(L == NULL)
    return NULL;

  list *tmp = L;
  int len = 0;
  while(tmp != NULL) {
    tmp = tmp->next;
    len++;
  }

  int i;
  for(i = 0; i < len/2; i++)
    L = L->next;

  while(L != NULL) {
    Lcopy = ajout_queue(Lcopy, L->elt);
    L = L->next;
  }

  return Lcopy;
}

struct list* join (struct list* l1, struct list* l2) {

  // pour ne pas modifier les pointeurs l1 et l2
  list *tmpl1 = l1;
  list *tmpl2 = l2;
  list *l1copy = NULL;
  list *l2copy = NULL;

  l1copy = copy(tmpl1, l1copy);
  l2copy = copy(tmpl2, l2copy);

  if(l1 == NULL)
    return l2copy;
  
  if(l2 == NULL)
    return l1copy;

  list *res = l1copy;

  while(l1copy->next != NULL)
    l1copy = l1copy->next;
  
  l1copy->next = l2copy;
  return res;
}

void split (struct list* l, struct list** l1, struct list** l2) {
  
  list *deb = NULL;
  list *fin = NULL;
  deb = firsthalf(l, deb);
  fin = lasthalf(l, fin);

  //display(deb);
  //display(fin);

  *l1 = NULL;
  printf("%p\n", *l1);

  // SEGMENTATION FAULT
  *l1 = deb;
  *l2 = fin;
}

void main (int argc, int *argv[]) {
 
  list* l = NULL;
  l = ajout_tete(l, -10);
  l = ajout_tete(l, 72);
  l = ajout_tete(l, -91);
  l = ajout_tete(l, 2);

  // QUESTION I

  /*list* l2 = NULL;
  l2 = ajout_tete(l2, 3);
  l2 = ajout_tete(l2, 8);
  l2 = ajout_tete(l2, 1);
  
  list* ljoin = NULL;
  ljoin = join(l, l2);
  
  printf("L1: "); display(l);
  printf("L2: "); display(l2);
  printf("Join: "); display(ljoin);*/

  
  // QUESTION II

  /*list** l1 = NULL;
  list** l2 = NULL;
  split(l, l1, l2);
  
  printf("L: "); display(l);*/
}
