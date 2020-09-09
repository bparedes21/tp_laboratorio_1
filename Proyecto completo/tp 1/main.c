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
int ElegirOperacion(int seleccionOperador);
int main()
{   setbuf(stdout, NULL);
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
    char ingreseSoN;
    int elegirOpcion;

        ingreseSoN='s';

        while(ingreseSoN=='s')
        {   system("cls");
            //1. Ingresar 1er operando
            printf("Ingresar 1er operando \n");
            A=pedirNumero();

            //2. Ingresar 2do operando
            printf("Ingresar 2do operando \n");
            B= pedirNumero();

            printf("A=%d \n",A);
            printf("B=%d \n",B);

            //3. Calcular todas las operaciones
            printf("Que operacion desea realizar?  \n");
            printf("Ingrese 1 para:  \n");
            printf("Calcular solo una operacion  \n");
            scanf("%d",&elegirOpcion);
             //3. Calcular todas las operaciones
            printf("Calcular todas las operaciones  \n");
            printf("Ingrese 2 para: \n");
            printf("Elegir una operacion  \n");
            scanf("%d",&elegirOpcion);
            while(elegirOpcion!=2||elegirOpcion!=1)
                  {
                        printf("ERROR Que opcion desea realizar?  \n");
                        printf("Ingrese 1 para:  \n");
                        printf("Calcular solo una operacion  \n");
                        scanf("%d",&elegirOpcion);
                        //3. Calcular todas las operaciones
                        printf("Calcular todas las operaciones  \n");
                        printf("Ingrese 2 para: \n");
                        scanf("%d",&elegirOpcion);
                  }
            if(elegirOpcion==2)
                {   printf("Elegir una operacion  \n");
                    printf("Que operacion desea realizar?  \n");
                    printf("Ingrese 1 para SUMA  \n");
                    printf("Ingrese 2 para RESTA \n");
                    printf("Ingrese 3 para MULTIPLICACION \n");
                    printf("Ingrese 4 para DIVICION  \n");
                    printf("Ingrese 5 para FACTORIAL  \n");
                    scanf("%d",&operadorSeleccionado);
                    operadorSeleccionado=validarSeleccion(operadorSeleccionado);
                    ElegirOperacion(operadorSeleccionado);

                }

            }
        printf("Desea realizar otra operacion? ingrese s/n \n");
        fflush(stdin);
        scanf("%c",&ingreseSoN);


    return 0;
}


 ElegirOperacion(int seleccionOperador)

{


    switch(seleccionOperador)
    {
        case 1:
            sumaAyB=sumar(A,B);
            printf("La suma A+B es: \n");
            printf("%d + %d = %d \n",A,B,sumaAyB);
            break;
        case 2:
            restaAyB=restar(A,B);
            printf("La resta A-B es: \n");
            printf("%d - %d = %d \n",A,B,restaAyB);
            break;
        case 3:
            multiplicacionAyB=multiplicar(A,B);
            printf("La multiplicacion A*B es: \n");
            printf("%d * %d = %d \n",A,B,multiplicacionAyB);
            break;
        case 4:
            divisionAyB=dividir(A,B,&resultadoF);
            if(divisionAyB==1)
            {
                printf("La division A/B es:  \n");
                printf("%d / %d = %.2f \n",A,B,resultadoF);
            }
            else
            {
                if(divisionAyB==-1)
                {
                    printf("No se puede dividir \n");
                }
            }
            break;
        case 5:
            factorialA=factorial(A);
            factorialB=factorial(B);
            printf("El factorial de A es: %d y El factorial de B es: %d",factorialA,factorialB);
            break;
}


