// Formateado cortesia de vscode, abrazo.
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <stdbool.h>
#include <ctype.h>
#define max 5
/*
Prototipo para la creacion de usuarios para uar en cajeros.
Datos:
apellido (16 caracteres)
nombre (16 caracteres)
CUIL/CUIT
Si es empleado del banco.
Numeros de tarjeta de credito
Sucursal de la cuenta bancaria:
    -Provincia
    -Localidad/Partido
    -Calle
    -Altura
Clave (cuatro numeros)
*/
struct tarjetaDeCredito
{
    char numeros[16 + 1];
    char codSeg[4 + 1];
};
struct sucursalBancaria
{
    char provincia[16 + 1];
    char localidad[16 + 1];
    char calle[16 + 1];
    char altura[4 + 1];
};
struct Usuarios
{
    char apellido[16 + 1];
    char nombre[16 + 1];
    char CUIL[13 + 1]; // o CUIT, xx-xxxxxxxx-x
    char esEmpleado[1 + 1];
    struct tarjetaDeCredito tarjeta;
    struct sucursalBancaria sucursal;
    char clave[4 + 1];
};
void flushear_stdin(void);
//tipo: 1 NO empleado, 2 empleado
void mostrarInfo(struct Usuarios[], int*, int);
void ingresarInfo(struct Usuarios[], int *);
void modificarSucursal(struct Usuarios[], int *);
void buscarCuenta(struct Usuarios[], int *);
void admin(struct Usuarios[], int*);
short verificarRepeticion(struct Usuarios[], int , int);
// tipo: 1 es letras, 2 numeros, 3 cuil, 4 caracteres raros.
short verificarCadena(char[], short); // para no repetir tanto la verificacion de cadenas.

int main()
{
    short opcion;
    int lastUser = 0;
    int *pLastUser = &lastUser; // crazy no? un puntero. -> 🥱
    struct Usuarios clientes[max + 1];
    do
    {
        system("cls");
        //printf("%d", *pLastUser);
        system("cls");
        printf("\tBienvenido al Banco DiNardo & Friends\nIngrese una opcion:\n");
        printf("1. Crear cuenta\n");
        printf("2. Modificar la sucursal\n");
        printf("3. Buscar cuenta\n");
        printf("4. Admin\n");
        printf("5. Salir\n");
        scanf("%hd", &opcion);
        switch (opcion)
        {
        case 1:
            ingresarInfo(clientes, pLastUser);
            lastUser++;
            break;
        case 2:
            modificarSucursal(clientes, pLastUser);
            break;
        case 3:
            buscarCuenta(clientes, pLastUser);
            break;
        case 4:
            admin(clientes, pLastUser);
            break;
        case 5:
            printf("Presione una tecla para continuar...\n");
            break;
        default:
            printf("Opcion no valida");
            break;
        }
    } while (opcion != 5);
    while(!kbhit());
    return 0;
}
void ingresarInfo(struct Usuarios usuarios[], int *pLastUser)
{
    short comprobacion;
    system("cls");
    printf("\tCrear cuenta\nIngrese:\n");
    if(*pLastUser == max)
    {
        printf("No hay mas espacio para crear cuentas.\n");
        return;
    }
        // Nombre
        do
        {
            comprobacion = 1;
            printf("Nombre: ");
            scanf("%s", usuarios[*pLastUser].nombre);
            comprobacion = verificarCadena(usuarios[*pLastUser].nombre, 1);
        } while (comprobacion == 0);
        // Apellido
        do
        {
            comprobacion = 1;
            printf("Apellido: ");
            scanf("%s", usuarios[*pLastUser].apellido);
            comprobacion = verificarCadena(usuarios[*pLastUser].apellido, 1);
        } while (comprobacion == 0);
        // CUIL/CUIT
        do
        {
            comprobacion = 1;
            printf("CUIL/CUIT: ");
            scanf("%s", usuarios[*pLastUser].CUIL);
            comprobacion = verificarCadena(usuarios[*pLastUser].CUIL, 3); // verificacion exclusiva del cuil.
            // Para evitar 2 mensajes de error. (en caso de que se cumplan las 2 cosas)
            if (comprobacion == 0) continue; // verifico si se repite HASTA el ultimo usuario registrado.
            comprobacion = verificarRepeticion(usuarios, *pLastUser, 1);
        } while (comprobacion == 0);
        // Es empleado del banco
        do
        {
            comprobacion = 1;
            printf("Es empleado del banco? (s/n): ");
            scanf("%s", usuarios[*pLastUser].esEmpleado);
            usuarios[*pLastUser].esEmpleado[0] = tolower(usuarios[*pLastUser].esEmpleado[0]);
            if (usuarios[*pLastUser].esEmpleado[0] != 's' && usuarios[*pLastUser].esEmpleado[0] != 'n')
            {
                printf("Ingrese 's' o 'n'\n");
                comprobacion = 0;
            }
        } while (comprobacion == 0);
        // Tarjeta de credito
        // Los numeros
        do
        {
            comprobacion = 1;
            printf("Numeros de tarjeta de credito: ");
            scanf("%s", usuarios[*pLastUser].tarjeta.numeros);
            comprobacion = verificarCadena(usuarios[*pLastUser].tarjeta.numeros, 2);
            // Para evitar 2 mensajes de error.
            if (comprobacion == 0) continue;
            comprobacion = verificarRepeticion(usuarios, *pLastUser, 2);
            if (comprobacion == 0) continue;
            if (strlen(usuarios[*pLastUser].tarjeta.numeros) < 16 || strlen(usuarios[*pLastUser].tarjeta.numeros) > 16)
            {
                printf("Invalido\n");
                comprobacion = 0;
                continue;
            }
        } while (comprobacion == 0);
        // asigno la clave
        for (int j = 12; j < 16; j++)
        {
            for (int k = 0; k < 4; k++)
                usuarios[*pLastUser].clave[k] = usuarios[*pLastUser].tarjeta.numeros[j];
        }
        // El codigo de seguridad
        do
        {
            printf("Codigo de seguridad: ");
            scanf("%s", usuarios[*pLastUser].tarjeta.codSeg);
            comprobacion = verificarCadena(usuarios[*pLastUser].tarjeta.codSeg, 2);
        } while (comprobacion == 0);
        // Sucursal
        if (usuarios[*pLastUser].esEmpleado[0] == 's')
        {
            strcpy(usuarios[*pLastUser].sucursal.provincia, "Buenos Aires");
            strcpy(usuarios[*pLastUser].sucursal.localidad, "La Plata");
            strcpy(usuarios[*pLastUser].sucursal.calle, "Calle 50");
            strcpy(usuarios[*pLastUser].sucursal.altura, "642");
        }
        else
        {
            // Provincia
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("Provincia: ");
                scanf("%[^\n]s", usuarios[*pLastUser].sucursal.provincia);
                comprobacion = verificarCadena(usuarios[*pLastUser].sucursal.provincia, 1); // Compruebo si no tienen caracteres extraños.
            } while (comprobacion == 0);
            // Localidad
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("\nLocalidad: ");
                scanf("%[^\n]s", usuarios[*pLastUser].sucursal.localidad);
                comprobacion = verificarCadena(usuarios[*pLastUser].sucursal.localidad, 1);
            } while (comprobacion == 0);
            // Calle
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("\nCalle: ");
                scanf("%[^\n]s", usuarios[*pLastUser].sucursal.calle);
                comprobacion = verificarCadena(usuarios[*pLastUser].sucursal.calle, 4);
            } while (comprobacion == 0);
            // Altura
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("\nAltura: ");
                scanf("%[^\n]s", usuarios[*pLastUser].sucursal.altura);
                comprobacion = verificarCadena(usuarios[*pLastUser].sucursal.altura, 2);
            } while (comprobacion == 0);
        }
    *pLastUser++;
    return;
}
//tipo 1 CUIL, 2 TARJETA
short verificarRepeticion(struct Usuarios usuarios[], int pLastUser, int tipo)
{
    if (tipo == 1)
    {
        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max; j++)
            {
                if(i==pLastUser) return 1;
                if (i == j)
                    continue;
                if (strcmp(usuarios[i].CUIL, usuarios[j].CUIL) == 0)
                {
                    printf("\n\tError: El CUIL ya existe.\n");
                    return 0;
                }
            }
        }
    }
    else if (tipo == 2)
    {
        for (int i = 0; i < max; i++)
        {
            for (int j = 0; j < max; j++)
            {
                if(i==pLastUser) return 1;
                if (i == j) continue;
                if (strcmp(usuarios[i].tarjeta.numeros, usuarios[j].tarjeta.numeros) == 0)
                {
                    printf("\n\tError: La tarjeta de credito ya existe.\n");
                    return 0;
                }
            }
        }
    }
    return 1;
}
void modificarSucursal(struct Usuarios usuarios[], int *pLastUser)
{
    system("cls");
    short comprobacion;
    char buffer[100];
    printf("CUIL: \n");
    scanf("%s", buffer);
    for(int i=0;i<*pLastUser;i++){
        if(strcmp(usuarios[i].CUIL, buffer)==0){
            printf("\nUsuario encontrado\n");
            // Provincia
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("Provincia: ");
                scanf("%[^\n]s", usuarios[i].sucursal.provincia);
                comprobacion = verificarCadena(usuarios[i].sucursal.provincia, 1); // Compruebo si no tienen caracteres extraños.
            } while (comprobacion == 0);
            // Localidad
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("\nLocalidad: ");
                scanf("%[^\n]s", usuarios[i].sucursal.localidad);
                comprobacion = verificarCadena(usuarios[i].sucursal.localidad, 4);
            } while (comprobacion == 0);
            // Calle
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("\nCalle: ");
                scanf("%[^\n]s", usuarios[i].sucursal.calle);
                comprobacion = verificarCadena(usuarios[i].sucursal.calle, 4);
            } while (comprobacion == 0);
            // Altura
            flushear_stdin();
            do
            {
                comprobacion = 1;
                printf("\nAltura: ");
                scanf("%[^\n]s", usuarios[i].sucursal.altura);
                comprobacion = verificarCadena(usuarios[i].sucursal.altura, 2);
            } while (comprobacion == 0);
            break;
    }
    }
    
    return;
}
void buscarCuenta(struct Usuarios usuarios[], int *pLastUser)
{
    system("cls");
    printf("Ingrese el CUIL de cuenta: ");
    char buffer[100];
    scanf("%s", buffer);
    for(int i=0;i<*pLastUser;i++)
    {
        if(strcmp(usuarios[i].CUIL, buffer)==0)
        {
            printf("\n\tUsuario encontrado:\n");
            printf("%s\t%s\n\n", usuarios[i].nombre, usuarios[i].apellido);
            while(!kbhit());
            return;
        }
    }
    printf("\nNo se encontro ningun usuario.\n");
    while(!kbhit());
    return;
}
void admin(struct Usuarios usuarios[], int* pLastUser)
{
    char buffer[100];
    char opcion[2];
    system("cls");
    printf("\tAdministrador\n");
    printf("Ingrese usuario: ");
    scanf("%s", buffer);
    if(strcmp(buffer, "admin1")!=0){
        while(!kbhit());
        return;
    } 
    printf("Ingrese contrasena: ");
    scanf("%s", buffer);
    if(strcmp(buffer, "3.14#saBado")!=0){
        while(!kbhit());
        return;
    }
    flushear_stdin();
    system("cls");
    printf("\tAdmin Mode\n");
    printf("1. Mostrar todos los datos de los usuarios (empleados no incluidos)\n");
    printf("2. Mostrar Empleados.\n");
    printf("3. Salir\n");
    do{
    scanf("%s", opcion);
    if(opcion[0]=='1'){
        mostrarInfo(usuarios, pLastUser, 1);
        while(!kbhit());
    }
    else if(opcion[0]=='2'){
        mostrarInfo(usuarios, pLastUser, 2);
        while(!kbhit());
    }
    else if(opcion[0]=='3'){
        while(!kbhit());
        return;
    }
    else{
        printf("Invalido\n");
    }
    } while(opcion[0]!='1'&& opcion[0]!='2'&& opcion[0]!='3');
    return;
}
void flushear_stdin(void){
    int c;
    do{
        c=getchar();
    } while(c!='\n' && c!= EOF);
}
short verificarCadena(char cadena[], short tipo){
    if(strlen(cadena)==0){
        printf("Invalido\n");
        return 0;
    }
    if (tipo == 1)
    {
        for (int i = 0; cadena[i] != '\0'; i++)
        {
            if ((cadena[i] < 'A' || cadena[i] > 'z') && cadena[i]!=' ') // Me fijo si son letras
            {
                printf("Invalido\n");
                return 0;
            }
        }
        return 1;
    }
    if (tipo == 2)
    {
        for (int i = 0; cadena[i] != '\0'; i++)
        {
            if (cadena[i] < 48 || cadena[i] > 57) // Me fijo si son numeros
            {
                printf("Invalido!\n");
                return 0;
            }
        }
        return 1;
    }
    if (tipo == 3)
    {
        if (strlen(cadena) != 13) return 0;
        for (int i = 0; i < 13; i++)
        {
            if (i == 2 || i == 11)
            {
                if (cadena[i] != '-')
                {
                    printf("Invalido\n");
                    return 0;
                }
                continue;
            }
            if (cadena[i] < 48 || cadena[i] > 57) // Me fijo si son numeros
            {
                printf("Invalido\n");
                return 0;
            }
        }
            return 1;
    }
    if (tipo == 4)
    {
        char caracteresRaros[24] = {'!', '@', '#', '$', '%', '^', '&', '*', '(', ')', '_', '+', '-', '=', '{', '}', '|', ':', ';', '<', '>', '?', '/', ','};
        for (int i = 0; cadena[i] != '\0'; i++)
        {
            for (int j = 0; j < 23; j++)
            {
                if (cadena[i] == caracteresRaros[j])
                {
                    printf("Invalido\n");
                    return 0;
                }
            }
        }
    }
    return 1;
}
void mostrarInfo(struct Usuarios usuarios[], int* pLastUser, int tipo){
    if(tipo==1){
    for(int i=0;i<*pLastUser;i++){
            if(usuarios[i].esEmpleado[0]=='n'){
            printf("Usuario: %d\nNombre %s\n",i+1, usuarios[i].nombre);
            printf("Apellido: %s\n", usuarios[i].apellido);
            printf("CUIL: %s\n", usuarios[i].CUIL);
            printf("Tarjeta:\nNumeros: %s\n",usuarios[i].tarjeta.numeros);
            printf("Codigo de Seguridad: %s\n",usuarios[i].tarjeta.codSeg);
            printf("Sucursal:\nProvincia: %s\n", usuarios[i].sucursal.provincia);
            printf("Localidad: %s\n", usuarios[i].sucursal.localidad);
            printf("Calle: %s\n", usuarios[i].sucursal.calle);
            printf("Altura: %s\n", usuarios[i].sucursal.altura);
            }
    }
    }
    if(tipo==2){
        for(int i=0;i<*pLastUser;i++){
            if(usuarios[i].esEmpleado[0]=='s'){
            printf("Usuario: %d\nNombre %s\n",i+1, usuarios[i].nombre);
            printf("Apellido: %s\n", usuarios[i].apellido);
            printf("CUIL: %s\n", usuarios[i].CUIL);
            printf("Tarjeta:\nNumeros: %s\n",usuarios[i].tarjeta.numeros);
            printf("Codigo de Seguridad: %s\n",usuarios[i].tarjeta.codSeg);
            printf("Sucursal:\nProvincia: %s\n", usuarios[i].sucursal.provincia);
            printf("Localidad: %s\n", usuarios[i].sucursal.localidad);
            printf("Calle: %s\n", usuarios[i].sucursal.calle);
            printf("Altura: %s\n", usuarios[i].sucursal.altura);
            }
    }
    }
    return;
}