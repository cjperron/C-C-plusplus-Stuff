//2 palabras y me devuelva un 1 si son distintas, y 0 si son iguales
#include<stdio.h>
#include<stdlib.h>
char *word1, *word2;
int main(){
    printf("Escribi la palabra 1: ");scanf("%s", &word1);
    printf("Escribi la palabra 2: ");scanf("%s", &word2);
    if (word1 == word2) printf("Son iguales.\n");
    else printf("Son distintas.\n");
    return 0;}