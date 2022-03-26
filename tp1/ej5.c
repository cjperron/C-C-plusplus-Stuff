/* 
Realizar un programa que ingresando un número por teclado,
complete un array con sus factores y los muestre por pantalla.
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    int n, factores[100], cont=0;
    printf("Ingrese un numero: ");
    scanf("%d", &n);
    for ( int i = n; i > 0 ; i--)
    {
        if(n%i==0){
            factores[cont]=i;
            cont++;
        }
    }
    printf("Los factores de %d son: \n", n);
    for (int i = 0; i < cont; i++)
    {
        printf("%d\n", factores[i]);
    }
    return 0;
}