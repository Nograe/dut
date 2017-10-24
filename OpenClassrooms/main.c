#include <stdio.h>

void printtab(int tab[]);
void add(int tab1[], int tab2[], int result[]);
void soustr(int tab1[], int tab2[], int result[]);
void calcul(int tab1[], int tab2[], int tabresult[], char op);
void divid2(int dividend[], int divisor[], int result[]);
void empty(int tab[]);
void reverse(int tab[]);
int max(int tab1[], int tab2[], int option);
void fill(int tab[], char *var_main);
void copy(int model[], int copy[]);

void mult(int tab1[], int tab2[], int result[]) {

    int i,j,k,unit1,unit2,mtp,count,indice;
    int taille1=tab1[1];
    int taille2=tab2[1];
    int temp2[1002]= {0};
    int temp3[1002]= {0};
    temp2[1]=1;
    temp3[1]=1;

    for(i=0,k=taille2+1 ; i<=taille1 && k>=2 ; i++,k--) {
        unit2=tab2[k];
//printf("unit2: %d\n",unit2);

        for(j=taille1+1,count=0; j>=2 && count<taille1; j--,count++) {
            unit1=tab1[j];
//printf("unit1: %d ; ",unit1);
            mtp=unit2*unit1;
//printf("mtp: %d ; ",mtp);
            indice=i+count;
//printf("indice: %d\n",indice);

            if(mtp<10) {
                temp2[2]=mtp;
                temp2[3]=0;
                if(indice==0) {
                    temp2[1]=1;
                } else {
                    temp2[1]=1+indice;
                }
            } else {
                temp2[2]=mtp/10;
                temp2[3]=mtp%10;
                if(indice==0) {
                    temp2[1]=2;
                } else {
                    temp2[1]=2+indice;
                }
            }

//printtab(temp2); printf("+"); printtab(temp3); printf("=");
            add(temp2,temp3,result);
            reverse(result);
//printtab(result); printf("\n");
            copy(result,temp3);
        }
    }
    reverse(result);
}

void divid(int dividend[], int divisor[], int result[], int option) {

    int signe=result[0];
    int previous=0;
    int next=0;
    int taille_divisor=divisor[1];
    int var,i;

    while(max(dividend,divisor,0)){
        previous=next;
        divid2(dividend,divisor,result);
        next=divisor[1];
//printf("%d, %d\n",previous,next);
        if(previous-next > 1 && previous!=0){
            var=result[result[1]+1];
            for(i=0; i<previous-next-1; i++){
            result[1]++;
            result[result[1]+i]=0;
            }
            result[result[1]+1]=var;
        }
        divisor[1]=taille_divisor;
    }

    if(next>divisor[1]){
        result[1]++;
    }

    reverse(result);
    result[0]=signe;

    if(option==1){
        empty(result);
        copy(dividend,result);
        reverse(result);
    }
}

void divid2(int dividend[], int divisor[], int result[]) {

    int temp[1002]={0};
    int count=0;

//printf("dividend: "); printtab(dividend);

    while(max(dividend,divisor,0)){
        divisor[1]++;
    }
    divisor[1]--;
    while(max(dividend,divisor,0)){
        soustr(dividend,divisor,temp); reverse(temp); copy(temp,dividend); empty(temp);
        count++;
    }

    result[1]++;
    result[result[1]+1]=count;

//printf("divisor: "); printtab(divisor); printf("result: "); printtab(result);
}

void modulo(int tab1[], int tab2[], int result[]) {

    if(max(tab2,tab1,0)) {
        copy(tab1,result);
        reverse(result);
        return;
    }

    tab1[0]=0;
    tab2[0]=0;

    divid(tab1,tab2,result,1);

    if(tab1[0]==1 && tab2[0]==0) {
        result[0]=1;
    }

}

void add(int tab1[], int tab2[], int result[]) {

    int i,sum;
    int j=2;
    int retenue=0;
    int taillemax;
    int taille1=tab1[1]+1;
    int taille2=tab2[1]+1;
    if(taille1 >= taille2) {
        taillemax=taille1;
    } else {
        taillemax=taille2;
    }

    for(i=taillemax; i>=2; i--) {
        if(taille1<=1) {
            sum=tab2[taille2]+retenue;
        } else if(taille2<=1) {
            sum=tab1[taille1]+retenue;
        } else {
            sum=tab1[taille1]+tab2[taille2]+retenue;
        }
        retenue=0;
        if (sum<10) {
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

    if(retenue==1) {
        result[j]=1;
        result[1]=taillemax;
    } else {
        result[1]=taillemax-1;
    }

}

void soustr(int tab1[], int tab2[], int result[]) {

    if(max(tab1,tab2,0)==-1) {
        result[0]=0;
        result[1]=1;
        result[2]=0;
        return;
    }

    int signe=result[0];
    int taille1=tab1[1]+1;
    int taille2=tab2[1]+1;
    result[0]=0;

    if(signe == 2 && max(tab2,tab1,0)) {
        result[0]=1;
    }
    if(signe == 3 && max(tab1,tab2,0)) {
        result[0]=1;
    }

    int i,sous;
    int j=2;
    int retenue=0;
    int taillemax;
    if(taille1 >= taille2) {
        taillemax=taille1;
    } else {
        taillemax=taille2;
    }

    for(i=taillemax; i>=2; i--) {
        if(taille1<=1) {
            sous=tab2[taille2]-retenue;
        } else if(taille2<=1) {
            sous=tab1[taille1]-retenue;
        } else {
            sous=tab1[taille1]-tab2[taille2]-retenue;
        }
//printf("Retenue= %d ; ", retenue);
        retenue=0;
        if (sous >= 0) {
            result[j]=sous;
            j++;
        } else {
            result[j]=10+sous;
            retenue++;
            j++;
        }
//printf("tab1[%d]=%d - tab2[%d]=%d=%d\n", taille1, tab1[taille1], taille2, tab2[taille2], result[j-1]);
        taille1--;
        taille2--;
    }

    while(result[taillemax] == 0) {
        taillemax--;
    }

    result[1]=taillemax-1;

}

void calcul(int tab1[], int tab2[], int tabresult[], char op) {

    if(op == '*') {
        if( (tab1[0]==1 && tab2[0]==0) || (tab1[0]==0 && tab2[0]==1) )  {
            tabresult[0]=1;
        }
        if(max(tab1,tab2,0)) {
            mult(tab1,tab2,tabresult);
            return;
        } else {
            mult(tab2,tab1,tabresult);
            return;
        }
    }
    if(op == '/') {
        if(max(tab1,tab2,0)) {
            if( (tab1[0]==1 && tab2[0]==0) || (tab1[0]==0 && tab2[0]==1) ) {
                tabresult[0]=1;
            }
            divid(tab1,tab2,tabresult,0);
            return;
        } else {
            tabresult[1]=1;
            return;
        }
    }
    if(op == '%') {
        modulo(tab1,tab2,tabresult);
        return;
    }
    if(op == '+') {
        // -X + Y   -> Positif pour Y > X
        // => Y-X  si  Y > X
        if(tab1[0]==1 && tab2[0]==0) {
            if(max(tab2,tab1,0)) {
                tabresult[0]=0;
                soustr(tab2,tab1,tabresult);
                return;
            }
            tabresult[0]=3;
            soustr(tab1,tab2,tabresult);
            return;
        }
        // -X + -Y  -> Négatif
        if(tab1[0]==1 && tab2[0]==1) {
            tabresult[0]=1;
            add(tab1,tab2,tabresult);
            return;
        }
        // X + -Y   -> Positif pour X > Y
        if(tab1[0]==0 && tab2[0]==1) {
            tabresult[0]=2;
            soustr(tab1,tab2,tabresult);
            return;
        }
        add(tab1,tab2,tabresult);
        return;
    }
    if(op == '-') {
        // -X - Y   -> Négatif
        if(tab1[0]==1 && tab2[0]==0) {
            tabresult[0]=1;
            add(tab1,tab2,tabresult);
            return;
        }
        // -X - -Y  -> Positif pour Y > X
        // => Y-X  si  Y > X
        if(tab1[0]==1 && tab2[0]==1) {
            if(!max(tab1,tab2,0)) {
                tabresult[0]=0;
                soustr(tab2,tab1,tabresult);
                return;
            }
            tabresult[0]=3;
            soustr(tab1,tab2,tabresult);
            return;
        }
        // X - -Y   -> Positif
        if(tab1[0]==0 && tab2[0]==1) {
            add(tab1,tab2,tabresult);
            return;
        }
        // X - Y    -> Positif pour X > Y
        if(tab1[0]==0 && tab2[0]==0) {
            if(!max(tab1,tab2,0)) {
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

void empty(int tab[]){
    int i;
    for(i=0; i<tab[1]+1; i++){
        tab[i]=0;
    }
}

void copy(int model[], int copy[]) {
    empty(copy);
    int taille=model[1]+2;
    int i;

    for(i=0; i<taille; i++) {
        copy[i]=model[i];
    }
}

void reverse(int tab[]) {
    int i;
    int temp;
    int taille=tab[1]+4;

    for(i=2; i<taille/2; i++) {
        temp=tab[i];
        tab[i]=tab[taille-i-1];
        tab[taille-i-1]=temp;
    }
}

//Renvoie 1 si X > Y
int max(int tab1[], int tab2[], int option) {
    int i;
    int taille=tab1[1]+1;
    int taille2=tab2[1]+1;
    int verif=1;

    if(tab1[0]==0 && tab2[0]==1 && option==1) {
        return 1;
    }

    if(tab1[0]==1 && tab2[0]==0 && option==1) {
        return 0;
    }

    if(taille > taille2) {
        return 1;
    }

    if(taille < taille2) {
        return 0;
    }

    for(i=2; i<=taille; i++) {
//printf("Compare: tab1[%d]=%d   et tab2[%d]=%d\n", i, tab1[i], i, tab2[i]);
        if(tab1[i] > tab2[i]) {
            return 1;
        }
        if(tab1[i] < tab2[i]) {
            return 0;
        }
        if(tab1[i] != tab2[i]) {
            verif=0;
        }
    }
    if(verif==1) {
        return -1;
    }
    return 0;
}

void printtab(int tab[]) {
    int i=2;
    int taille=tab[1]+2;

    if (tab[0]==1) {
        printf("-");
    }

    for(i=2; i<taille; i++) {
        //if(i==2) {printf("-");}
        printf("%d", tab[i]);
    }
    printf("\n");
}

void fill(int tab[], char *var_main) {

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


int main (int argc, char *argv[]){

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

    printtab(tabfinal);
    return 0;
}
