/*  
Realizar un programa donde al ingresar un número indique por 
pantalla si es palindromo o no.
*/
#include <stdio.h>
#include <stdlib.h>
unsigned int capicua(unsigned int n)
{
unsigned int invertido = 0;
for (unsigned int i = n; i > 0; i /= 10)
invertido = invertido*10 + i%10;
// Devuelve true si el número es capicua
return (n==invertido);
}
// No se puede usar con numeros muy grandes.
int main(){
    unsigned int numero;
    printf("Ingrese un numero: ");
    scanf("%d", &numero);
    if(capicua(numero)){
        printf("El numero %d es capicua\n", numero);
    }else{
        printf("El numero %d no es capicua\n", numero);
    }
    return 0;
}