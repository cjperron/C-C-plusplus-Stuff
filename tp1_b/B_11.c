/*  
Realizar un programa que funcione como un strcmp.
*/
#include <stdio.h>
#include <stdlib.h>
int main(){
    char a[100],b[100];
    int i=0,j=0,k=0;
    printf("Ingrese una cadena: ");
    scanf("%s",a);
    printf("Ingrese otra cadena: ");
    scanf("%s",b);
    //Comparar caracteres
    while(a[i]!='\0'){
        i++;
    }
    while(b[j]!='\0'){
        j++;
    }
    if(i!=j){
        printf("Las cadenas no son iguales\n");
    }
    /* En caso de que la cantidad de caracteres coincida se compraran carácter a carácter. */
    else{
        while(k<i){
            if(a[k]!=b[k]){
                printf("Las cadenas no son iguales\n");
                break;
            }
            k++;
        }
        if(k==i){
            printf("Las cadenas son iguales\n");
        }
    }
    return 0;
}