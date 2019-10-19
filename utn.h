#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct{
    int codigo;
    char descripcion[51];
    float importe;
    int idCategoria;
}eJuegos;

typedef struct{
    int id;
    char descripcion[51];
}eCategoria;

typedef struct{
    int codigo;
    char nombre[51];
    char apellido[51];
    char sexo;
    int telefono;
    int isEmpty;
}eCliente;

typedef struct{
    int dia;
    int mes;
    int anio;
}eFecha;

typedef struct{
    int codigoDeAlquiler;
    int codigoDeJuego;
    int codigoDeCliente;
    eFecha fecha;
}eAlquileres;

void mostrarCliente(eCliente x);
void inicializarClientes(eCliente vec[], int tam);
int altaCliente(eCliente vec[], int tam, int codigo);
eCliente newCliente(int codigo,char nombre[],char apellido[],char sexo,int telefono);
int buscarLibre(eCliente vec[], int tam);
void mostrarClientes(eCliente vec[], int tam);
int buscarCliente(int codigo, eCliente vec[], int tam);
int bajaCliente(eCliente vec[], int tam);
int ModificarCliente(eCliente vec[], int tam);

char menu();

//menu de opcionees
char menu(){
    char opcion;

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


//muestra un cliente
//parametro eCliente
void mostrarCliente(eCliente x){
    printf("%d %10s, %10s, %2c, %10d \n", x.codigo, x.nombre, x.apellido, x.sexo, x.telefono);
}

//inicializa el vector de clientes cambiando el estado
//parametro el vector de clientes y el tamaño
void inicializarClientes(eCliente vec[], int tam)
{
    for(int i = 0; i < tam; i++)
    {
        vec[i].isEmpty = 1;
    }
}
//da de alta un nuevo cliente
//parametro el vector de clientes y el tamaño y el codigo
int altaCliente(eCliente vec[], int tam, int codigo){

    int todoOk = 0;
    int indice;
    char nombre[51];
    char apellido[51];
    char sexo;
    int telefono;


    system("cls");

    printf("*****Alta CLiente*****\n\n");

    indice = buscarLibre(vec, tam);

     if( indice == -1)
    {
        printf("\nSistema completo\n\n");
    }
    else
    {
        printf("Ingrese nombre: ");
        fflush(stdin);
        gets(nombre);

        printf("Ingrese apellido: ");
        gets(apellido);

        printf("Ingrese sexo: ");
        fflush(stdin);
        scanf("%c", &sexo);

        printf("ingrese telefono: ");
        scanf("%d", &telefono);

        }



        vec[indice] = newCliente(codigo, nombre, apellido, sexo, telefono);
        todoOk = 1;
        printf("Alta exitosa!!\n\n");
    }

//busca en el vector un indice que este libre
//parametro el vector de clientes y el tamaño
int buscarLibre(eCliente vec[], int tam){
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 1 )
        {
            indice = i;
            break;
        }
    }
    return indice;
}

//crea un auxiliar de cliente
//parametro los datos del cliente
eCliente newCliente(
    int codigo,
    char nombre[],
    char apellido[],
    char sexo,
    int telefono
    )
{

    eCliente cl;
    cl.codigo = codigo;
    strcpy(cl.nombre, nombre);
    strcpy(cl.apellido, apellido);
    cl.sexo = sexo;
    cl.telefono = telefono;
    cl.isEmpty = 0;

    return cl;
}

// muestra todos los clientes tienen alta
//parametro el vector de clientes y el tamaño
void mostrarClientes(eCliente vec[], int tam)

{

    int flag = 0;
    system("cls");

    printf(" Codigo    nombre    apellido   Sexo  telefono\n\n");

    for(int i=0; i < tam; i++)
    {
        if( vec[i].isEmpty == 0)
        {
            mostrarCliente(vec[i]);
            flag = 1;
        }
    }

    if( flag == 0)
    {
        printf("\nNo hay Clientes que mostrar\n");
    }

    printf("\n\n");
}

//da de baja un cliente
//parametro el vector de clientes y el tamaño
int bajaCliente(eCliente vec[], int tam)
{
    int todoOk = 0;
    int codigo;
    int indice;
    char confirma;
    system("cls");
    printf("***** Baja CLiente *****\n\n");
    printf("Ingrese codigo: ");
    scanf("%d", &codigo);

    indice = buscarCliente(codigo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un alumno con ese legajo\n\n");

    }
    else
    {
        mostrarCliente(vec[indice]);

        printf("\nConfirma baja? 's' para confirmar \n");
        fflush(stdin);
        scanf("%c", &confirma);

        if( confirma == 's')
        {
            vec[indice].isEmpty = 1;
            todoOk = 1;
            printf("Baja exitosa!!!");
        }
        else
        {
            printf("Se ha cancelado la operacion");
        }
    }

    return todoOk;
}

//busca un cliente por su codigo
//parametro el vector clientes y el tamaño y el codigo
int buscarCliente(int codigo, eCliente vec[], int tam)
{
    int indice = -1;

    for(int i=0; i < tam; i++)
    {
        if( vec[i].codigo == codigo && vec[i].isEmpty == 0)
        {
            indice = i;
            break;
        }
    }
    return indice;
}
//modifica los detos de algun cliente
//parametro el vector de clientes y el tamaño
int ModificarCliente(eCliente vec[], int tam)
{

    int todoOk = 0;
    int codigo;
    int indice;
    char nombre[51];
    char apellido[51];
    system("cls");
    printf("***** Modificar Cliente *****\n\n");
    printf("Ingrese codigo: ");
    scanf("%d", &codigo);
    int opcion;

    indice = buscarCliente(codigo, vec, tam);

    if( indice == -1)
    {
        printf("No existe un Cliente con ese codigo\n\n");

    }
    else
    {

        mostrarCliente(vec[indice]);

        printf("1- Modificar nombre\n");
        printf("2- Modificar apellido\n");
        printf("3- Modificar telefono\n");
        printf("4- salir");
        printf("Ingrese opcion: ");
        scanf("%d", &opcion);
        switch(opcion)
        {
        case 1:
            printf("Ingrese nuevo nombre: ");
            fflush(stdin);
            scanf("%s", &nombre);
            strcpy(vec[indice].nombre, nombre);
            break;

        case 2:
            printf("Ingrese nuevo apellido: ");
            fflush(stdin);
            scanf("%s", &apellido);
            strcpy(vec[indice].apellido, apellido);
            break;

        case 3:
            printf("ingrese nuevo telefono: ");
            scanf("%d", &vec[indice].telefono);

            break;
        case 4:
            printf("Se ha cancelado la mofdificacion ");
            break;
        }
    }
    return todoOk;
}

void ordenarCLientes(eCliente vec[], int tam)
{
    eCliente auxCliente;

    for(int i= 0; i < tam-1 ; i++)
    {
        for(int j= i+1; j <tam; j++)
        {
            if( strcmp(vec[i].nombre, vec[j].nombre) > 0)
            {
                auxCliente = vec[i];
                vec[i] = vec[j];
                vec[j] = auxCliente;
            }
        }
    }
}
