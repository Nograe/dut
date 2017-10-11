#include <stdio.h>

int commun(int ent, int ent2) {
    int tmp=ent;
    int var, var2;
    int verif;
    while(ent2>0) {
        ent=tmp;
        var2=ent2%10;
        ent2=ent2/10;
        //printf("var2:%d     ent2:%d\n",var2,ent2);
        while(ent>0) {
            var=ent%10;
            ent=ent/10;
            //printf("var:%d     ent:%d\n",var,ent);
            if(var==var2) {
                return 1;
            }
        }
    }
    return 0;
}

void main() {
    int ent, ent2;
    scanf("%d %d",&ent, &ent2);
    printf("%d\n",commun(ent, ent2));
}
