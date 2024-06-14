#include <stdlib.h>
#include <stdio.h>

int ren=4;
int col=3;

void llenar_precios(int precio[ren][col]){
    precio[0][0]=15;
    precio[0][1]=10;
    precio[0][2]=30;
    precio[1][0]=10;
    precio[1][1]=20;
    precio[1][2]=40;
    precio[2][0]=30;
    precio[2][1]=20;
    precio[2][2]=40;
    precio[3][0]=50;
    precio[3][1]=50;
    precio[3][2]=30;
}

void llenar_cantidad(int cantidad[ren][col]){
    int i,j;
    for(i=0;i<ren;i++){
        for(j=0;j<col;j++){
            cantidad[i][j]=rand()%9+2;
        }
    }
}

void main(){
    char documentacion[1000];
    int precios[ren][col],cantidad[ren][col];
    llenar_cantidad(cantidad);
    llenar_precios(precios);
    FILE*apuntador;
    apuntador=fopen("documentacion.txt","w");
    if(apuntador!=NULL){
        fprintf(apuntador,"%i",precios);
        fputc('\n',apuntador);
        fprintf(apuntador,"%i",cantidad);
        fputc('\n',apuntador);
        fputc('\n',apuntador);
        fclose(apuntador);
    }
}
