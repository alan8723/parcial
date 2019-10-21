#include <stdio.h>
#include <stdlib.h>
#include "utn.h"
#define CANTIDAD 5
#define TAM 100

int main()
{
    eCategoria categoria[CANTIDAD] = {{1, "mesa"}, {2, "azar"}, {3, "estrategia"}, {4, "salon"}, {4, "magia"}};
    eJuegos juegos [CANTIDAD] = {{1, "juego1", 450.23, 1 }, {2, "juego2", 330.55, 5}, {3, "juego3", 280.85, 3}, {4,"juego4", 900, 2}};
    eCliente clientes[TAM]  = {1, "pedro", "sanchez", 'm', 42232318, 1};

    inicializarClientes(clientes, TAM);

    char salir = 'n';
    int ultimoCodigo = 0;
    int todoOk;
    char option;


      do{

        switch(menu()){

        case 'a':

            printf("****** ALTAS ****** \n\n");
            todoOk = altaCliente(clientes, TAM, ultimoCodigo);
            if(todoOk){
                ultimoCodigo ++;
            }
            break;
        case 'b':
            printf("****** Bajas ******\n\n");
            ModificarCliente(clientes, TAM);
            break;
        case 'c':
            printf("****** Modificaciones ******\n\n");
            bajaCliente(clientes, TAM);
            break;
        case 'd':
             ordenarCLientes(clientes, TAM);
             mostrarClientes(clientes, TAM);

            break;
        case 'e':
            printf("******ALQUILERES******\n\n");
            printf("a- ALTA");
            fflush(stdin);
            scanf("%c", option);
            switch (option){
            case 'a':
                //altaAlquiler();
                break;

            }
        case 'f':
            printf("cancelar salir 'n' confirmar ingrese cualquier otra letra.\n");
            fflush(stdin);
            salir = getche();
            break;
        default:
            printf("error al ingresar opcion");
    }
    system("pause");
    system("cls");
    }
    while(salir == 'n');

    return 0;
}
