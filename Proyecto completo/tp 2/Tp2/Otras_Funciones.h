#ifndef OTRAS_FUNCIONES_H_INCLUDED
#define OTRAS_FUNCIONES_H_INCLUDED

int newId(Employee* list, int len);
int getIntMenu(char mensaje[]);
int numberBetweenOneAndFive(int opcion);
int compareOptionEqualToOne(opcionMenu);
float getFloatSalary(char mensaje[]);
int getIntSector(char mensaje[]);
int getIntModificarName(char mensaje[]);
int getIntNumId(char mensaje[]);
int mostrarId(Employee* list, int len);
char primeraLetraMayuscula(char contieneLetras[]);
void modificarApellido(Employee* list, int len, int IdOpcion,char lastName[]);
void modificarNombre(Employee* list, int len, int IdOpcion,char name[]);

#endif // OTRAS_FUNCIONES_H_INCLUDED
