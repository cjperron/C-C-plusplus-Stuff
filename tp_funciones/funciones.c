#include<stdio.h>
#include<stdlib.h>
#include<math.h>
float toKelvin(float);
float toMilimetros(float);
int suma(int,int);
int validar(int,int,int);
int decimalToBinary(int);
void printRange(int,int,int);
float porcentajeDeTotal(int,int);
int main(){
    return 0;
}
/*
♠   1) Realizar una función que 
    reciba una temperatura en grados centígrados y la
    retorne en grados kelvin.
*/
float toKelvin(float grados){
    return grados+273.15;
}
/* 
2) Realizar una función que reciba 
    una distancia en metros y la retorne en
    milimetros.
*/
float toMilimetros(float metros){
    return metros*1000;
}
/*  
3) Realizar una 
    función que reciba dos números enteros y 
    retorne la suma.
*/
int suma(int a, int b){
    return a+b;
}
/*  
4) Realizar una función que valide los resultados 
    de una suma, dado los
    operandos y el resultado.
*/
int validar(int a, int b, int resultado){
    return (a+b)==resultado;
}
/*  
5) Realizar una función que reciba un número 
entero decimal y lo pase a binario.
*/
int decimalToBinary(int num){
    int binario=0;
    for (int i;num>0;i++)
    {
        binario+=(num%2)*pow(10,i);
        num/=2; 
    }
    return binario;
}
/*  
6) Realizar una función que reciba 3 números: inicial, final e incremento. 
La función imprimira los números entre inicial y final , saltando de incremento en incremento.
*/
void printRange(int inicial, int final, int incremento){
    for (int i=inicial;i<=final;i+=incremento) printf("%i\n",i);
}
/* 
7) Realizar una función que reciba dos números: valor y total. 
La función retorna que porcentaje es valor del total.
*/

float porcentajeDeTotal(int valor, int total){
    return (float)valor/total*100; //printf("Porcentaje de a, respecto a b: %.2f%%\n", porcentajeDeTotal(a, b));
}