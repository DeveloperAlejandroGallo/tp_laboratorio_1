#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <conio.h>
#include <ctype.h>
#include "movies.h"
#include "datos.h"



/*******************************************************************************************
Constructor
*******************************************************************************************/


void pedirDatosPelicula(eMovie* unaPeli, char titulo[50])
{
    char
    auxGenero[20],
    auxDescripcion[500],
    auxLinkImg[200];
    int auxDuracion, auxPuntaje;

    strcpy(unaPeli->titulo,titulo);
    pedirNDato("Genero: ", unaPeli->genero,20);
    unaPeli->duracion = pedirDatoNumericoValidado("Duracion: ");
    pedirNDato("Descripcion: ", unaPeli->descripcion,500);
    unaPeli->puntaje = pedirDatoNumericoValidado("Puntaje: ");
    pedirNDato("Link Imagen: ", unaPeli->linkImagen,200);
    unaPeli->activo=1;


}


eMovie* caragarArchivoEnVector(eMovie* vectorPelis, int* contador, int* listSize)
{
    /*Carga del archivo*/
    FILE* archPeliculas;
    eMovie* vectorPelisAux;
    int contAux = (*contador);
    int listSizeAux = (*listSize);

    vectorPelis = (eMovie*)malloc(sizeof(eMovie)*listSizeAux);

    archPeliculas = fopen("Peliculas.dat", "rb");

    if(archPeliculas != NULL)
    {
        while(fread((void*)(vectorPelis + contAux),sizeof(eMovie),1,archPeliculas)==1)
        {
            contAux++;
            listSizeAux++;
            vectorPelisAux = (eMovie*)realloc(vectorPelis,sizeof(eMovie)* listSizeAux);
            if(vectorPelisAux != NULL)
                vectorPelis = vectorPelisAux;
        }
        fclose(archPeliculas);
    }
    (*contador) = contAux;
    (*listSize) = listSizeAux;

    return vectorPelis;
}



int agregarPelicula(eMovie* vectorPelis,eMovie unaPeli,int *contador,int *listSize)
{
    eMovie* vectorPelisAux;

    vectorPelisAux = (eMovie*)realloc(vectorPelis,sizeof(eMovie)*(*listSize));
    (*listSize)++;
    if(vectorPelisAux == NULL)
    {
        infoMessage("No hay mas lugar para el vector");
        free(vectorPelis);
        free(vectorPelisAux);
        return 1;
    }
    vectorPelis = vectorPelisAux;
    vectorPelis[(*contador)]=unaPeli;
    (*contador)++;

    return 0;
}


int existePelicula(eMovie* vectorPelis,char titulo[50],int contador, int* posicion)
{
    int bEncontrada=0,i;

    (*posicion) = 0;
    for(i=0;i<contador;i++)
    {
        if(strcmp(vectorPelis[i].titulo,titulo)==0)
        {
            bEncontrada=1;
            (*posicion)=i;
            break;
        }
    }
    return bEncontrada;
}


void verTitulosPeliculas(eMovie* vectorPelis,int contador)
{
    int i;
    printf("\nTITULOS:\n");
    for(i=0;i<contador;i++)
    {
        if(vectorPelis[i].activo == 1)
            printf("-> %s\n",vectorPelis[i].titulo);
    }
}



void generarPagina(eMovie vectorPelis[], char* html, int cantidad)
{
    int i;
    FILE* archivoHTML;
    archivoHTML = fopen(html,"w");
    if(archivoHTML!=NULL)
    {
		//cabecera de pagina
		fprintf(archivoHTML,"%s\n","<!DOCTYPE html>");
		fprintf(archivoHTML,"%s\n","<html lang='en'>");
		fprintf(archivoHTML,"%s\n","<head>");
		fprintf(archivoHTML,"%s\n","    <meta charset='utf-8'>");
		fprintf(archivoHTML,"%s\n","    <meta http-equiv='X-UA-Compatible' content='IE=edge'>");
		fprintf(archivoHTML,"%s\n","    <meta name='viewport' content='width=device-width, initial-scale=1'>");
		fprintf(archivoHTML,"%s\n","    <title>Lista peliculas</title>");
		fprintf(archivoHTML,"%s\n","    <link href='css/bootstrap.min.css' rel='stylesheet'>");
		fprintf(archivoHTML,"%s\n","    <link href='css/custom.css' rel='stylesheet'>");
		fprintf(archivoHTML,"%s\n","</head>");
		fprintf(archivoHTML,"%s\n","<body>");
		fprintf(archivoHTML,"%s\n","    <div class='container'>");
		//Inicio de repetitivo
		for(i=0;i<cantidad;i++)
        {
            if(vectorPelis[i].activo==1)
            {
				fprintf(archivoHTML,"%s\n","<div class='row'>");
				fprintf(archivoHTML,"%s\n","<article class='col-md-4 article-intro'>");
				fprintf(archivoHTML,"%s\n","<a href='#'>");
				fprintf(archivoHTML,"%s","<img class='img-responsive img-rounded'  src='");

				fprintf(archivoHTML,"%s",vectorPelis[i].linkImagen);


				fprintf(archivoHTML,"%s\n","' alt='Falta img ");
				fprintf(archivoHTML,"%s'>",vectorPelis[i].titulo);
				fprintf(archivoHTML,"%s\n","</a>");
				fprintf(archivoHTML,"%s\n","<h3>");
				fprintf(archivoHTML,"%s","<a href='#'>");

				fprintf(archivoHTML,"%s",vectorPelis[i].titulo);

				fprintf(archivoHTML,"%s","</a>");
				fprintf(archivoHTML,"%s\n","</h3>");
				fprintf(archivoHTML,"%s\n","<ul>");
				fprintf(archivoHTML,"%s","<li>Género:");
				fprintf(archivoHTML,"%s",vectorPelis[i].genero);
				fprintf(archivoHTML,"%s\n","</li>");
				fprintf(archivoHTML,"%s","<li>Puntaje:");
				fprintf(archivoHTML,"%d",vectorPelis[i].puntaje);
				fprintf(archivoHTML,"%s\n","</li>");
				fprintf(archivoHTML,"%s","<li>Duración:");
				fprintf(archivoHTML,"%d",vectorPelis[i].duracion);
				fprintf(archivoHTML,"%s\n","</li>");
				fprintf(archivoHTML,"%s\n","</ul>");
				fprintf(archivoHTML,"%s","<p>");

				fprintf(archivoHTML,"%s",vectorPelis[i].descripcion);

				fprintf(archivoHTML,"%s\n","</p>");
				fprintf(archivoHTML,"%s\n","</article>");
				fprintf(archivoHTML,"%s\n","</div>");
            }
        }
		//Pie de pagina
		fprintf(archivoHTML,"%s\n","    </div>");
		fprintf(archivoHTML,"%s\n","    <script src='js/jquery-1.11.3.min.js'></script>");
		fprintf(archivoHTML,"%s\n","    <script src='js/bootstrap.min.js'></script>");
		fprintf(archivoHTML,"%s\n","	<script src='js/ie10-viewport-bug-workaround.js'></script>");
		fprintf(archivoHTML,"%s\n","	<script src='js/holder.min.js'></script>");
		fprintf(archivoHTML,"%s\n","</body>");
		fprintf(archivoHTML,"%s\n","</html>");

        fclose(archivoHTML);

    }
    else
        infoMessage("El Archivo no pudo ser creado;");
}



void crearArchivoBinario(eMovie* vectorPelis, int contador)
{
    int i;
    FILE* archivoPeliculas;

    archivoPeliculas = fopen("Peliculas.dat","wb");
    if(archivoPeliculas == NULL)
    {
        infoMessage("El archivo no pude ser creado");
        exit(1);
    }

    for(i=0;i<contador;i++)
    {
        if((vectorPelis + i)->activo==1)
        {//verificar la cantidad de escritos
            fwrite((vectorPelis + i),sizeof(eMovie),1,archivoPeliculas);

        }

    }
    fclose(archivoPeliculas);
}




/*******************************************************************************************
FUNCIONES DE VISUALIZACION
*******************************************************************************************/

void imprimoMenu()
{
        imprimirTitulo("MENU");
        printf("1- Agregar pelicula\n");
        printf("2- Borrar pelicula\n");
        printf("3- Modificar pelicula\n");
        printf("4- Generar pagina web\n");
        printf("5- Listar Titulos\n");
        printf("6- Salir\n\n");
        printf("ELECCION: ");

}


void infoMessage(char message[])
{
    printf("\nInfo ===> %s\n", message);
}



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
