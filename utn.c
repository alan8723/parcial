#include "utn.h"
#include <stdio.h>


    //\brief Solicita numero al usuario
    //\param mensaje Es el mensaje a ser mostrado
    //\return numero ingresado por el usuario

int getInt(char mensaje[]){

    int auxiliar;

    printf("%s", mensaje);
    scanf("%d", &auxiliar);

    return auxiliar;

}

    //\brief Solicita un caracter al usuario
    //\param mensaje Es el mensaje a ser mostrado
    //\return caracter ingresado por el usuario

char getChar(char mensaje[]){

    char auxiliar;

    printf("%s", mensaje);
    fflush(stdin);
    scanf("%c", &auxiliar);


    return auxiliar;

}

    //\brief Solicita numero con coma al usuario
    //\param mensaje Es el mensaje a ser mostrado
    //\return numero con coma ingresado por el usuario

float getFloat(char mensaje[]){

    float auxiliar;

    printf("%s", mensaje);
    scanf("%f", &auxiliar);


    return auxiliar;

}

 //\menu de opciones

int menu(){
    int opcion;

    printf("****** menu de opciones ******\n\n");
    printf("-a ALTAS \n");
    printf("-b MODIFICAR \n");
    printf("-c BAJA \n");
    printf("-d INFORMES \n");
    printf("-e SALIR \n");
    printf("seleccione una opcion \n");
    fflush(stdin);
    scanf("%c", &opcion);

    return opcion;
}
