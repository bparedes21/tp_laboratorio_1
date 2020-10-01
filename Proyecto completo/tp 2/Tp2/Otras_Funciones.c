#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array_de_Employee.h"
#include "Otras_Funciones.h"
#include <ctype.h>
#define LEN 3
#define TRUE 1
#define FALSE 0

/** \brief Comprueba que haya una posicion libre en  el array isEmpty
 *
 * \param estructura list
 * \param tamaño de la estructura
  * \param recibe como parametro el id generado en el main
 * \return Devuelve el Id si hay una posicion  libre en  el array isEmpty
 *
 */

int newId(Employee* list, int len, int contadorId)
{

    int i;
    int Id=-1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==TRUE)
        {
            Id=contadorId;

            break;
        }
    }

    return Id;
}
/** \brief Pide un numero como cadena de caracteres lo valida y luego lo convierte en entero
 *
 * \param imprime un mensaje
 * \return retorna el numero validado ingresado por el usuario
 *
 */

int getIntMenu(char mensaje[])
{
    char auxiliar [40];
    int esCeroOUno;
    int isNumericI;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",auxiliar);

    esCeroOUno=isNumeric(auxiliar);
    while(esCeroOUno==-1)
    {
        printf("ERROR!! \n");
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",auxiliar);
        esCeroOUno=isNumeric(auxiliar);
    }
    isNumericI=atoi(auxiliar);
    return isNumericI;

}
/** \brief comprueba que el numero ingresado por el usuario sea un numero entre 1 y 5
 *
 * \param recibe el numero que se almaceno en una variable y es el retorno de a funcion getIntMenu
 * \return retorna el numero validado
 *
 */

int numberBetweenOneAndFive(int opcion)
{

    while (opcion<1||opcion>5)
    {
        printf("Ingrese una opcion valida entre 1 y 5 \n ");
        scanf("%d",&opcion);
    }


    return opcion;
}

/** \brief Mientras la opcion sea diferente a 1 va a pedir que se ingrese la opcion 1
 *
 * \param recibe la opcion ingresada por el usuario anteriormente validada por la funcion numberBetweenOneAndFive
 * \return retorna la opcion ingresada por el usuario solo devuelve 1
 *
 */

int compareOptionEqualToOne(int opcionMenu)
{
    while (opcionMenu!=1)
    {
        printf("Primero debe cargar al menos un empleado ingrese opcion 1 \n");
        opcionMenu=getIntMenu(" Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR\n 3-BAJAS\n 4-INFORMAR:\n 5-SALIR \n");
    }
    return opcionMenu;
}
/** \brief Comprueba que es un numero lo que el usuario ingresa
 *
 * \param Recibe una cadena de caracteres previamente ingresada por el usuario con la funciones  getIntSector y  getFloatSalary
 * \return si la cadena de caracteres tiene solo  numeros retorna 0 sino retorna -1
 *
 */

int isNumeric(char numero[])
{
    int i=0;
    while(numero[i] != '\0')
    {
        if( (numero[i] < '0' || numero[i] > '9'))
        {
            return -1;
        }
        i++;
    }
    return 1;
}
/** \brief Pide al usuario que ingrese el salario lo almacena como cadena de caracteres si no es un numero se pide nuevamente
 *validandola. Posteriormente convirtiendola en flotante
 * \param imprime un mensaje
 * \return  retorna el salario
 *
 */

float getFloatSalary(char mensaje[])
{

    char auxiliar[20];
    int esCeroOUno;
    float isNumericF;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",auxiliar);
    esCeroOUno=isNumeric(auxiliar);
    while(esCeroOUno==-1)
    {
        printf("ERROR!! \n");
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",auxiliar);
        esCeroOUno=isNumeric(auxiliar);
    }
    isNumericF=atof(auxiliar);

    return isNumericF;
}
/** \brief Pide al usuario que ingrese el salario lo almacena como cadena de caracteres si no es un numero se pide nuevamente
* \param imprime un mensaje
 *validandola. Posteriormente convirtiendola en entero
 * \return  retorna el sector
 *
 */
int getIntSector(char mensaje[])
{

    char auxiliar[20];
    int esCeroOUno;
    int isNumericI;
    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",auxiliar);
    esCeroOUno=isNumeric(auxiliar);
    while(esCeroOUno==-1)
    {
        printf("ERROR!! \n");
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",auxiliar);
        esCeroOUno=isNumeric(auxiliar);
    }
    isNumericI=atoi(auxiliar);

    return isNumericI;
}

/** \brief comprueba que el numero ingresado por el usuario sea un numero entre 1 y 2
 *
 * \param imprime un mensaje
 * \return retorna el numero validado
 *
 */
int getIntOpcion(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    while(auxiliar<1||auxiliar>2)
    {
        printf("%s \n",mensaje);
        scanf("%d",&auxiliar);
    }

    return auxiliar;
}
/** \brief comprueba que el numero ingresado por el usuario sea un numero
 *
 * \param imprime un mensaje
 * \param recibe el array de estructura list
 * \param y su tamaño como array
 * \return retorna el numero de id que le corresponde a el empleado segun el numero de empleado elegido
 *
 */
int getIntNumId(char mensaje[],Employee* list,int len)
{
    char auxiliar[20];

    int esCeroOUno;
    int isNumericI;
    int retunError;

    printf("%s",mensaje);
    fflush(stdin);
    scanf("%s",auxiliar);
    //comprueba que sea un numero
    esCeroOUno=isNumeric(auxiliar);
    //mientras no sea un numero lo vuelve a pedir
    while(esCeroOUno==-1)
    {
        printf("ERROR!! \n");
        printf("%s",mensaje);
        fflush(stdin);
        scanf("%s",auxiliar);
        esCeroOUno=isNumeric(auxiliar);
    }
    //convierte la cadena de caracteres a entero
    isNumericI=atoi(auxiliar);

    //busca el id si para saber si coincide

    retunError=comprobarId( list,len, isNumericI);
    while(retunError==-1)
    {
        printf("ERROR!! \n");
        retunError=getIntNumId("Ingresar numero de empleado \n", list,len);
    }

    return retunError;
}
/** \brief Verifica si el numero recibido coincide con una posicion en el array estructura list Ocupado =FALSE= 0
 *
 * \param recibe el array de estructura list
 * \param y su tamaño como array
 * \param recibe como parametro el numero ingresado en la funcion getIntNumId
 * \return retorna -1 si no hay una posicion ocupada que coincida con el numero de empleado ingresada por el usuario
 *
 */

int comprobarId(Employee* list, int len,int idIngresado)
{

    int retunError=-1;
    int i;
    int contadorEmpleados;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            if(contadorEmpleados==idIngresado)
            {
                retunError=list[i].id;

            }

            contadorEmpleados++;
        }
    }


    return retunError;

}

/** \brief modifica el nombre almacenando el cambio en la estructura array list
 *
 * \param recibe el array de estructura list
 * \param y su tamaño como array
 * \param recibe como parametro el id previamente verificado en la funcion getIntNumId
 * \param recibe como parametro la cadena de caracteres ingresada en el main
 * \return devuelve
 *
 */

void modificarNombre(Employee* list, int len, int IdOpcion,char name[])
{
    int i;

    for(i=0; i<len; i++)
    {
        if(list[i].id==IdOpcion)
        {
            strcpy(list[i].name,name);
            printf("El empleado que desea MODIFICAR es: \n Id: %d, *Nombre: %s, *Apellido: %s, *Sector: %d \n",list[i].id, list[i].name, list[i].lastName,list[i].sector);
            break;
        }
    }
}
/** \brief modifica el nombre almacenando el cambio en la estructura array list
 *
 * \param recibe el array de estructura list
 * \param y su tamaño como array
 * \param recibe como parametro el id previamente verificado en la funcion getIntNumId
 * \param recibe como parametro la cadena de caracteres ingresada en el main
 * \return devuelve
 *
 */

void modificarApellido(Employee* list, int len, int IdOpcion,char lastName[])
{
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].id==IdOpcion)
        {
            strcpy(list[i].lastName,lastName);
            printf("El empleado que desea MODIFICAR es: \n Id: %d, *Nombre: %s, *Apellido: %s, *Sector: %d \n",list[i].id, list[i].name, list[i].lastName,list[i].sector);
            break;
        }
    }
}
/** \brief comprueba que el texto ingresado por el usuario sean solo letras
 *
 * \param recibe una cadena de caracteres
 * \return retorna el numero validado
 *
 */
int onlyLetters(char nameLastName[])
{
    int i;

    int isChar=0;
    int lenToLower=0;
    lenToLower=strlen(nameLastName);

    if(lenToLower==1)
    {
        isChar=-1;
    }
    for(i=0; i<lenToLower; i++)
    {

        if((nameLastName[i] < 'a' ||  nameLastName[i] > 'z' ) &&(nameLastName[i] < 'A' || nameLastName[i] > 'Z'))
        {
            isChar=-1;
            break;
        }


    }
    return  isChar;
}
/** \brief calcula el promedio y el total de los sueldos
 *
 * \param recibe el array de estructura list
 * \param y su tamaño como array
 * \param recibe como parametro el id previamente verificado en la funcion getIntNumId
 * \param recibe como parametro la cantidad de empleados
 * \return no retorna nada
 *
 */

void calcularTotalyPromedio (Employee* list, int len,int contadorEmpleados)
{
    int i;
    float acumuladorTotal;
    float promedioDeSueldos;
    int contadorMayorSueldo;

    contadorMayorSueldo=0;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE)
        {
            acumuladorTotal=acumuladorTotal+list[i].salary;
        }

    }
    promedioDeSueldos=acumuladorTotal/contadorEmpleados;
    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==FALSE&&list[i].salary>promedioDeSueldos)
        {
            contadorMayorSueldo++;
        }

    }


    printf("Total: %f \nPromedio de los salarios: %.2f \nEmpleados que superan el salario promedio: %d \n",acumuladorTotal,promedioDeSueldos,contadorMayorSueldo);

}
/** \brief  ingresa datos en el array estructura list
 *
 * \param recibe el array de estructura list
 * \param y su tamaño como array
 * \param recibe como parametro el id previamente verificado en la funcion getIntNumId

 * \return No devuelve nada
 *
 */

void hardCodearPerfil(Employee* listEmploye,int len)
{

    int arrayId[10]= {101,102,103,104,105,106,107,108,109,110};
    char arrayName[10][51]= {"Brian","Oscar","Ale","Oliver Jake","Noah","Liam Mason","Jacob","James","Robert","	Robert"};
    char arrayLastName[10][51]= {"Gonzales","Perez","Maradona","Johnson","Williams","Jones","Brown","Smith","Miller","Anderson"};
    float arraySalary[10]= {11000,12000,13000,14000,15000,16000,17000,18000,19000,20000};
    int arraySector[10]= {10,15,10,15,10,15,10,10,15,10};
    int arrayIsEmpty[10]= {0,0,0,0,0,0,0,0,0,0};


    int i ;
    for(i=0; i<len; i++)
    {
        listEmploye[i].id=arrayId[i];
        strcpy(listEmploye[i].name,arrayName[i]);
        strcpy(listEmploye[i].lastName,arrayLastName[i]);
        listEmploye[i].salary=arraySalary[i];
        listEmploye[i].sector=arraySector[i];
        listEmploye[i].isEmpty=arrayIsEmpty[i];


    }
}
