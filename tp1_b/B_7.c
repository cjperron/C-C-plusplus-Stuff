/*
Realizar un programa que al ingresar una cadena de caracteres
se indique la cantidad de caracteres tipeados.
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    char cadena[100];
    printf("Ingrese una cadena de caracteres: ");
    scanf("%s", cadena);
    for(int i=0; i<100; i++){
        if(cadena[i]=='\0'){
            printf("La cadena tiene %d caracteres\n", i);
            break;
        }
    }
    return 0;
}