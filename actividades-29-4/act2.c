/*  
Realizar un programa que a partir del siguiente struct tenga las siguientes funciones:
1.Ingreso de datos
2. Verificación de contraseña (TP1, 20 caracteres máximo)
3. Verificación de nombre de usuario (que no se repita, ni username ni DNI)
4. Buscar datos (dni).
*/
/*
struct datos {
char nombre[16];
char apellido[16];
char dni[8+1];	
short edad;
struct login user;
};
struct login {
	char userName[20+1];
	char userPwd[20+1];
	
};
*/
#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include <string.h>
#include <stdbool.h>
#define max 1
struct login {
	char userName[20+1];
	char userPwd[20+1];
};
struct datos{
    char nombre[16];
    char apellido[16];
    char dni[8+1];	
    short edad;
    struct login user;
};
void ingresarDatos(struct datos users[]);
short verificarContrasena(char []);
short verificarRepeticion(struct datos users[]);
void buscarDatos(struct datos users[]);
int main(){
    struct datos usuarios[max+1];
    int opcion;
    //Menu
    do{
        printf("1. Ingresar datos\n");
        printf("2. Buscar datos\n");
        printf("3. Salir\n");
        printf("Ingrese una opcion: ");
        scanf("%d", &opcion);
        switch(opcion){
            case 1:
                ingresarDatos(usuarios);
                break;
            case 2:
                buscarDatos(usuarios);
                break;
            case 3:
                printf("Saliendo...\n");
                break;
            default:
                printf("Opcion invalida\n");
                break;
        }
    }while(opcion!=3);
    return 0;
}
short verificarContrasena(char pwd[]){
    int i=0, min=0, may=0, num=0, car=0, longi=0;
    //Contar caracteres de la contraseña.
    while(pwd[i]!='\0'){
        i++;
    }
    i--; //Para saber la cantidad precisa de caracteres.
    //Chequeo de caracteres
    while(i>=0){
        if(pwd[i]>='a' && pwd[i]<='z'){
            min++;
        }
        if(pwd[i]>='A' && pwd[i]<='Z'){
            may++;
        }
        if(pwd[i]>='0' && pwd[i]<='9'){
            num++;
        }
        if(pwd[i]<'0' || pwd[i]>'9' && pwd[i]<'A' || pwd[i]>'Z' && pwd[i]<'a' || pwd[i]>'z'){
            car++;
        }
        i--;
    }
    //Chequeo de longitud
    if(i==-1){
        longi=1;
    }
    if(min==0 || may==0 || num==0 || car==0 || longi==0){
        //printf("La contrasena no es segura\n");
        return 0;
    }
    else{
        //printf("La contrasena es segura\n");
        return 1;
    }
}
void ingresarDatos(struct datos users[]){
    short comprobacion = 1;
    for (int i = 0; i < max; i++){
        printf("[%d]\n", i+1);
        do{
            printf("Username: ");
            scanf("%s", users[i].user.userName);
            comprobacion = verificarRepeticion(users);
        } while(comprobacion == 0);
        do{
            printf("Password(mM1$-8c): ");
            scanf("%s", users[i].user.userPwd);
            if (verificarContrasena(users[i].user.userPwd)==0)
            {
                printf("La contraseña no es segura\n");
                comprobacion = 0;
            }
            else comprobacion = 1;
        } while(comprobacion == 0);
            
        do{
            printf("Nombre del usuario: ");
            scanf("%s", users[i].nombre);
            for (int j = 0; users[i].nombre[j] != '\0'; j++)
            {
                if (users[i].nombre[j] < 65 || users[i].nombre[j] > 122) //Me fijo si son letras
                {
                    printf("Nombre invalido\n");
                    comprobacion = 0;
                    break;
                } comprobacion = 1;
            }
        }while(comprobacion == 0);
        do
        {
            printf("Apellido del Usuario: ");
            scanf("%s", users[i].apellido);
            for (int j = 0; users[i].apellido[j] != '\0'; j++)
            {
                if (users[i].apellido[j] < 65 || users[i].apellido[j] > 122) //Me fijo si son letras
                {
                    printf("Apellido invalido!\n");
                    comprobacion = 0;
                    break;
                }
                comprobacion = 1;
            }
        } while (comprobacion == 0);

        do
        {   int j = 0;
            printf("DNI del usuario: ");
            scanf("%s", users[i].dni);
            for (j = 0; users[i].dni[j] != '\0'; j++)
            {
                if (users[i].dni[j] < 48 || users[i].dni[j] > 57) //Me fijo si son numeros
                {
                    printf("DNI invalido!\n");
                    comprobacion = 0;
                    break;
                }
                comprobacion = verificarRepeticion(users);
            }
            if (j<8)
            {
                printf("DNI invalido!\n");
                comprobacion = 0;
            }
        } while (comprobacion == 0);
        do
        {
            printf("Edad del usuario: ");
            scanf("%hd", &users[i].edad);
            if(users[i].edad < 7 || users[i].edad > 100){
                printf("Edad invalida! (7-100)\n");
                comprobacion = 0;
            }
        } while (comprobacion == 0);
        printf("-----------------\n");
    }
}
//Funcion que verifica si se repite el nombre de usuario y el dni. Si no se repite, devuelve 1.
short verificarRepeticion(struct datos users[]){
    for (int i = 0; i < max; i++){
        for (int j = 0; j < max; j++){
            if (i!=j){
                if (strcmp(users[i].user.userName, users[j].user.userName) == 0){
                    printf("El nombre de usuario %s ya existe\n", users[i].user.userName);
                    return 0;
                }
                if (strcmp(users[i].dni, users[j].dni) == 0){
                    printf("El DNI %s ya existe\n", users[i].dni);
                    return 0;
                }
            }
        }
    }
    return 1;
}
void buscarDatos(struct datos users[]){
    char buscar[8+1];
    printf("Ingrese el DNI que desea buscar: ");
    scanf("%s", buscar);
    printf("-----------------\n");
    for (int i = 0; i < max; i++){
        if (strcmp(buscar, users[i].dni) == 0){
            printf("Nombre: %s\n", users[i].nombre);
            printf("Apellido: %s\n", users[i].apellido);
            printf("Edad: %hd\n", users[i].edad);
            printf("-----------------\n");
            return;
        }
    }
    printf("No se encontro el DNI\n");
}