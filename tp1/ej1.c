#include<stdio.h>
/* 
Ingresar una palabra y mostar cuantos caracteres tiene
*/
int main(){
    char cadena[20];
    int i = 0;
    scanf("%s", cadena);
    for (/*int i = 0*/; i < 20 && cadena[i]!='\0'; i++);
    printf("\nLa cantidad de caracteres ingresados es: %d \n", i);
    return 0;
}
