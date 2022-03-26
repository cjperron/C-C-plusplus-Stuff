/*  
Realizar un programa que ingrese 5 números enteros en un array y 5
números enteros en otro. El programa deberá determinar cuántos números
del primer array se repiten en el segundo
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, numeros1[5],numeros2[5], cont=0;
    printf("Ingrese los 5 numeros enteros del primer array: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el numero [%d]: ", i+1);
        scanf("%d", &numeros1[i]);
    }
    printf("Ingrese los 5 numeros enteros del segundo array: \n");
    for (int i = 0; i < 5; i++)
    {
        printf("Ingrese el numero [%d]: ", i+1);
        scanf("%d", &numeros2[i]);
    }
    for (int i = 0; i < 5; i++)
    {
        for (int j = 0; j < 5; j++)
        {
            if(numeros1[i]==numeros2[j]){
                cont++;
            }
        }
    }
    printf("La cantidad de numeros repetidos es: %d\n", cont);
    return 0;
}