#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define max 100
struct socio
{
    char apellido[20];
    char dni[9];
    char nDeSocio[4];
};
void ingresarDatos(struct socio socios[]);
void genNSocio(struct socio socios[]);
void mostrarDatos(struct socio socios[]);
int main()
{
    printf("Ingrese los datos:\n");
    struct socio socios[max+1];
    //Menu de opciones
    int opcion;
    do
    {
        printf("1. Ingresar datos\n");
        printf("2. Mostrar datos\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
            case 1:
                ingresarDatos(socios);
                genNSocio(socios);
                break;
            case 2:
                mostrarDatos(socios);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    } while(opcion!=3);
    return 0;
}
void ingresarDatos(struct socio socios[])
{
    short comprobacion = 1;
    for (int i = 0; i < max; i++)
    {
        do
        {
            printf("Apellido del socio: ");
            scanf("%s", socios[i].apellido);
            for (int j = 0; socios[i].apellido[j] != '\0'; j++)
            {
                if (socios[i].apellido[j] < 65 || socios[i].apellido[j] > 122) //Me fijo si son letras
                {
                    printf("Input invalido!\n");
                    comprobacion = 0;
                    break;
                }
                comprobacion = 1;
            }
        } while (comprobacion == 0);

        do
        {
            printf("DNI del socio (8 digitos): ");
            scanf("%s", socios[i].dni);
                if (socios[i].dni[0] == '-') //Me fijo si es un guion, es decir si es negativo
                {
                    printf("Saliendo de 'Ingresar datos'...\n");
                    return;
                }
            for (int j = 0; socios[i].dni[j] != '\0'; j++)
            {
                if (socios[i].dni[j] < 48 || socios[i].dni[j] > 57) //Me fijo si son numeros
                {
                    printf("Input invalido!\n");
                    comprobacion = 0;
                    break;
                }
                comprobacion = 1;
            }
        } while (comprobacion == 0);
        printf("-----------------\n");
    }
}
//Funcion que genera el numero de socio, son 4 caracteres, la primera letra del apellido, y los ultimos 3 numeros del dni.
void genNSocio(struct socio socios[])
{
    for (int i = 0; i < max; i++)
    {
        socios[i].nDeSocio[0] = socios[i].apellido[0];
        socios[i].nDeSocio[1] = socios[i].dni[5];
        socios[i].nDeSocio[2] = socios[i].dni[6];
        socios[i].nDeSocio[3] = socios[i].dni[7];
        //printf("Numero de socio: %s\n", socios[i].nDeSocio);
    }
}
void mostrarDatos(struct socio socios[])
{
    for (int i = 0; i < max; i++)
    {
        printf("Apellido: %s\n", socios[i].apellido);
        printf("DNI: %s\n", socios[i].dni);
        printf("Numero de socio: ");
        for (int j = 0; j < 4; j++)
        {
            printf("%c", socios[i].nDeSocio[j]);
        }
        printf("\n----------------\n");
    }
}
