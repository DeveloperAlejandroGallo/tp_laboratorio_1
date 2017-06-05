#ifndef MOVIES_H_INCLUDED
#define MOVIES_H_INCLUDED

typedef struct{
    char titulo[50];
    char genero[20];
    int duracion;
    char descripcion[500];
    int puntaje;
    char linkImagen[200];
    int activo;
}eMovie;



/** \brief Pide los datos validados para la pelicula
 *
 * \param unaPeli eMovie* Puntero a pelicula
 * \param titulo[50] char titulo de la pelicula
 * \return void
 *
 */
void pedirDatosPelicula(eMovie* unaPeli, char titulo[50]);



/** \brief Carga todos los datos del archivo a un vector en memoria dinamica
 *
 * \param vectorPelis eMovie* vector a ser llenado
 * \param contador int* contador de peliculas leidas
 * \param listSize int* maximo tamaño del vector
 * \return eMovie* puntero al vector de peliculas.
 *
 */
eMovie* caragarArchivoEnVector(eMovie* vectorPelis, int* contador, int* listSize);

/** \brief Agrega una pelicula nueva al vector de peliculas.
 *
 * \param vectorPelis eMovie* vector de peliculas a agregar
 * \param unaPeli eMovie estructura pelicula a agregar
 * \param contador int* posicion donde ira la pelicula
 * \param listSize int* maximo tamaño del vector de peliculas
 * \return int 0 - Si lo pudo agregar / 1 si no pudo.
 *
 */
int agregarPelicula(eMovie* vectorPelis,eMovie unaPeli,int *contador,int *listSize);


/** \brief Busca una pelicula por titulo
 *
 * \param vectorPelis eMovie* vector en el que se busca la pelicula
 * \param titulo[50] char titulo buscado
 * \param contador int cant de peliculas cargadas
 * \param posicion int* posicion en la que se encontro la pelicul
 * \return int 1 - si la encontro / 0 si no lo hizo
 *
 */
int existePelicula(eMovie* vectorPelis,char titulo[50],int contador, int* posicion);

/** \brief Muestra un listado de las peliculas.
 *
 * \param vectorPelis eMovie* vector a recorrer
 * \param contador int cant maxima de peliculas cargadas
 * \return void
 *
 */
void verTitulosPeliculas(eMovie* vectorPelis,int contador);


/** \brief Genera la pagina html con las peliculas activas
 *
 * \param vectorPelis[] eMovie vector de peliculas activas
 * \param html char* nombre del archivo html a generar
 * \param cantidad int cantidad de peliculas cargadas
 * \return void
 *
 */
void generarPagina(eMovie vectorPelis[], char* html, int cantidad);


/** \brief Crea de cero el archivo binario con las peliculas activas
 *
 * \param vectorPelis eMovie* vector de peliculas cargadas
 * \param contador int cant maxima de paliculas cargadas
 * \return void
 *
 */
void crearArchivoBinario(eMovie* vectorPelis, int contador);






//FUNC DE VISUALIZACION
/** \brief Imprime el menu de opciones
 *
 * \return void
 *
 */
void imprimoMenu();

/** \brief Muestra un mensaje  por pantalla
 *
 * \param message[] char mensaje a mostrar
 * \return void
 *
 */
void infoMessage(char message[]);

/** \brief Imprime el texto recibido como cabecera de la pantalla
 *
 * \param titulo[] char Titulo a mostrar.
 * \return void
 *
 */
void imprimirTitulo(char titulo[]);

#endif // MOVIES_H_INCLUDED
