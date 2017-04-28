#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "datos.h"
#include "personas.h"

#define QTY_PERS 20

int main()
{

    ePersona gente[QTY_PERS] ;
    char seguir='s', respuesta;
    int opcion=0;
    //Auxiliares
    int iBuscado, nro;
    ePersona personaAux;

    cargar10Personas(gente);

    while(seguir=='s')
    {
        imprimoMenu();
        scanf("%d",&opcion);

        switch(opcion)
        {
            case 1:
                iBuscado = obtenerEspacioLibre(gente, QTY_PERS);
                if(iBuscado != -1)
                    {
                        personaAux=obtenerDatoPersona();
                        if(buscarPorDni(gente,personaAux.dni,QTY_PERS) == -1)
                        {
                            altaPersona(gente,personaAux,iBuscado);
                            imprimirTitulo("PERSONA DADA DE ALTA");
                            imprimirCabeceraTabla();
                            mostrarPersona(gente[iBuscado]);
                        }
                        else
                            infoMessage("LA PERSONA YA EXISTE!");

                    }
                else
                    infoMessage("NO QUEDAN LUGARES LIBRES.");
                break;
            case 2:
                imprimirTitulo("BAJA DE PERSONA");
                nro=pedirDatoNumericoValidado("DNI Buscado: ");
                iBuscado =  buscarPorDni(gente,nro,QTY_PERS);
                printf("\n\n");
                if(iBuscado != -1)
                {

                    imprimirCabeceraTabla();
                    mostrarPersona(gente[iBuscado]);

                    respuesta = pedirRespuesta("\nDesea Eliminarlo? (s/n): ");

                    if(respuesta=='s')
                    {
                        bajaPersona(gente,iBuscado);
                    }
                    else
                    {
                        infoMessage("La persona NO se ha dado de Baja.");
                    }

                }
                else
                    infoMessage("LA PERSONA NO EXISTE");
                break;
            case 3:
                ordenarListaXNombre(gente, QTY_PERS);
                imprimirTitulo("LISTA DE PERSONAS");
                imprimirCabeceraTabla();
                imprimirPersonasActivas(gente, QTY_PERS);

                break;
            case 4:
                imprimirTitulo("GRAFICO");
                graficoDeEdades(gente, QTY_PERS);
                break;
            case 5:
                seguir = 'n';
                break;
        }
        printf("\n\n");
        if(opcion!=5)
                system("pause"); //Para q no pida 2 veces la tecla al salir
    }

    return 0;
}
