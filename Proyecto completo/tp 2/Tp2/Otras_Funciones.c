#include <stdio.h>
#include <stdlib.h>
#include "Array_de_Employee.h"
#include "Otras_Funciones.h"
#define LEN 3
#define TRUE 1
#define FALSE 0

int newId(Employee* list, int len)
{
    /*
    El Id a asignar es  una posicion vacia en el vector es un numero unico
    */
  int i;
  int Id;

      for(i=0;i<len;i++)
        {
            if(list[i].isEmpty=TRUE)
            {
            Id=i;
            }
        }
 return Id;
}
int getIntMenu(char mensaje[],Employee* list, int len,int opcionMenu)
{
    int auxiliar;
    int opcionReturn;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    opcionReturn=validarOpcionMenu(auxiliar,list, len,opcionMenu);

    return opcionReturn;

}
int getOpcionMenu(int opcion,Employee* list, int len, int opcionMenu)
{


    while (opcionMenu==0)
        {
            printf("Primero debe cargar al menos un empleado");
            opcion=getIntMenu(" Menu de opciones\n Ingrese una opcion\n 1-ALTAS:\n 2-MODIFICAR\n 3-BAJAS\n 4-INFORMAR:\n 5-SALIR \n");
        }

  return opcion;
}
int getOpcionMenuU(int opcion,Employee* list, int len)
{
    while (opcion<1||opcion>5)
    {
        printf("Ingrese una opcion ");
        scanf("%d",&opcion);

    }
}
