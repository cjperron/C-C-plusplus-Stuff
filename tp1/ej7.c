/*
Realizar un programa que busque un número dentro de un array de 7
números enteros positivos recibidos por teclado.  
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, numeros[7], cont=0;
    printf("Ingrese el numero a buscar: ");
    scanf("%d", &n);
    for (int i = 0; i < 7; i++)
    {
        printf("Ingrese un numero: ");
        scanf("%d", &numeros[i]);
        if(numeros[i]>0){
            cont++;
        }
    }
    printf("Los numeros ingresados son: \n");
    for (int i = 0; i < cont; i++)
    {
        printf("%d\n", numeros[i]);
    }
    printf("El numero buscado es: %d\n", n);
    for (int i = 0; i < cont; i++)
    {
        if(n==numeros[i]){
            printf("El numero %d se encuentra en la posicion %d del array\n", n, i);
        }
    }
    return 0;
}