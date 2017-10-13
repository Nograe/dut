#include <stdio.h>

void printtab(int tab[]);
void calcul(int tab1[], int tab2[], int tabresult[], char op);

void mult(int tab1[], int tab2[], int result[]) {
    printf("Mult!\n");
}

void divid(int tab1[], int tab2[], int result[]) {
    printf("Divid!\n");
}

void modulo(int tab1[], int tab2[], int result[]) {
    printf("Modulo!\n");
}

void add(int tab1[], int tab2[], int result[]) {

    int i;
    //Scan des tableaux
    for(i=99; i>=1; i++) {
        if(tab1[i] == 11111) {
            printf("Stop � la case %d", i);
        }
    }

    for(i=1000; i>0; i++) {
        tab1[i]+tab2[i];
    }

    printf("Add!\n");
}

void soustr(int tab1[], int tab2[], int result[]) {
    printf("Soustr!\n");
}

void printtab(int tab[]) {
    int i;
    for(i=0; i<99; i++) {
        printf("%d", tab[i]);
    }
    printf("\n");
}

void calcul(int tab1[], int tab2[], int tabresult[], char op) {

    if(op == '*') {
        mult(tab1,tab2,tabresult);
        return;
    }
    if(op == '/') {
        divid(tab1,tab2,tabresult);
        return;
    }
    if(op == '%') {
        modulo(tab1,tab2,tabresult);
        return;
    }
    if(op == '+') {
        add(tab1,tab2,tabresult);
        return;
    }
    if(op == '-') {
        soustr(tab1,tab2,tabresult);
        return;
    }

}

void main() {

    int tab1[100]= {0};
    int tab2[100]= {0};
    int tab3[100]= {0};
    int tabresult[1000]= {0};
    int tabfinal[1000]= {0};
    char op1, op2, var;
    int i=2;

    //Attribution 0/1
    scanf("%c", &var);
    if(var == '-') {
        tab1[0]=1;
        //Skip espaces entre n�gatif et 1er nombre
        do {
            scanf("%c", &var);
        } while(var == ' ');
        tab1[1]=var - '0';
    } else {
        tab1[0]=0;
        tab1[1]=var - '0';
    }

    //Remplissage 1er tab
    scanf("%c", &var);
    while(var >= '0' && var <= '9') {
        //printf("var: '%c'\n", var);
        tab1[i]=var - '0';
        i++;
        scanf("%c", &var);
    }
    tab1[i]=11111;

    //Skip espaces et r�cup�ration 1er op�rateur
    while(var == ' ') {
        scanf("%c", &var);
    }
    op1=var;

    printf("operateur1: '%c'\n", op1);
    printtab(tab1);


    //Skip espaces avant 2e nombre
    do {
        scanf("%c", &var);
        //printf("var: '%c'\n", var);
    } while(var == ' ');

    //Attribution 0/1
    i=2;
    if(var == '-') {
        tab2[0]=1;
        //Skip espaces entre n�gatif et 2e nombre
        do {
            scanf("%c", &var);
        } while(var == ' ');
        tab2[1]=var - '0';
    } else {
        tab2[0]=0;
        tab2[1]=var - '0';
    }

    //Remplissage 2e tab
    scanf("%c", &var);
    while(var >= '0' && var <= '9') {
        tab2[i]=var - '0';
        i++;
        scanf("%c", &var);
    }
    tab2[i]=11111;

    //Skip espaces et r�cup�ration 2e op�rateur
    while(var == ' ') {
        scanf("%c", &var);
    }
    op2=var;

    printf("operateur2: '%c'\n", op2);
    printtab(tab2);


    //Test 3e op�rateur
    if((int)op2 == 10) {
        calcul(tab1,tab2,tabfinal,op1);
        printtab(tabfinal);
        return;
    }


    //Skip espaces avant 3e nombre
    do {
        scanf("%c", &var);
    } while(var == ' ');

    //Attribution 0/1
    i=2;
    if(var == '-') {
        tab3[0]=1;
        //Skip espaces entre n�gatif et 3e nombre
        do {
            scanf("%c", &var);
        } while(var == ' ');
        tab3[1]=var - '0';
    } else {
        tab3[0]=0;
        tab3[1]=var - '0';
    }

    //Remplissage 3e tab
    scanf("%c", &var);
    while(var >= '0' && var <= '9') {
        tab3[i]=var - '0';
        i++;
        scanf("%c", &var);
    }
    tab1[i]=11111;

    printtab(tab3);


    //Calcul prioritaire de tab2 et tab3 puis tab1 et result
    if((op2 == '*' || op2=='/' || op2=='%') && (op1 != '*' && op1 != '/' && op1 != '%')) {
        calcul(tab2,tab3,tabresult,op2);
        calcul(tab1,tabresult,tabfinal,op1);
        printtab(tabfinal);
        return;
    }

    //Calcul de tab1 et tab2 puis tab2 et tabresult
    calcul(tab1,tab2,tabresult,op1);
    calcul(tab2,tabresult,tabfinal,op2);
    printtab(tabfinal);
    return;
}
