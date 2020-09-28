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
    int  nameIsChar;
    char lastName[51];
    float salary;
    int sector;
    int i;
    int contadorId;
    int lenToLower;
    int IdOpcion;
    int opcionNombreOApellido;
    int contadorEmployee;
    int opcionOrder;
    contadorEmployee=0;
    nameIsChar=0;
    contadorId=100;

    returnInitEmployees=initEmployees(list, LEN);

    opcionMenu=getIntMenu("Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR:\n 3-BAJAS:\n 4-INFORMAR:\n 5-SALIR \n");
    opcionMenu=numberBetweenOneAndFive(opcionMenu);


    do
    {
        if(contadorEmployee==0)
        {
            opcionMenu=compareOptionEqualToOne(opcionMenu);
        }
        switch (opcionMenu)
        {
        case 1://ALTAS: Se debe permitir ingresar un empleado calculando automáticamente el número
            contadorId++;
            newID=newId(list, LEN, contadorId);
            if(newID==-1)
            {
                printf("No hay mas espacio para un nuevo ID \n");
            }
            else
            {
                printf("Ingrese Nombre \n");
                fflush(stdin);
                scanf ("%[^\n]",name);

                lenToLower=strlen(name);

                for(i=0; i<lenToLower; i++)
                {
                    name[i]=tolower(name[i]);

                }

                nameIsChar=onlyLetters(name);

                while(nameIsChar==0)
                {

                    printf("ERROR Ingrese Nombre solo letras \n");
                    fflush(stdin);
                    scanf ("%[^\n]",name);
                    nameIsChar=onlyLetters(name);
                }
                for(i=0; i<lenToLower; i++)
                {
                    if(i==0)
                    {
                        name[i]=toupper(name[i]);
                    }
                    else
                    {
                        if(name[i]==' ')
                        {
                            name[i+1]=toupper(name[i+1]);
                        }
                    }

                }
                printf("Ingrese Apellido \n"); //Apellido
                fflush(stdin);
                scanf ("%[^\n]",lastName);
                lenToLower=strlen(lastName);

                for(i=0; i<lenToLower; i++)
                {
                    lastName[i]=tolower(lastName[i]);

                }
                nameIsChar=onlyLetters(lastName);
                while(nameIsChar==0)
                {
                    printf("%d",nameIsChar);
                    printf("ERROR Ingrese Apellido solo letras \n");
                    fflush(stdin);
                    scanf ("%[^\n]",name);
                    nameIsChar=onlyLetters(name);

                }
                for(i=0; i<lenToLower; i++)
                {
                    if(i==0)
                    {
                        lastName[i]=toupper(lastName[i]);
                    }
                    else
                    {
                        if(lastName[i]==' ')
                        {
                            lastName[i+1]=toupper(lastName[i+1]);
                        }
                    }

                }


                salary=getFloatSalary("Ingrese el salario \n");
                sector=getIntSector("Ingrese el sector \n");

                addEmployee(list,LEN, newID, name, lastName,salary, sector);
                contadorEmployee++;
            }

            break;

        case 2://MODIFICAR: Se ingresará el Número de Id, permitiendo modificar: o Nombre o Apellido
            mostrarEmpleados(list,LEN);
            IdOpcion=getIntNumId("Ingresar numero de empleado para modificar\n",list, LEN);

            opcionNombreOApellido=getIntOpcion("Ingrese \n 1- para modificar *Nombre \n 2- para modificar *Apellido \n");
            switch (opcionNombreOApellido)
            {
            case 1:
                printf("Ingrese Nombre \n");
                fflush(stdin);
                scanf ("%[^\n]",name);

                lenToLower=strlen(name);

                for(i=0; i<lenToLower; i++)
                {
                    name[i]=tolower(name[i]);

                }

                nameIsChar=onlyLetters(name);

                while(nameIsChar==0)
                {
                    printf("ERROR Ingrese Nombre solo letras \n");
                    fflush(stdin);
                    scanf ("%[^\n]",name);
                    nameIsChar=onlyLetters(name);
                }
                for(i=0; i<lenToLower; i++)
                {
                    if(i==0)
                    {
                        name[i]=toupper(name[i]);
                    }
                    else
                    {
                        if(name[i]==' ')
                        {
                            name[i+1]=toupper(name[i+1]);
                        }
                    }

                }

                modificarNombre(list, LEN, IdOpcion, name);

                break;

            case 2:
                printf("Ingrese *Apellido \n"); //Apellido
                fflush(stdin);
                scanf ("%[^\n]",lastName);
                lenToLower=strlen(lastName);

                for(i=0; i<lenToLower; i++)
                {
                    lastName[i]=tolower(lastName[i]);

                }
                for(i=0; i<lenToLower; i++)
                {
                    if(i==0)
                    {
                        lastName[i]=toupper(lastName[i]);
                    }
                    else
                    {
                        if(lastName[i]==' ')
                        {
                            lastName[i+1]=toupper(lastName[i+1]);
                        }
                    }


                }

                modificarApellido(list, LEN, IdOpcion, name);
                break;
            }
            break;

        case 3://BAJA: Se ingresará el Número de Id y se eliminará el empleado del sistema.
            mostrarEmpleados(list,LEN);
            IdOpcion=getIntNumId("Ingresar numero de empleado para eliminar el empleado del sistema\n",list, LEN);
            findEmployeeById(list,LEN,IdOpcion);
            removeEmployee(list, LEN, IdOpcion);
            mostrarEmpleados(list,LEN);
            contadorEmployee--;
            break;


        case 4://4. INFORMAR:
                opcionOrder=getIntOpcion("Ordenar alfabeticamente por Apellido y Sector \nIngrese una opcion para ordenar: \n 1-Manera ascendente:\n 2-Manera descendente:\n");

             // 1. Listado de los empleados ordenados alfabéticamente por Apellido y Sector.
                sortEmployees(list, LEN, opcionOrder);
                mostrarEmpleados(list,LEN);
            // 2. Total y promedio de los salarios, y cuántos empleados superan el salario promedio

                break;
                break;
                /*
            case 5:
                break;
                */
            }

            opcionMenu=getIntMenu("Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR:\n 3-BAJAS:\n 4-INFORMAR:\n 5-SALIR \n");
            opcionMenu=numberBetweenOneAndFive(opcionMenu);

        }
        while (opcionMenu!=5);
        return 0;

    }



