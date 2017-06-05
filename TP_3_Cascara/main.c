#include <stdio.h>
#include <stdlib.h>
#include "movies.h"
#include "datos.h"


int main()
{
    char seguir='s', titulo[50];
    int opcion=0,
        contador=0,
        listSize=1,
        posicion;

    eMovie unaPeli; //estructura estatica para cargar las peliculas
    eMovie* vectorPelis ;

    vectorPelis = caragarArchivoEnVector(vectorPelis, &contador, &listSize);

    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1://Alta de pelicula
                imprimirTitulo("Alta de Pelicula");
                pedirNDato("Titulo: ",titulo,50);

                if(existePelicula(vectorPelis, titulo, contador, &posicion)==0)
                {
                    pedirDatosPelicula(&unaPeli, titulo);
                    if(agregarPelicula(vectorPelis, unaPeli, &contador, &listSize)==0)
                        infoMessage("Pelicula dada de alta");
                    else
                        infoMessage("Pelicula NO dada de alta");
                }
                else
                    infoMessage("LA PELICULA YA EXISTE.");

                break;
            case 2://Borrar pelicula
                imprimirTitulo("Baja de Pelicula");
                verTitulosPeliculas(vectorPelis, contador);
                pedirNDato("\nQue pelicula desea eliminar?: ",titulo,50 );

                if(existePelicula(vectorPelis, titulo, contador, &posicion)== 1)
                {
                    vectorPelis[posicion].activo=0;
                    printf("\nPelicula %s dada de baja", vectorPelis[posicion].titulo);
                }
                else
                    infoMessage("No existe la pelicula");
                break;
            case 3://Modificar Pelicula
                imprimirTitulo("Modificar Pelicula");
                verTitulosPeliculas(vectorPelis, contador);

                printf("\nQue pelicula desea modificar?:\n\n");
                pedirNDato("Titulo: ",titulo,50);
                if(existePelicula(vectorPelis, titulo, contador, &posicion)==1)
                {
                    pedirDatosPelicula(&unaPeli, titulo);
                    vectorPelis[posicion]=unaPeli;
                    infoMessage("Pelicula modificada");
                }
                else
                    infoMessage("No existe la pelicula");

               break;
            case 4: //Generar pag web
                generarPagina(vectorPelis, "template/index.html", contador);
                infoMessage("Pagina Web generada: Template/index.html");
                break;
            case 5://Listar
                imprimirTitulo("Listar Titulos");
                verTitulosPeliculas(vectorPelis,contador);
                break;
            case 6://EXIT
                crearArchivoBinario(vectorPelis, contador);
                free(vectorPelis);
                seguir = 'n';
                break;
        }
        printf("\n\n");
        if(opcion!=6)
            system("pause"); //Para q no pida 2 veces la tecla al salir
    }
    //exit(0);
    return 0;
}
