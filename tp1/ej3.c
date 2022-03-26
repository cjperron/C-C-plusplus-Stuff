/* Ingresando 33 numeros enteros, el programa debera determinar, cuantos son primos, impares, negativos, ceros, promedio de pares, maximo, minimo, porcentaje de menores a 73*/
#include<stdio.h>
#define numero 4
int isPrime(int n);
int comprobarPrimo(int n[]);
int comprobarImpares(int n[]);
int comprobarNegativos(int n[]);
int comprobacionCeros(int n[]);
int comprobarMaximo(int n[]);
int comprobarMinimo(int n[]);
float porcentajeMenor73(int n[]);
double comprobarPares(int n[]);
int main(){
    int numeros[numero];
    int negativos, ceros, impares, maximo, minimo, primos, g=0;
    double promedioPares;
    float porcentaje73;
    for (int i = 0; i < numero; i++)
    {
        printf("Ingrese el numero[%d]: ", i+1);
        scanf("%d", &numeros[i]);
    }
    negativos = comprobarNegativos(numeros);
    ceros = comprobacionCeros(numeros);
    impares = comprobarImpares(numeros);
    promedioPares = comprobarPares(numeros);
    maximo = comprobarMaximo(numeros);
    minimo = comprobarMinimo(numeros);
    porcentaje73 = porcentajeMenor73(numeros);
    primos = comprobarPrimo(numeros);

    printf("\nCantidad de Primos: %d \n", primos);
    printf("Cantidad de Negativos: %d \n", negativos);
    printf("Cantidad de Ceros: %d \n", ceros);
    printf("Cantidad de Impares: %d \n", impares);
    printf("Promedio de pares: %f \n", promedioPares);
    printf("Maximo: %d \n", maximo);
    printf("Minimo: %d \n", minimo);
    printf("Porcentaje menor de 73: %f \n", porcentaje73);

    return 0;
}

int isPrime(int n){
    int g = 0;
    for (int i = n; i >= 1; i--)
    {
        if (n / i == n || n/i == 1)
        {
            g++;
        }
    }
    if (g == 2)
    {
        return 1;
    }else{
        return 0;
    }
}
int comprobarPrimo(int n[]){
    int primo=0;
    for (int i = 0; i < numero; i++)
    {
        if (isPrime(n[i]) == 1)
        {
            primo++;
        }
        
    }
    
    return primo;
}
int comprobarImpares(int n[]){
    int g=0;
    for (int i = 0; i < numero; i++)
    {
        if (n[i] % 2 != 0)
        {
            g++;
        }
        
    }
    return g;
}
int comprobarNegativos(int n[]){
    int g=0;
    for (int  i = 0; i < numero; i++)
    {
        if (n[i]<0)
        {
            g++;
        } 
    }
    return g;
}
int comprobacionCeros(int n[]){
    int g=0;
    for (int  i = 0; i < numero; i++)
    {
        if (n[i] == 0)
        {
            g++;
        }
        
    }
    return g;
}
double comprobarPares(int n[]){
    int g=0, suma=0;
    for (int i = 0; i < numero; i++)
    {
        if (n[i] % 2 == 0)
        {
            suma += n[i];
            g++;
        } 
    }
        suma /= g;
    return suma;
}
int comprobarMaximo(int n[]){
    int g=0, maximo=0;
    for (int i = 0; i < numero; i++)
    {
        if (n[i] > g)
        {
            maximo = n[i];
            g = n[i];
        }
        
    }
    return maximo;
}
int comprobarMinimo(int n[]){
    int g= 32767;
    int minimo=0;
    for (int i = 0; i < numero; i++)
    {
        if (n[i] < g)
        {
            minimo = n[i];
            g = n[i];
        } 
    }
    return minimo;
}
float porcentajeMenor73(int n[]){
    int g=0;
    for (int i = 0; i <= numero; i++)
    {
        if (n[i] <= 73)
        {
            g++;
        }
        
    }
    return g*100/numero;
}
