#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "personas.h"
#include "datos.h"

#define COLS 3
#define ANCHO_PANTA 68
#define LARGO_NAME 50

/** \brief Inicializa lel vector de personas con 10 personas.
 *
 * \param gente Vector de personas a inicializar
  * \param cant Cantidad de Personas
 * \return void
 *
 */
void cargar10Personas(ePersona gente[])
{
     int cant=10;
    //Se definen con el tamaño total para que los datos queden cereados y asi los tome la matriz
    int DNIs[10] = {29111111,29222222,29333333,29444444,29555555,29666666,29777777,
                    29888888,29999999,29000000};
    char Nombres [10][50]  = {"aPersonaA","PersonaB","PersonaC","PersonaD","PersonaE",
                                                         "PersonaF","PersonaG","PersonaH","PersonaI","PersonaJ"};
    int Edades[10] = {1, 2, 3, 18, 22, 23, 24, 25, 35, 80};
    int i;

    inicializarMatriz(gente, 20);

    for(i=0;i<cant;i++)
    {
        gente[i].dni = DNIs[i];
        gente[i].edad = Edades[i];
        strcpy(gente[i].nombre ,Nombres[i]);
        gente[i].estado = 1;
    }
}


/** \brief Inicializa la matriz de personas
 *
 * \param gente[] ePersona Matriz a Inicializar
 * \param QTY_P int Cantidad de personas
 * \return void
 *
 */
void inicializarMatriz(ePersona gente[], int QTY_P)
{
    int i;
    for(i=0;i<QTY_P;i++)
    {
        gente[i].dni = 0;
        gente[i].edad = 0;
        strcpy(gente[i].nombre ,"");
        gente[i].estado = 0;
    }
}

/**
 * \brief Obtiene el primer indice libre del array.
 *
 * \param ePersona lista[] - Vector a buscar espacio libre.
 * \param int cantidada - Tamanio del vector
 * \return El indice del espacio libre.
 *
 */
int obtenerEspacioLibre(ePersona lista[], int cantidad)
{
    int posicion=-1;
    int i;

    for(i=0;i<cantidad;i++)
    {
        if(lista[i].estado == 0)
        {
            posicion = i;
            i=cantidad;
        }
    }

    return posicion;
}

/**
 * \brief Obtiene el indice que coincide con el dni pasado por parametro.
 * \param ePersona lista[] Array en el cual se buscara
 * \param int dni El DNI a ser buscado en el array.
 * \param int tam Tamanio del array
 * \return posicion El indice en donde se encuentra el elemento que coincide con el parametro dni
 */
int buscarPorDni(ePersona lista[], int dni, int tam)
{
    int posicion=-1, i;

    for(i=0;i<tam;i++)
    {
        if(lista[i].dni==dni && lista[i].estado == 1) //Solo busco en los dados de alta.
        {
            posicion = i;
            i=tam;
        }
    }

    return posicion;
}

/** \brief Guarda una persona en indice indicado
 *
 * \param gente[] ePersona Vector de personas
 * \param persona ePersona Persona a guardar
 * \param espacioLibre int Indice del espacio libre
 * \return void
 *
 */
void altaPersona(ePersona gente[], ePersona persona, int espacioLibre)
{
    gente[espacioLibre] = persona;
}

/** \brief Realiza la baja logica del registro
 *
 * \param gente[] ePersona Vector de personas
 * \param pos int Indice a marcar la baja
 * \return void
 *
 */
void bajaPersona(ePersona gente[], int pos)
{
    gente[pos].estado = 0;
    infoMessage("PERSONA DADA DE BAJA");
}


/** \brief Imprime la cabecera de la tabla de Personas
 *
 * \return void
 *
 */
void imprimirCabeceraTabla()
{
     int i, largo = strlen("NOMBRE Y APELLIDO");
    printf("|%s", "NOMBRE Y APELLIDO");
        for(i=0;i<51-largo;i++) //Imprimo los espacios necesario para alinear la tabla
        printf(" ");

        printf("| %4s |","EDAD");
    printf("%8s\n", "DNI");
}


/** \brief  Imprime los datos de una persona por linea.
 *
 * \param persona ePersona - Estructura tipo persona a leer
 * \return void
 *
 */
void mostrarPersona(ePersona persona)
{
    int i, largo = strlen(persona.nombre);
    formatearNombre(persona.nombre);
    printf("|%s",persona.nombre);

    for(i=0;i<51-largo;i++) //Imprimo los espacios necesario para alinear la tabla
        printf(" ");

    printf("| %4d |",persona.edad);
    printf("%08d\n", persona.dni);

}


/** \brief Pide por pantalla los datos de una persona
 *
 * \param void
 * \return ePersona Persona valida
 *
 */
ePersona obtenerDatoPersona(void)
{
    char auxString[200];
    ePersona persona;

    imprimirTitulo("ALTA DE PERSONA");
    pedirDatoSoloLetrasValido("NOMBRE: ",auxString);
    formatearNombre(auxString);
    strcpy(persona.nombre,auxString);
    persona.edad = pedirDatoNumericoValidado("EDAD: ");
    persona.dni = pedirDatoNumericoValidado("DNI: ");
    persona.estado = 1;
    printf("\n");

    return persona;
}



/** \brief Pone letra capital a cada nombre
 *
 * \param auxString[] char Nombre completo
 * \return void
 *
 */
void formatearNombre(char auxString[])
{
    int i=0;

    while(auxString[i] != '\0')
    {
        if(auxString[i]!=' ')
            auxString[i] = tolower(auxString[i]);
        i++;
    }

     i=0;
    auxString[0] = toupper(auxString[0]);
    while(auxString[i] != '\0')
    {
        if(auxString[i] == ' ')
            auxString[i+1] = toupper(auxString[i+1]);

        i++;
    }
}


/** \brief Ordena la Lista de personas por nombre
 *
 * \param gente[] ePersona Vector de personas
 * \param tam int tamaño del vector
 * \return void
 *
 */
void ordenarListaXNombre(ePersona gente[],  int tam)
{

    int i, j;
    ePersona aux;

    for(i=0;i<tam-1;i++)
    {
        for(j=i+1;j<tam;j++)
        {
            if(strcmp(gente[i].nombre, gente[j].nombre) == 1  )
            {
                aux = gente[i];
                gente[i]=gente[j];
                gente[j]=aux;
            }
        }
    }
}

/** \brief Genera el grafico de edades
 *
 * \param gente[] ePersona Matriz de Personas
 * \param QTY_PERS int Cantidad de personas
 * \return void
 *
 */
void graficoDeEdades(ePersona gente[], int QTY_PERS)
{
    int cantMenor18=0, cantEntre18y35=0, cantMayor35=0,i, edad, max; //El enunciado dice menores a 18 luego entre 19 y 35, de esta manera los iguales a 18 se pierden, los incluyo en la variable entre 18y35
    //Cuento las edaddes
    for(i=0;i<QTY_PERS;i++)
    {
        edad = gente[i].edad;

        if(edad>0 && edad < 18)
            cantMenor18++;
        else
            if (edad >= 18 && edad <= 35)
                    cantEntre18y35 ++;
            else
                if(edad>35)
                    cantMayor35++;
    }

    max = buscarMayorDe3(cantMenor18,cantEntre18y35,cantMayor35);

    graficar(cantMenor18,cantEntre18y35,cantMayor35, max);

}

/** \brief Busca el mayor entre 3 nros
 *
 * \param cantMenor18 Numero 1
 * \param cantEntre18y35 Numero 2
 * \param cantMayor35 Numero 3
 * \return int
 *
 */
int buscarMayorDe3(cantMenor18,cantEntre18y35,cantMayor35)
{
    int max;

        if(cantMenor18 > cantEntre18y35)
        {
            if(cantMenor18 > cantMayor35)
                max = cantMenor18;
            else
                max = cantMayor35;
        }
        else
            if (cantEntre18y35 > cantMayor35)
                max = cantEntre18y35;
            else
                max = cantMayor35;

        return max;

}

/** \brief Grafica el grafico de edades. Lo inicializa. Marca por columna los asteriscos. Imprime
 *
 * \param menor18 int
 * \param entre18y35 int
 * \param mayor35 int
 * \param maxCantVistas int El numero maximo de visitas para tomarlo como el mayor rango a dibujar y de ahi hacia abajo
 * \return void
 *
 */
void graficar(int cantMenor18, int cantEntre18y35, int cantMayor35, int maxCantVistas)
{

    char grafico[maxCantVistas][COLS];
//Inicializo la matriz
    inicializoGrafico(grafico, maxCantVistas);

    marcaPosicion(grafico,cantMenor18,0);
    marcaPosicion(grafico,cantEntre18y35,1);
    marcaPosicion(grafico,cantMayor35,2);

    imprimeGrafico(grafico, maxCantVistas, 3);
}


/** \brief Pone en blanco todo el grafico
 *
 * \param grafico[][COLS] char Grafico pantalla
 * \param maximo int maxima cant de filas
 * \return void
 *
 */
void inicializoGrafico(char grafico[][COLS],int maximo)
{
    int i,j;
    for(i=0;i<maximo;i++)
    {
        for(j=0;j<COLS;j++)
        {
            grafico[i][j]=' ';
        }
    }
}

/** \brief Marca por columna la cant de asteriscos q le correspondan de mayor a menos
 *
 * \param grafico[][COLS] char Grafico
 * \param cant int cantidad maxima a marcar
 * \param col int columna a marcar
 * \return void
 *
 */
void marcaPosicion(char grafico[][COLS], int cant, int col)
{//col tiene la columna a marcar
    int fila;
        for(fila=cant-1;fila>=0;fila--)
            grafico[fila][col] = '*';
}


/** \brief Imprime el grafico por completo. De la maxima cantidad hacia abajo como un eje carteciano
 *
 * \param grafico[][COLS] char Grafico
 * \param filas int maxima cant de filas
 * \param cols int max cant de columnas
 * \return void
 *
 */
void imprimeGrafico(char grafico[][COLS], int filas, int cols)
{
    int i,j;
    printf("\nCantidad\n");
    for(i=filas-1;i>=0;i--)
    {
        printf("%d-\t",i+1); //Muestro las cantidades como en los ejes cartesianos
        for(j=0;j<cols;j++)
        {
            printf("  %c\t",grafico[i][j] );
        }
        printf("\n");
    }
    printf("\t<18\t18-35\t>35  Edades");
    printf("\n\n");
}

/** \brief Solo imprime la liinea de las personas que estan activas
 *
 * \param gente[] ePersona MAtriz de personas
 * \param QTY_PERS int cantidad
 * \return void
 *
 */
void imprimirPersonasActivas(ePersona gente[], int  QTY_PERS)
{
    int i;
    for(i=0;i<QTY_PERS;i++)
        {
            if(gente[i].estado == 1) //Solo imprimo los que poseen edad !=0
                mostrarPersona(gente[i]);

        }

    }
/*******************************************************************************************
FUNCIONES DE VISUALIZACION
*******************************************************************************************/
/** \brief Imprime el menu principal
 *
 * \return void
 *
 */
void imprimoMenu()
{
        imprimirTitulo("MENU");
        printf("1- AGREGAR PERSONA\n");
        printf("2- BORRAR PERSONA\n");
        printf("3- IMPRIMIR LISTA ORDENADA POR NOMBRE\n");
        printf("4- IMPRIMIR GRAFICO DE EDADES\n");
        printf("5- SALIR\n\n");
        printf("ELECCION: ");

}

/** \brief Imprime un mensaje de informacion
 *
 * \param message[] char Mensaje a mostrar
 * \return void
 *
 */
void infoMessage(char message[])
{
    printf("\nInfo ===> %s\n", message);
}


/** \brief Imprime un Titulo con formato
 *
 * \param titulo[] char titulo a mostrar
 * \return void
 *
 */
void imprimirTitulo(char titulo[])
{

        int i, largo, mitadPalabra, mitadPantalla;

        largo = strlen(titulo);
        mitadPalabra = largo / 2 + 1; //Como meto la division en entero me queda solo la parte entera
        mitadPantalla = ANCHO_PANTA / 2;

        system("cls");
        for(i=0;i<ANCHO_PANTA;i++) printf("*");
        printf("\n");
        printf("*");
        for(i=0;i<mitadPantalla-mitadPalabra;i++) printf(" ");
        printf("%s",titulo);
        for(i=0;i<mitadPantalla-mitadPalabra;i++) printf(" ");
        printf("*");
        printf("\n");
        for(i=0;i<ANCHO_PANTA;i++) printf("*");
        printf("\n");


    }


