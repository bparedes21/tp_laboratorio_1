#include <stdio.h>
#include "funciones.h"

//estilo doxygen


int pedirNumero(void)
{    int numeroIngresado;
     int numero;
     numeroIngresado=0;
     scanf("%d",&numero);

     numeroIngresado=numero;
     return numeroIngresado;

}

/*
*\brief la funcion va a sumar dos numeros y guardar el resultado en una variable de tipo entero
*\param   el primer parametro de la funcion es numeros de tipo entero
*\param  el segundo parametro de la funcion es numeros de tipo entero
*\return el valor que retorna es el resultado de la suma
*/
int validarSeleccionMenu(int calcularTodoOUno)
{
    while(calcularTodoOUno!=1 && calcularTodoOUno!=2)
   {
        printf("ERROR para calcular TODAS las operaciones: \n");
        printf("Ingrese 1 \n");
        printf("Para calcular SOLO 1 operacion:  \n");
        printf("Ingrese 2 \n");
        scanf("%d",&calcularTodoOUno);
   }
   return calcularTodoOUno;
}


/*
*\brief la funcion va a sumar dos numeros y guardar el resultado en una variable de tipo entero
*\param   el primer parametro de la funcion es numeros de tipo entero
*\param  el segundo parametro de la funcion es numeros de tipo entero
*\return el valor que retorna es el resultado de la suma
*/
int validarSeleccion(int seleccion)
{
    while(seleccion<1 || seleccion>5)
   {
        printf("ERROR! Que operacion desea realizar?  \n");
        printf("Ingrese 1 para SUMA  \n");
        printf("Ingrese 2 para RESTA \n");
        printf("Ingrese 3 para MULTIPLICACION \n");
        printf("Ingrese 4 para DIVICION  \n");
        printf("Ingrese 5 para FACTORIAL  \n");
        scanf("%d",&seleccion);
   }
   return seleccion;
}


int sumar(int x, int y)
{
    int resultado;
    resultado=x+y;
    return resultado;
}
/*
*\brief la funcion va a resta dos numeros y guardar el resultado en una variable de tipo entero
*\param   el primer parametro de la funcion es numeros de tipo entero
*\param  el segundo parametro de la funcion es numeros de tipo entero
*\return el valor que retorna es el resultado de la resta
*/
int restar(int x, int y)
{
    int resultado;
    resultado=x-y;
    return resultado;
}
/*
*\brief la funcion va a multiplicar dos numeros y guarda el resultado en una variable de tipo entero
*\param   el primer parametro de la funcion es numeros de tipo entero
*\param  el segundo parametro de la funcion es numeros de tipo entero
*\return el valor que retorna es el resultado de la multiplicacion
*/
int multiplicar(int x, int y)
{
    int resultado;
    resultado=x*y;
    return resultado;
}
/*
*\brief la funcion va a dividir dos numeros y guarda el resultado en una variable de tipo flotante. Luego se le indica un espacio de memoria con una direccion de memoria en donde se va a almacenar el resultado.
*\param   el primer parametro de la funcion es numeros de tipo entero
*\param  el segundo parametro de la funcion es numeros de tipo entero
*\param  el segundo parametro de la funcion es numeros de tipo flotante  aca la funcion recibe como parametro la direccion la variable declarada en el main. Y luego utilizando la direccion se escribe el resultado en esa posicion de memoria
*\return el valor que retorna es -1 en el caso de que la division sea por 0 cero o 1 si se divide por un numero diferente a 0 cero
*/
float dividir(int x,int y,float* resultadoFloat)
{
    float resultado;
    float noSeDivide;
    noSeDivide=1;
    resultado=(float)x/y;
    (*resultadoFloat)=resultado;
    if (y==0)
    {
     noSeDivide=-1;
    }

    return noSeDivide;
}
/*
*\brief la funcion va a calcular el factorial de un numero
*\param  el parametro de la funcion es numeros de tipo entero
*\return el valor que retorna es el resultado de la multiplicacion consecutiva desde  1 hasta el numero ingresado
*/
factorial(int xoy)
 {
    int resultado;
    int i;
    int multiplicacionFactorial;
    multiplicacionFactorial=1;

    for(i=1;i<=xoy;i++)
    {
        multiplicacionFactorial=multiplicacionFactorial*i;
    }
    resultado=multiplicacionFactorial;
    return resultado;
 }
/*
*\brief permite que se ingrese un numero y lo valida entre 1 y 5
*\param  no recibe paramentros
*\return el valor que retorna el numero ingresado con scanf
*/

 int ingresarOpcionMenu(void)
{
    int numeroIngresado;
    scanf("%d",&numeroIngresado);

    while(numeroIngresado<1 || numeroIngresado>5)
    {   printf("ERROR de opciones: \n");
        printf("Menu de opciones: \n");
        printf("1. Ingresar 1er operando (A=x) \n");
        printf("2. Ingresar 2do operando (B=y) \n");
        printf("3. Calcular todas las operaciones \n");
        printf(" a) Calcular la suma (A+B) \n");
        printf(" b) Calcular la resta (A-B) \n");
        printf(" c) Calcular la division (A/B) \n");
        printf(" d) Calcular la multiplicacion (A*B) \n");
        printf(" e) Calcular el factorial (A!) \n");
        printf("4. Informar resultados \n");
        printf("5. Salir \n" );
        scanf("%d",&numeroIngresado);
    }


    return numeroIngresado;

}
