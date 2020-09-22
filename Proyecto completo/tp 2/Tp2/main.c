#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array_de_Employee.h"
#include "Otras_Funciones.h"
#define LEN 3
#define TRUE 1
#define FALSE 0
/*El sistema deberá tener el siguiente menú de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
de Id. El resto de los campos se le pedirá al usuario.
2. MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio.

Se deberá realizar el menú de opciones y las validaciones a través de funciones.
Tener en cuenta que no se podrá ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de algún empleado.
*/

int main()
{
    Employee list[LEN];
    int returnInitEmployees;
    int opcionMenu;
    int newID;
    int isEmpty;
    char  name[51];
    char lastName[51];
    float salary;
    int sector;


    returnInitEmployees=initEmployees(list, LEN);

    opcionMenu=getIntMenu("Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR:\n 3-BAJAS:\n 4-INFORMAR:\n 5-SALIR \n");
    opcionMenu=numberBetweenOneAndFive(opcionMenu);
    opcionMenu=compareOptionEqualToOne(opcionMenu);

    do
    {
        switch (opcionMenu)
        {
        case 1://ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
            newID=newId(list, LEN);

            printf("Ingrese Nombre \n"); // nombre
            fflush(stdin);
            scanf ("%[^\n]",name);
            printf("Ingrese Apellido \n"); //Apellido
            fflush(stdin);
            scanf ("%[^\n]",lastName);
            printf("Ingrese el salario \n"); // salario
            scanf ("%f",&salary);
            printf("Ingrese el sector \n"); //sector
            scanf ("%d",&salary);
            addEmployee(list,LEN, newID, name, lastName,salary, sector);
            break;
            /*
             case 2://MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
                break;
                 case 3://BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
                break;
                 case 4://4. INFORMAR:

                    switch ()
                    {
                    case 1:
                        break;
                    case 2:
                        break;


                    // 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
                    // 2. Total y promedio de los salarios, y cuántos empleados superan el salario promed
                break;
                 case 5:
                break;*/
        }
        //opcionMenu=getIntMenu("Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR:\n 3-BAJAS:\n 4-INFORMAR:\n 5-SALIR \n");
        //opcionMenu=numberBetweenOneAndFive(opcionMenu);
    }
    while (opcionMenu!=5);
    return 0;
}

