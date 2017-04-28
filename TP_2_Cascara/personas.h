#ifndef PERSONAS_H_INCLUDED
#define PERSONAS_H_INCLUDED




typedef struct {
    char nombre[50];
    int edad;
    int dni;
    int estado; //1 - Activo / 0 - Baja
}ePersona;


 void cargar10Personas(ePersona gente[]);

void inicializarMatriz(ePersona gente[], int QTY_P);

int obtenerEspacioLibre(ePersona lista[], int cantidad);

int buscarPorDni(ePersona lista[], int dni, int tam);

void altaPersona(ePersona gente[], ePersona persona, int espacioLibre);

void bajaPersona(ePersona gente[], int pos);

void mostrarPersona(ePersona persona);

ePersona obtenerDatoPersona(void);

void ordenarListaXNombre(ePersona gente[],  int tam);

void graficoDeEdades(ePersona gente[], int QTY_PERS);

int buscarMayorDe3(int cantMenor18,int cantEntre18y35,int cantMayor35);

void graficar(int menor18, int entre18y35, int mayor35, int maxCantVistas);

void inicializoGrafico(char grafico[][3],int maximo);

void marcaPosicion(char grafico[][3], int cant, int col);

void imprimeGrafico(char grafico[][3], int filas, int cols);

void imprimirPersonasActivas(ePersona gente[], int  QTY_PERS);

void formatearNombre(char auxString[]);

//FUNC DE VISUALIZACION
void imprimoMenu();

void infoMessage(char message[]);

void imprimirTitulo(char titulo[]);

void imprimirCabeceraTabla();


#endif // PERSONAS_H_INCLUDED
