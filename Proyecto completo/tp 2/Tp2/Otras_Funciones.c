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
            if(list[i].isEmpty==TRUE)
            {
            Id=i;
            printf("ID , %d \n",Id);
            break;
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

float getFloatSalary(char mensaje[])
{
    float auxiliar;
    printf("%s",mensaje);
    scanf("%f",&auxiliar);
    return auxiliar;
}
int getIntSector(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
int getIntModificarName(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    while(auxiliar<1||auxiliar>2)
    {
        printf("Ingresar numero de Id para modificar");
        scanf("%d",&auxiliar);
    }
    return auxiliar;
}
int getIntNumId(char mensaje[])
{
    int auxiliar;
    printf("%s",mensaje);
    scanf("%d",&auxiliar);
    return auxiliar;
}
int mostrarId(Employee* list, int len)
{
  int i;
      for(i=0;i<len;i++)
        {
         if(list[i].isEmpty==FALSE)
         {
          printf("Id: %d, *Nombre: %s, *Apellido: %s, *Sector: %d \n",i, list[i].name, list[i].lastName,list[i].sector);
         }
        }

}
void modificarNombre(Employee* list, int len, int IdOpcion,char name[])
{
    int i;

      for(i=0;i<len;i++)
        {
         if(i==IdOpcion)
         {
          strcpy(list[i].name,name);
         }
        }
}
void modificarApellido(Employee* list, int len, int IdOpcion,char lastName[])
{
      int i;
      for(i=0;i<len;i++)
        {
         if(i==IdOpcion)
         {
          strcpy(list[i].lastName,lastName);
         }
        }
}
