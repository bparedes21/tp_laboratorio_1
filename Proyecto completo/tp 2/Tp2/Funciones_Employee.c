#include <stdio.h>
#include <stdlib.h>
#include "Array_de_Employee.h"
#include "Otras_Funciones.h"
#define LEN 3
#define TRUE 1
#define FALSE 0


//2.1 Funci�n initEmployees
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
/* Para indicar que todas las posiciones del array est�n vac�as, esta funci�n pone la bandera
(isEmpty) en TRUE en todas las posiciones del array.*/
  int i;
  int Error=-1;
  if(list!=NULL&&len>=0)
  {   Error=0;
      for(i=0;i<len;i++)
        {
        list[i].isEmpty =TRUE;
        }
  }
return Error;
}

//2.2 Funci�n addEmployees
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
/*
Agrega en un array de empleados existente los valores recibidos como par�metro en la primer
posici�n libre.
*/
return -1;
}


//2.3 Funci�n findEmployeeById

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

//Busca un empleado recibiendo como par�metro de b�squeda su Id.

return NULL;
}

//2.4 Funci�n removeEmployee
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

//Elimina de manera l�gica (isEmpty Flag en 1) un empleado recibiendo como par�metro su Id.
return -1;
}

//2.5 Funci�n sortEmployeeByName
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

//Ordena el array de empleados por apellido y sector de manera ascendente o descendente./
return 0;
}

//2.6 Funci�n printEmployees
/** \brief print the content of employees array
*
* \param list Employee*
* \param length int
* \return int
*
*/

int printEmployees(Employee* list, int length)
{
//Imprime el array de empleados de forma encolumnada.
return 0;
}
