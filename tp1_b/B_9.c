/*  
Realizar un programa donde al ingresar una palabra indique por pantalla si es un palindromo o no.
*/
#include <stdio.h>
#include <stdlib.h>
// La idea general es ir contando caracteres mientras que sean iguales, y si no lo son, se termina el ciclo.
int main(){
    char palabra[100];
    printf("Ingrese una palabra: ");
    scanf("%s", palabra);
    int i=0, j=0;
    while(palabra[i]!='\0'){
        i++;
    }
    i--; //Para saber la cantidad precisa de caracteres.
    while(i>=0){
        if(palabra[i]!=palabra[j]){
            printf("La palabra no es un palindromo\n");
            break;
        }
        //Carácter final con inicial, y se van restando y sumando respectivamente los contadores.
        i--;
        j++;
    }
    if(i==-1/* Debido a que al inicio le restamos uno */){
        printf("La palabra es un palindromo\n");
    }
    return 0;
}