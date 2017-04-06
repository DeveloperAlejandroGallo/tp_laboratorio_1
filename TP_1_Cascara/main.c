#include <stdio.h>
#include <stdlib.h>
#include <conio.h>
#include "GalloAlejandro.h"

int main()
{
    char seguir='s';
    char opcion;
    int bOperando1=0;
    int bOperando2=0;
    int operando1;
    int operando2;


    while(seguir=='s')
    {
        system("cls");
        printf("******************************\n");
        printf("*     CALCULADORA 1RO G      *\n");
        printf("******************************\n\n");
        printf("MENU:\n");
        if(bOperando1 == 0) printf("1- Ingresar 1er operando (A=x)\n");
        else printf("1- Ingresar 1er operando (A=%d)\n",operando1);

        if(bOperando2 == 0) printf("2- Ingresar 2do operando (B=y)\n");
        else printf("2- Ingresar 2do operando (B=%d)\n",operando2);

        printf("3- Calcular la suma (A+B)\n");
        printf("4- Calcular la resta (A-B)\n");
        printf("5- Calcular la division (A/B)\n");
        printf("6- Calcular la multiplicacion (A*B)\n");
        printf("7- Calcular el factorial (A!)\n");
        printf("8- Calcular todas las operacione\n");
        printf("9- Salir\n\n");

        //scanf("%d",&opcion);
        opcion = getch();

        switch(opcion)
        {
            case '1':
                printf("Ingrese el 1er Nro: ");
                operando1 = obtenerNro();
                bOperando1=1;
                break;
            case '2':
                printf("Ingrese el 2do Nro: ");
                operando2 = obtenerNro();
                bOperando2=1;
                break;
            case '3':
				if(bOperando1 == 1 && bOperando2 == 1)
					printf("La suma (A+B): %d \n",sumar(operando1,operando2));
                break;
            case '4':
				if(bOperando1 == 1 && bOperando2 == 1)
					printf("La resta (A-B): %d \n", restar(operando1,operando2));
                break;
            case '5':
				if(bOperando1 == 1 && bOperando2 == 1)
                {
					if(operando2 !=0)
                        printf("La division (A/B): %f \n", dividir(operando1,operando2));
                    else
                        printf("ERROR: Esta intentando dividir por cero.");
                }
                break;
            case '6':
				if(bOperando1 == 1 && bOperando2 == 1)
					printf("La multiplicacion (A*B): %d \n", multiplicar(operando1,operando2));
                break;
            case '7':
                //Se requiere el 1er operando y debe ser mayor a cero.
				if(bOperando1 == 1 )
                    if(operando1 > 0)
                        printf("El factorial (A!): %d \n", factorial(operando1));
                    else
                        printf("No se puede realizar el factorial del nro %d porque es negativo\n", operando1);
                break;
            case '8':
				if(bOperando1 == 1 && bOperando2 == 1)
				{
					printf("\n");
					printf("La suma (A+B): %d \n", sumar(operando1,operando2));
					printf("La resta (A-B): %d \n", restar(operando1,operando2));
					printf("La division (A/B): %f \n", dividir(operando1,operando2));
					printf("La multiplicacion (A*B): %d \n", multiplicar(operando1,operando2));
					printf("El factorial (A!): %d \n", factorial(operando1));
				}
                break;
            case '9':
                seguir = 'n';
				printf("USTED HA SALIDO DEL SISTEMA\n\n");
                break;
        }

        //Ambos operandos deben estar cargados para las opciones que requieren los 2
		if((bOperando1 == 0 || bOperando2 == 0) && opcion != '9' && opcion != '1' && opcion != '2'  && opcion != '7')
		{
			printf("Ambos operandos deben estar cargados!\n\n");
		}
		else if (bOperando1 == 0 && opcion == '7')  //Validacion para el factorial ya que solo requiere el 1er operador
            printf("Debe cargar el 1er operando.\n\n");

        //Pausa para mostrar el resultado
		if(opcion != '1' && opcion != '2')
		system("pause");
    }
    return 0;
}
