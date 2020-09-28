#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array_de_Employee.h"
#include "Otras_Funciones.h"
#define LEN 3
#define TRUE 1
#define FALSE 0


int newId(Employee* list, int len, int contadorId)
{
    /*
    El Id a asignar es  una posicion vacia en el vector es un numero unico
    */
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
int numberBetweenOneAndFive(int opcion)
{

    while (opcion<1||opcion>5)
    {
        printf("Ingrese una opcion valida entre 1 y 5 \n ");
        scanf("%d",&opcion);
    }


    return opcion;
}


int compareOptionEqualToOne(int opcionMenu)
{
    while (opcionMenu!=1)
    {
        printf("Primero debe cargar al menos un empleado ingrese opcion 1 \n");
        opcionMenu=getIntMenu(" Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR\n 3-BAJAS\n 4-INFORMAR:\n 5-SALIR \n");
    }
    return opcionMenu;
}
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
int onlyLetters(char nameLastName[])
{
    int i;

    int isChar=-1;
    int lenToLower=0;

    lenToLower=strlen(nameLastName);

    for(i=0; i<lenToLower; i++)
    {
        if((nameLastName[i] < 'a' ||  nameLastName[i] > 'z' ) &&(nameLastName[i] < 'A' || nameLastName[i] > 'Z'))
        {

            isChar=0;
        }
        else
        {
            if(lenToLower==1)
            {
                isChar=0;
            }

        }

    }
    return  isChar;
}

void totalYPromedio (Employee* list, int len)
{
    int i;
    float acumuladorTotal;


    for(i=0; i<len; i++)
    {

    }
}

