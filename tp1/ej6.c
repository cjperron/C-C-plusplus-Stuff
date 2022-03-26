/* 
Realizar un programa que permita ingresar los datos obtenidos de una
prueba de laboratorio. Antes de recibir los datos, el usuario deberá precisar
la cantidad de datos a ingresar, teniendo un límite de 100 datos.Todos los
datos de la prueba son positivos. El ingreso de datos se termina una vez que
se alcance el máximo de datos a ingresar precisado por el usuario o si el
usuario ingresa un número menor a 0, cualquier evento que pase primero.
Una vez finalizado el ingreso, mostrar por pantalla los datos ingresados y el
promedio de ellos con una precisión decimal de dos dígitos.
*/
#include<stdio.h>
#include<stdlib.h>
#define MAX 100
int main(){
    int datos[MAX], cont=0;
    float promedio, suma=0;
    printf("Ingrese la cantidad de datos a ingresar: ");
    scanf("%d", &cont);
    if(cont>MAX){
        printf("La cantidad de datos ingresados es mayor a %d\n", MAX);
        return 0;
    }
    for (int i = 0; i < cont; i++)
    {
        printf("Ingrese un dato: ");
        scanf("%d", &datos[i]);
        if(datos[i]<0){
            printf("El dato ingresado es menor a 0\n");
            return 0;
        }
        suma+=datos[i];
    }
    promedio=suma/cont;
    printf("Los datos ingresados son: \n");
    for (int i = 0; i < cont; i++)
    {
        printf("%d\n", datos[i]);
    }
    printf("El promedio de los datos ingresados es: %.2f\n", promedio);
    return 0;
}