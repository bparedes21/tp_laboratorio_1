#ifndef OTRAS_FUNCIONES_H_INCLUDED
#define OTRAS_FUNCIONES_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

int newId(Employee* list, int len,int contadorId);
int getIntMenu(char mensaje[]);
int numberBetweenOneAndFive(int opcion);
int compareOptionEqualToOne(int opcionMenu);
float getFloatSalary(char mensaje[]);
int isNumeric(char numero[]);
int getIntSector(char mensaje[]);
int getIntOpcion(char mensaje[]);
int getIntNumId(char mensaje[],Employee* list,int len);
char primeraLetraMayuscula(char contieneLetras[]);
void modificarApellido(Employee* list, int len, int IdOpcion,char lastName[]);
void modificarNombre(Employee* list, int len, int IdOpcion,char name[]);
int comprobarId(Employee* list, int len,int idIngresado);
int onlyLetters(char nameLastName[]);
void calcularTotalyPromedio (Employee* list, int len,int contadorEmpleados);
void hardCodearPerfil(Employee listEmploye[]);
int cantidadDeSectores(Employee* listEmploye,int len);

#endif // OTRAS_FUNCIONES_H_INCLUDED
