/*  
Realizar un programa que ordene un array con números enteros 
de menor a mayor o de mayor a menor según lo indique el 
usuario.
*/
#include <stdio.h>
#include <stdlib.h>
#define max 5
int main(){
    int numeros[max], opcion;
    printf("Ingrese los numeros: ");
    for(int i=0;i<max;i++){
        scanf("%d",&numeros[i]);
    }
    printf("Como quiere ordenar los numeros?\n");
    printf("1. De menor a mayor\n");
    printf("2. De mayor a menor\n");
    scanf("%d",&opcion);
    //Según la opción, se ordenan.
    switch(opcion){
        case 1:
            for(int i=0;i<max;i++){
                for(int j=i+1;j<max;j++){
                    if(numeros[i]>numeros[j]){
                        int aux=numeros[i]; //Se necesita un auxiliar para no perder el valor de un número, ya que se va a intercambiar.
                        numeros[i]=numeros[j];
                        numeros[j]=aux;
                    }
                }
            }
            break;
        case 2:
            for(int i=0;i<max;i++){
                for(int j=i+1;j<max;j++){
                    if(numeros[i]<numeros[j]){
                        int aux=numeros[i];
                        numeros[i]=numeros[j];
                        numeros[j]=aux;
                    }
                }
            }
            break;
        default:
            printf("Opcion no valida\n");
            break;
    }
    //Se imprimen los numeros ordenados.
    printf("Los numeros ordenados son: ");
    for(int i=0;i<max;i++){
        printf("%d ",numeros[i]);
    }
    return 0;
}