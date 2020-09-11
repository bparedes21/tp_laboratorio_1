/*
Apellido:Paredes
Nombre:Brian
1 Enunciado
Hacer una calculadora. Para ello el programa iniciará y contará con un menú de opciones:
1. Ingresar 1er operando (A=x)
2. Ingresar 2do operando (B=y)
3. Calcular todas las operaciones
a) Calcular la suma (A+B)
b) Calcular la resta (A-B)
c) Calcular la division (A/B)
d) Calcular la multiplicacion (A*B)
e) Calcular el factorial (A!)
4. Informar resultados
a) “El resultado de A+B es: r”
b) “El resultado de A-B es: r”
c) “El resultado de A/B es: r” o “No es posible dividir por cero”
d) “El resultado de A*B es: r”
e) “El factorial de A es: r1 y El factorial de B es: r2”
5. Salir
• Todas las funciones matemáticas del menú se deberán realizar en una biblioteca aparte,
que contenga las funciones para realizar las cinco operaciones.
• En el menú deberán aparecer los valores actuales cargados en los operandos A y B
(donde dice “x” e “y” en el ejemplo, se debe mostrar el número cargado)
• Deberán contemplarse los casos de error (división por cero, etc)
• Documentar todas las funciones
2 Cómo realizar y entregar el trabajo práctico
El trabajo práctico deberá ser entregado en el repositorio de GIT correspondiente al TP1 de la
materia.
El mismo consistirá en el proyecto de CodeBlocks con el programa funcionando y comentado,
respetando las reglas de estilo de la cátedra. La compilación no deberá arrojar mensajes de
error ni de warnings.
El proyecto deberá contar con la biblioteca descripta en la sección número dos, y se deberá
hacer uso de dichas funciones para resolver la lógica del programa.


*/

#include <stdio.h>
#include <stdlib.h>
#include "funciones.h"

int main()
{   setbuf(stdout, NULL);
    int ingresarOpcion;
    int valorNumeroIngresado;
    float resultadoF;
    int A;
    int B;
    int sumaAyB;
    int restaAyB;
    int multiplicacionAyB;
    float divisionAyB;
    int factorialA;
    int factorialB;
    int operadorSeleccionado;
    int seleccionOperacion;


        printf("Menu de opciones: \n");
        printf("1. Ingresar 1er operando (A=x) \n");
        printf("2. Ingresar 2do operando (B=y) \n");
        printf("3. Calcular todas las operaciones \n");
        printf(" a) Calcular la suma (A+B) \n");
        printf(" b) Calcular la resta (A-B) \n");
        printf(" c) Calcular la division (A/B) \n");
        printf(" d) Calcular la multiplicacion (A*B) \n");
        printf(" e) Calcular el factorial (A!) \n");
        printf("4. Informar resultados \n" );
        printf("5. Salir \n" );

        ingresarOpcion=ingresarOpcionMenu();
        while(ingresarOpcion!=5)
        {


            switch(ingresarOpcion)
            {
                case 1:
                    //1. Ingresar 1er operando
                    printf("Ingresar 1er operando \n");
                    A=pedirNumero();
                    break;
                case 2:
                    //2. Ingresar 2do operando
                    printf("Ingresar 2do operando \n");
                    B= pedirNumero();
                    break;
                case 3:
                    sumaAyB=sumar(A,B);
                    restaAyB=restar(A,B);
                    multiplicacionAyB=multiplicar(A,B);
                    divisionAyB=dividir(A,B,&resultadoF);
                    factorialA=factorial(A);
                    factorialB=factorial(B);
                    break;
                case 5:
                    system("cls");
                    ingresarOpcion==5;
                break;
            }
                if(ingresarOpcion==1)
                {   printf("1er operando INGRESADO \n",A);
                    printf("A=%d \n",A);
                    printf("Menu de opciones: \n");
                    printf("2. Ingresar 2do operando (B=%d)\n",B );
                }
                else
                {
                    if(ingresarOpcion==2)
                    {   printf("2do operando INGRESADO \n",A);
                        printf("B=%d \n",B);
                    }
                    else
                    {
                        if(ingresarOpcion==3)
                        {
                            printf("Menu de opciones: \n");
                            printf("Calcular la suma %d+%d  \n",A,B);
                            printf("Calcular la resta %d-%d  \n",A,B);
                            printf("Calcular la multiplicacion %d*%d  \n",A,B);
                            printf("Calcular la division %d/%d =\n",A,B);
                            printf("Calcular el factorial de A es: %d y El factorial de B es: %d \n",A,B);
                            printf("4. Informar resultados \n" );
                            printf("5. Salir \n" );
                        }
                        else
                        {
                            if(ingresarOpcion==4)
                            {
                                printf("El resultado de %d + %d = %d \n",A,B,sumaAyB);
                                printf("El resultado de %d - %d = %d \n",A,B,restaAyB);
                                printf("El resultado de %d * %d = %d \n",A,B,multiplicacionAyB);
                                printf("El resultado de %d / %d = %d \n",A,B,divisionAyB);
                                printf("El resultado de factorial de A es: %d \n", factorialA);
                                printf("El resultado de factorial de B es: %d \n", factorialB);
                            }
                        }
                    }
                }

            if(ingresarOpcion!=3&&ingresarOpcion!=4)
            {
                printf("3. Calcular todas las operaciones \n");
                printf(" a) Calcular la suma (%d+%d) \n",A,B);
                printf(" b) Calcular la resta (%d-%d) \n",A,B);
                printf(" c) Calcular la division (%d/%d) \n",A,B);
                printf(" d) Calcular la multiplicacion (%d*%d) \n",A,B);
                printf(" e) Calcular el factorial (%d!) \n",A);
                printf(" e) Calcular el factorial (%d!) \n",B);
                printf("4. Informar resultados \n" );
                printf("5. Salir \n" );
            }
        ingresarOpcion=ingresarOpcionMenu();
        }

    return 0;
}






