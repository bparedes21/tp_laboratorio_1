#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Array_de_Employee.h"
#include "Otras_Funciones.h"
#define LEN 15
#define TRUE 1
#define FALSE 0
/*El sistema deber� tener el siguiente men� de opciones:
1. ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
de Id. El resto de los campos se le pedir� al usuario.
2. MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
o Salario o Sector
3. BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
4. INFORMAR:
1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.

Se deber� realizar el men� de opciones y las validaciones a trav�s de funciones.
Tener en cuenta que no se podr� ingresar a los casos 2, 3 y 4; sin antes haber realizado la
carga de alg�n empleado.
*/

int main()
{
    Employee list[LEN];
    int opcionMenu;
    int newID;
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

    contadorEmployee=10;
    nameIsChar=0;
    contadorId=100; //para usar hardCodearPerfil(list) poner en 110

    initEmployees(list, LEN);
    //hardCodearPerfil(list);

    do
    {
        opcionMenu=getIntMenu("Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR:\n 3-BAJAS:\n 4-INFORMAR:\n 5-SALIR \n");
        opcionMenu=numberBetweenOneAndFive(opcionMenu);
        if(contadorEmployee==0)
        {
            opcionMenu=compareOptionEqualToOne(opcionMenu);
        }
        switch (opcionMenu)
        {
        case 1://ALTAS: Se debe permitir ingresar un empleado calculando autom�ticamente el n�mero
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
                nameIsChar=onlyLetters(name);
                while(nameIsChar==-1)
                {
                    printf("while %d",nameIsChar);
                    printf("ERROR Ingrese Nombre solo letras \n");
                    fflush(stdin);
                    scanf ("%[^\n]",name);
                    nameIsChar=onlyLetters(name);
                }
                for(i=0; i<lenToLower; i++)
                {
                    name[i]=tolower(name[i]);

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


                nameIsChar=onlyLetters(lastName);

                while(nameIsChar==-1)
                {
                    printf("%d",nameIsChar);
                    printf("ERROR Ingrese Apellido solo letras \n");
                    fflush(stdin);
                    scanf ("%[^\n]",lastName);
                    nameIsChar=onlyLetters(lastName);

                }
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


                salary=getFloatSalary("Ingrese el salario \n");
                sector=getIntSector("Ingrese el sector \n");

                addEmployee(list,LEN, newID, name, lastName,salary, sector);
                contadorEmployee++;
            }

            break;

        case 2://MODIFICAR: Se ingresar� el N�mero de Id, permitiendo modificar: o Nombre o Apellido
            printEmployees(list,LEN,contadorEmployee);
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

                while(nameIsChar==-1||nameIsChar==-2)
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

        case 3://BAJA: Se ingresar� el N�mero de Id y se eliminar� el empleado del sistema.
            printEmployees(list,LEN,contadorEmployee);
            IdOpcion=getIntNumId("Ingresar numero de empleado para eliminar el empleado del sistema\n",list, LEN);
            findEmployeeById(list,LEN,IdOpcion);
            removeEmployee(list, LEN, IdOpcion);
            printEmployees(list,LEN,contadorEmployee);
            contadorEmployee--;
            break;


        case 4://4. INFORMAR:
            opcionOrder=getIntOpcion("Ingrese una opcion para: \n1. Listado de los empleados ordenados alfabeticamente por Apellido y Sector.\n2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio.\n");

            switch (opcionOrder)
            {
            case 1:
                opcionOrder=getIntOpcion("Ordenar alfabeticamente por Apellido y Sector \nIngrese una opcion para ordenar: \n 1-Manera ascendente:\n 2-Manera descendente:\n");
                // 1. Listado de los empleados ordenados alfab�ticamente por Apellido y Sector.
                sortEmployees(list, LEN, opcionOrder);
                printEmployees(list,LEN,contadorEmployee);
                break;

            case 2:
                // 2. Total y promedio de los salarios, y cu�ntos empleados superan el salario promedio
                calcularTotalyPromedio (list,LEN,contadorEmployee);
                break;
            }

            break;
            break;

        }
    }
    while (opcionMenu!=5);
    return 0;

}



