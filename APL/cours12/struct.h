typedef struct List List;

struct List {
  int elt;
  List *next;
  List *prev;
};
