#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include "Array_de_Employee.h"
#include "Otras_Funciones.h"
#define LEN 3
#define TRUE 1
#define FALSE 0


//2.1 Función initEmployees
/** \brief To indicate that all position in the array are empty,
* this function put the flag (isEmpty) in TRUE in all
* position of the array
* \param list Employee* Pointer to array of employees
* \param len int Array length
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/
int initEmployees(Employee* list, int len)
{
    /* Para indicar que todas las posiciones del array están vacías, esta función pone la bandera
    (isEmpty) en TRUE en todas las posiciones del array.*/
    int i;
    int Error=-1;
    if(list!=NULL&&len>=0)
    {
        Error=0;
        for(i=0; i<len; i++)
        {
            list[i].isEmpty =TRUE;

        }
    }

    return Error;
}

//2.2 Función addEmployees
/** \brief add in a existing list of employees the values received as parameters
* in the first empty position
* \param list employee*
* \param len int
* \param id int
* \param name[] char
* \param lastName[] char
* \param salary float
* \param sector int
* \return int Return (-1) if Error [Invalid length or NULL pointer or without
free space] - (0) if Ok
**/


int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector)
{
    int i;
    int error;
    error=-1;

    for(i=0; i<len; i++)
    {
        if(list[i].isEmpty==TRUE)
        {

            list[i].id=id;
            strcpy(list[i].name,name);
            strcpy(list[i].lastName,lastName);
            list[i].salary=salary;
            list[i].sector=sector;
            list[i].isEmpty=FALSE;

            error=0;
            break;
        }
    }
    return error;
}


//2.3 Función findEmployeeById

/** \brief find an Employee by Id en returns the index position in array.
*
* \param list Employee*
* \param len int
* \param id int
* \return Return employee index position or (-1) if [Invalid length or NULL
pointer received or employee not found]
*
*/

int findEmployeeById(Employee* list, int len,int id)
{

//Busca un empleado recibiendo como parámetro de búsqueda su Id.

    int i;
    for(i=0; i<len; i++)
    {

        if(list[i].id==id)
        {
            printf("El empleado que desea eliminar es: \n *Nombre: %s, *Apellido: %s, *Sector: %d \n", list[i].name, list[i].lastName,list[i].sector);
            break;
        }
    }

    return 0;
}

//2.4 Función removeEmployee
/** \brief Remove a Employee by Id (put isEmpty Flag in 1)
*
* \param list Employee*
* \param len int
* \param id int
* \return int Return (-1) if Error [Invalid length or NULL pointer or if can't
find a employee] - (0) if Ok
*
*/

int removeEmployee(Employee* list, int len, int id)
{

//Elimina de manera lógica (isEmpty Flag en 1) un empleado recibiendo como parámetro su Id.
    int i;
    for(i=0; i<len; i++)
    {
        if(list[i].id==id)
        {
            list[i].isEmpty=TRUE;

            break;
        }
    }

    return -1;
}

//2.5 Función sortEmployeeByName
/** \brief Sort the elements in the array of employees, the argument order
indicate UP or DOWN order
*
* \param list Employee*
* \param len int
* \param order int [1] indicate UP - [0] indicate DOWN
* \return int Return (-1) if Error [Invalid length or NULL pointer] - (0) if Ok
*
*/


int sortEmployees(Employee* list, int len, int order)
{

    int j;
    char auxiliarChar[51];
    int auxiliarInt;
    int flagNoEstaOrdenado = 1;
    j=0;

    //Ordena el array de empleados por apellido y sector de manera ascendente o descendente./
    if(order==1)
    {
        while (flagNoEstaOrdenado==1)
        {
            flagNoEstaOrdenado = 0;
            for (j = 1; j < len; j++)
            {
                if(list[j-1].isEmpty==0)
                {
                    if (strcmp(list[j].lastName,list[j-1].lastName)<0)
                    {
                        auxiliarInt=list[j].id;
                        list[j].id=list[j-1].id;
                        list[j-1].id=auxiliarInt;

                        strcpy(auxiliarChar,list[j].name);
                        strcpy(list[j].name,list[j-1].name);
                        strcpy(list[j-1].name,auxiliarChar);

                        strcpy(auxiliarChar,list[j].lastName);
                        strcpy(list[j].lastName,list[j-1].lastName);
                        strcpy(list[j-1].lastName,auxiliarChar);

                        auxiliarInt=list[j].salary;
                        list[j].salary=list[j-1].salary;
                        list[j-1].salary=auxiliarInt;

                        auxiliarInt=list[j].sector;
                        list[j].sector=list[j-1].sector;
                        list[j-1].sector=auxiliarInt;
                        flagNoEstaOrdenado = 1;
                    }
                    else
                    {
                        if (strcmp(list[j].lastName,list[j-1].lastName)==0)
                        {
                            if (list[j].sector<list[j-1].sector)
                            {
                                auxiliarInt=list[j].id;
                                list[j].id=list[j-1].id;
                                list[j-1].id=auxiliarInt;

                                strcpy(auxiliarChar,list[j].name);
                                strcpy(list[j].name,list[j-1].name);
                                strcpy(list[j-1].name,auxiliarChar);

                                strcpy(auxiliarChar,list[j].lastName);
                                strcpy(list[j].lastName,list[j-1].lastName);
                                strcpy(list[j-1].lastName,auxiliarChar);

                                auxiliarInt=list[j].salary;
                                list[j].salary=list[j-1].salary;
                                list[j-1].salary=auxiliarInt;

                                auxiliarInt=list[j].sector;
                                list[j].sector=list[j-1].sector;
                                list[j-1].sector=auxiliarInt;
                                flagNoEstaOrdenado = 1;
                            }
                        }
                    }
                }

            }
        }
    }
    if(order==2)
    {
        while (flagNoEstaOrdenado==1)
        {
            flagNoEstaOrdenado = 0;
            for (j = 1; j < len; j++)
            {
                if(list[j-1].isEmpty==0)
                {
                    if (strcmp(list[j].lastName,list[j-1].lastName)>0)
                    {
                        auxiliarInt=list[j].id;
                        list[j].id=list[j-1].id;
                        list[j-1].id=auxiliarInt;

                        strcpy(auxiliarChar,list[j].name);
                        strcpy(list[j].name,list[j-1].name);
                        strcpy(list[j-1].name,auxiliarChar);

                        strcpy(auxiliarChar,list[j].lastName);
                        strcpy(list[j].lastName,list[j-1].lastName);
                        strcpy(list[j-1].lastName,auxiliarChar);

                        auxiliarInt=list[j].salary;
                        list[j].salary=list[j-1].salary;
                        list[j-1].salary=auxiliarInt;

                        auxiliarInt=list[j].sector;
                        list[j].sector=list[j-1].sector;
                        list[j-1].sector=auxiliarInt;
                        flagNoEstaOrdenado = 1;
                    }
                    else
                    {
                        if (strcmp(list[j].lastName,list[j-1].lastName)==0)
                        {
                            if (list[j].sector<list[j-1].sector)
                            {
                                auxiliarInt=list[j].id;
                                list[j].id=list[j-1].id;
                                list[j-1].id=auxiliarInt;

                                strcpy(auxiliarChar,list[j].name);
                                strcpy(list[j].name,list[j-1].name);
                                strcpy(list[j-1].name,auxiliarChar);

                                strcpy(auxiliarChar,list[j].lastName);
                                strcpy(list[j].lastName,list[j-1].lastName);
                                strcpy(list[j-1].lastName,auxiliarChar);

                                auxiliarInt=list[j].salary;
                                list[j].salary=list[j-1].salary;
                                list[j-1].salary=auxiliarInt;

                                auxiliarInt=list[j].sector;
                                list[j].sector=list[j-1].sector;
                                list[j-1].sector=auxiliarInt;
                                flagNoEstaOrdenado = 1;
                            }
                        }
                    }
                }

            }
        }
    }
    return 0;
}


//2.6 Función printEmployees

/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*
*/

int printEmployees(Employee* list, int length, int cantidadEmpleados)
{
//Imprime el array de empleados de forma encolumnada.

    int i;
    int contadorEmpleados;
    int contadorIsEmpty;
    contadorEmpleados=1;
    contadorIsEmpty=0;
    printf("Nro de empleado:  Nombre:    Apellido:   Salary:    Sector: \n");
    for(i=0; i<length; i++)
    {
        if(cantidadEmpleados==contadorIsEmpty)
        {
            break;
        }
        else
        {
            if(list[i].isEmpty==FALSE)
            {
                printf("%6d %15s        %5s        %2.2f     %6d \n",contadorEmpleados, list[i].name, list[i].lastName,list[i].salary,list[i].sector);
                contadorEmpleados++;
                contadorIsEmpty++;
            }

        }





    }

    return 0;
}

