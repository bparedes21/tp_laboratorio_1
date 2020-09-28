#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
/*
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
    int i;
    int j;
    char auxiliarChar[51];
    int auxiliarInt;
    //Ordena el array de empleados por apellido y sector de manera ascendente o descendente./
    if(order==1)
    {
        for (i=0; i<len-1; i++);
        {   printf("I %d \n",i);
            for (j=i+1; j<len; j++)
            {   printf("J %d \n",j);
                printf("lastanme: %s \n",list[i].name);
                if(list[i].name<list[j].name)
                {
                    printf("copia \n");
                    auxiliarInt=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=auxiliarInt;

                    strcpy(auxiliarChar,list[i].name);
                    strcpy(list[i].name,list[j].name);
                    strcpy(list[j].name,auxiliarChar);

                    strcpy(auxiliarChar,list[i].lastName);
                    strcpy(list[i].lastName,list[j].lastName);
                    strcpy(list[j].lastName,auxiliarChar);

                    auxiliarInt=list[i].salary;
                    list[i].salary=list[j].salary;
                    list[j].salary=auxiliarInt;

                    auxiliarInt=list[i].sector;
                    list[i].sector=list[j].sector;
                    list[j].sector=auxiliarInt;
                }
            }
        }
    }

    if(order==2)
    {
        for (i=0; i<len-1; i++);
        {
            for (j=i+1; j<len; j++)
            {
                if(list[i].lastName[0]&& list[i].sector>list[j].lastName[0]&& list[j].sector)
                {
                     auxiliarInt=list[i].id;
                    list[i].id=list[j].id;
                    list[j].id=auxiliarInt;

                    strcpy(auxiliarChar,list[i].name);
                    strcpy(list[i].name,list[j].name);
                    strcpy(list[j].name,auxiliarChar);

                    strcpy(auxiliarChar,list[i].lastName);
                    strcpy(list[i].lastName,list[j].lastName);
                    strcpy(list[j].lastName,auxiliarChar);

                    auxiliarInt=list[i].salary;
                    list[i].salary=list[j].salary;
                    list[j].salary=auxiliarInt;

                    auxiliarInt=list[i].sector;
                    list[i].sector=list[j].sector;
                    list[j].sector=auxiliarInt;

                }
            }
        }
    }




return 0;
}

/*
//2.6 Función printEmployees
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*


int printEmployees(Employee* list, int length)
{
//Imprime el array de empleados de forma encolumnada.
return 0;
}
*/
