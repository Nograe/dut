#include <stdio.h>

void printtab(int tab[]);
void calcul(int tab1[], int tab2[], int tabresult[], char op);
void reverse(int tab[]);
int max(int tab1[], int tab2[]);
void fill(int tab[], char *var_main);

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

    int i,sum;
    int j=2;
    int retenue=0;
    int taillemax;
    int taille1=tab1[1]+1;
    int taille2=tab2[1]+1;
    if(taille1 >= taille2){
        taillemax=taille1;
    } else {
        taillemax=taille2;
    }

    for(i=taillemax; i>=2; i--){
        if(taille1<=1){
            sum=tab2[taille2]+retenue;
        } else if(taille2<=1){
            sum=tab1[taille1]+retenue;
        } else{
            sum=tab1[taille1]+tab2[taille2]+retenue;
        }
        retenue=0;
        if (sum<10){
            result[j]=sum;
            j++;
        } else {
            result[j]=sum%10;
            retenue++;
            j++;
        }
        taille1--;
        taille2--;
    }

    if(retenue==1){
        result[j]=1;
        result[1]=taillemax;
    } else{
        result[1]=taillemax-1;
    }

}

void soustr(int tab1[], int tab2[], int result[]) {

    int signe=result[0];
    int taille1=tab1[1]+1;
    int taille2=tab2[1]+1;
    result[0]=0;

    if(signe == 2 && max(tab2,tab1)){
        result[0]=1;
    }
    if(signe == 3 && max(tab1,tab2)){
        result[0]=1;
    }

    int i,sous;
    int j=2;
    int retenue=0;
    int taillemax;
    if(taille1 >= taille2){
        taillemax=taille1;
    } else {
        taillemax=taille2;
    }

    for(i=taillemax; i>=2; i--){
        if(taille1<=1){
            sous=tab2[taille2]-retenue;
        } else if(taille2<=1){
            sous=tab1[taille1]-retenue;
        } else{
            sous=tab1[taille1]-tab2[taille2]-retenue;
        }
//printf("Retenue= %d ; ", retenue);
        retenue=0;
        if (sous >= 0){
            result[j]=sous;
            j++;
        } else {
            result[j]=10+sous;
            retenue++;
            j++;
        }
//printf("tab1[%d]=%d - tab2[%d]=%d = %d\n", taille1, tab1[taille1], taille2, tab2[taille2], result[j-1]);
        taille1--;
        taille2--;
    }

    result[1]=taillemax;
    
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
        // -X + Y   -> Positif pour Y > X
        // => Y-X  si  Y > X
        if(tab1[0]==1 && tab2[0]==0){
            if(!max(tab1,tab2)){
                tabresult[0]=0;
                soustr(tab2,tab1,tabresult);
                return;
            }
            tabresult[0]=3;
            soustr(tab1,tab2,tabresult);
            return;
        }
        // -X + -Y  -> Négatif
        if(tab1[0]==1 && tab2[0]==1){
            tabresult[0]=1;
            add(tab1,tab2,tabresult);
            return; 
        }
        // X + -Y   -> Positif pour X > Y
        if(tab1[0]==0 && tab2[0]==1){
            tabresult[0]=2;
            soustr(tab1,tab2,tabresult);
            return; 
        }
        add(tab1,tab2,tabresult);
        return;
    }
    if(op == '-') {
        // -X - Y   -> Négatif
        if(tab1[0]==1 && tab2[0]==0){
            tabresult[0]=1;
            add(tab1,tab2,tabresult);
            return;
        }
        // -X - -Y  -> Positif pour Y > X
        // => Y-X  si  Y > X
        if(tab1[0]==1 && tab2[0]==1){
            if(!max(tab1,tab2)){
                tabresult[0]=0;
                soustr(tab2,tab1,tabresult);
                return;
            }
            tabresult[0]=3;
            soustr(tab1,tab2,tabresult);
            return; 
        }
        // X - -Y   -> Positif
        if(tab1[0]==0 && tab2[0]==1){
            add(tab1,tab2,tabresult);
            return; 
        }
        // X - Y    -> Positif pour X > Y
        if(tab1[0]==0 && tab2[0]==0){
            if(!max(tab1,tab2)){
                tabresult[0]=3;
                soustr(tab2,tab1,tabresult);
                return;
            }
        tabresult[0]=2;
        soustr(tab1,tab2,tabresult);
        return;
        }
    }

}

void reverse(int tab[]){
    int i;
    int temp;
    int taille=tab[1]+4;

    for(i=2; i<taille/2; i++){
        temp=tab[i];
        tab[i]=tab[taille-i-1];
        tab[taille-i-1]=temp;
    }
}

//Renvoie 1 si X > Y
int max(int tab1[], int tab2[]){
    int i;
    int taille=tab1[1]+1;
    int taille2=tab2[1]+1;

    if(taille > taille2){
        return 1;
    }

    if(taille < taille2){
        return 0;
    }

    for(i=2; i<=taille; i++){
//printf("Compare: tab1[%d]=%d   et tab2[%d]=%d\n", i, tab1[i], i, tab2[i]);
        if(tab1[i] > tab2[i]){
            return 1;
        }
    }

    return 0;
}

void printtab(int tab[]) {
    int i=2;
    int taille=tab[1]+2;
    int var=i;

    //Effacer les '0' en début de résultat
    while(tab[var] == 0){
        var++;
    }

    for(i=var; i<taille; i++) {
        if (i==0)
        {
            printf("-");
        }
        printf("%d", tab[i]);
    }
    printf("\n");
}

void fill(int tab[], char *var_main){

    char var=*var_main;
    int i=3;

    //Skip espaces avant nombre
    do {
        scanf("%c", &var);
//printf("var: '%c'\n", var);
    } while(var == ' ');

    //Attribution négatif(1)
    if(var == '-') {
        tab[0]=1;
        //Skip espaces entre ' - ' et le nombre
        do {
            scanf("%c", &var);
//printf("var: '%c'\n", var);
        } while(var == ' ');
        tab[2]=var - '0';
        //Attribution positif(0)
    } else {
        tab[0]=0;
        tab[2]=var - '0';
    }

    //Remplissage tab
    scanf("%c", &var);
//printf("var: '%c'\n", var);
    while(var >= '0' && var <= '9') {
        tab[i]=var - '0';
        i++;
        scanf("%c", &var);
//printf("var: '%c'\n", var);
    }
    tab[1]=i-2;

    *var_main=var;

}


int main() {

    int tab1[102]= {0};
    int tab2[102]= {0};
    int tab3[102]= {0};
    int tabresult[1002]= {0};
    int tabfinal[1002]= {0};
    char op1, op2, var;

    fill(tab1,&var);

    //Skip espaces et récupération 1er opérateur
    while(var == ' ') {
        scanf("%c", &var);
    }
    op1=var;

//printtab(tab1);
//printf("operateur1: '%c'\n", op1);

    fill(tab2,&var);

    //Skip espaces et récupération 2e opérateur
    while(var == ' ') {
        scanf("%c", &var);
    }
    op2=var;

//printtab(tab2);
//if(op2!=10) printf("operateur2: '%c'\n", op2);


    //Test 3e opérateur
    if((int)op2 == 10) {
        calcul(tab1,tab2,tabfinal,op1);
//printf("Before reverse: ");
//printtab(tabfinal);
        reverse(tabfinal);
//printf("Result: ");

        if(tabfinal[0]==1){
            printf("-");
        }
        printtab(tabfinal);
        return 0;
    }

    fill(tab3,&var);

//printtab(tab3);


    //Calcul prioritaire de tab2 et tab3 puis tab1 et result
    if((op2 == '*' || op2=='/' || op2=='%') && (op1 != '*' && op1 != '/' && op1 != '%')) {
        calcul(tab2,tab3,tabresult,op2);
//printf("Before reverse 1: ");
//printtab(tabresult);
        reverse(tabresult);
//printf("Result 1: ");
//printtab(tabresult);
        calcul(tab1,tabresult,tabfinal,op1);
//printf("Before reverse 2: ");
//printtab(tabfinal);
        reverse(tabfinal);
//printf("Result 2: ");
        
        if(tabfinal[0]==1){
            printf("-");
        }
        printtab(tabfinal);
        return 0;
    }

    //Calcul de tab1 et tab2 puis tabresult et tab 3
    calcul(tab1,tab2,tabresult,op1);
//printf("Before reverse 1: ");
//printtab(tabresult);
    reverse(tabresult);
//printf("Result 1: ");
//printtab(tabresult);
    calcul(tabresult,tab3,tabfinal,op2);
//printf("Before reverse 2: ");
//printtab(tabfinal);
    reverse(tabfinal);
//printf("Result 2: ");

    if(tabfinal[0]==1){
        printf("-");
    }
    printtab(tabfinal);
    return 0;
}
