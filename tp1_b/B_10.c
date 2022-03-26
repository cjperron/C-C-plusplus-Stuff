/*  
Un usuario ingrese una contraseña propuesta y se le indique si incumple con tener: 
a)    Al menos 1 minúscula.
b)    Al menos 1 mayúscula.
c)    Al menos 1 carácter que sea número.
d)    Al menos 1 carácter que no sea ni letra ni número.
e)    Al menos tener 8 caracteres.
*/
#include<stdio.h>
#include<stdlib.h>
int main(){
    char contrasena[100];
    int i=0, min=0, may=0, num=0, car=0, longi=0;
    printf("Ingrese una contrasena: ");
    scanf("%s", contrasena);
    //Contar caracteres de la contraseña.
    while(contrasena[i]!='\0'){
        i++;
    }
    i--; //Para saber la cantidad precisa de caracteres.
    //Chequeo de caracteres
    while(i>=0){
        if(contrasena[i]>='a' && contrasena[i]<='z'){
            min++;
        }
        if(contrasena[i]>='A' && contrasena[i]<='Z'){
            may++;
        }
        if(contrasena[i]>='0' && contrasena[i]<='9'){
            num++;
        }
        if(contrasena[i]<'0' || contrasena[i]>'9' && contrasena[i]<'A' || contrasena[i]>'Z' && contrasena[i]<'a' || contrasena[i]>'z'){
            car++;
        }
        i--;
    }
    //Chequeo de longitud
    if(i==-1){
        longi=1;
    }
    //Imprimir resultados
    if(min==0 || may==0 || num==0 || car==0 || longi==0){
        printf("La contrasena no es segura\n");
    }
    else{
        printf("La contrasena es segura\n");
    }
    return 0;
}