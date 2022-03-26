/* Realizar un programa, que dada una serie 7 de números 
ingresados por teclado a un array, y un número específico, 
determine cuántos números del array son múltiplos del divisor
(número específico). */
#include<stdio.h>
#include<stdlib.h>
#define N 7
int main(){
    int n[N], div, cont=0;
    for(int i=0; i<N; i++){
        printf("Ingrese el numero[%d]: ", i+1);
        scanf("%d", &n[i]);
    }
    printf("Ingrese el divisor: ");
    scanf("%d", &div);
    for (int i = 0; i < N; i++)
    {
        if (n[i]%div==0)
        {
            cont++;
        } 
    }
    printf("El numero de multiplos es: %d", cont);
    return 0;
}