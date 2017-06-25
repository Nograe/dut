int main(int argc, char* argv[]) {

  int a = 1, b = 2, c = 3;
  int *p, *q;
  p=&a;
  printf("1. %d %d %d\n",a,b,c);
  q=&c;
  printf("2. %d %d %d\n",a,b,c);
  *p=(*q)++;
  printf("3. %d %d %d\n",a,b,c);
  p=q;
  printf("4. %d %d %d\n",a,b,c);
  q=&b;
  printf("5. %d %d %d\n",a,b,c);
  *p-=*q;
  printf("6. %d %d %d\n",a,b,c);
  ++*q;
  printf("7. %d %d %d\n",a,b,c);
  *p*=*q;
  printf("8. %d %d %d\n",a,b,c);
  a=++*q**p;
  printf("9. %d %d %d\n",a,b,c);
  p=&a;
  printf("10. %d %d %d\n",a,b,c);
  *q=*p/(*q);
  printf("11. %d %d %d\n",a,b,c);
  return 0;
}

