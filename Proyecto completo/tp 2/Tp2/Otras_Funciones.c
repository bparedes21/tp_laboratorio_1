#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  int Id=-1;

      for(i=0;i<len;i++)
        {
            if(list[i].isEmpty=TRUE)
            {
            Id=i;
            }
        }
      if(Id==-1)
      {
      printf("No hay mas espacio para un nuevo ID \n");
      }
 return Id;
}

int getIntMenu(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;

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





char primeraLetraMayuscula(char contieneLetras[])
{
    int len;
    int i;
    char letra;
    len= strlen(contieneLetras);
    for (i=0;i<len;i++)
    {
        if(i==0)
        {
          toupper(contieneLetras[0]);
         // nameLastName= toupper(nameLastName);
         // len[i+1]=nameLastName;
        }
        else
        {
            if(contieneLetras[i]==" ")
            {
              toupper(contieneLetras[i+1]);

            }
        }

    }
    return contieneLetras;
}
