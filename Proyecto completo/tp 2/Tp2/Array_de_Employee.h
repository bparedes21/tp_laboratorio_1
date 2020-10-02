#ifndef ARRAY_DE_EMPLOYEE_H_INCLUDED
#define ARRAY_DE_EMPLOYEE_H_INCLUDED
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>

struct
{
    int id;
    char name[51];
    char lastName[51];
    float salary;
    int sector;
    int isEmpty;
} typedef Employee;

//2.1 Función initEmployees
int initEmployees(Employee* list, int len);
//2.2 Función addEmployees
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
//2.3 Función findEmployeeById

int findEmployeeById(Employee* list, int len,int id);
//2.4 Función removeEmployee
int removeEmployee(Employee* list, int len, int id);
//2.5 Función sortEmployeeByName
int sortEmployees(Employee* list, int len, int order);
//2.6 Función printEmployees
int printEmployees(Employee* list, int length , int cantidadEmpleados);
#endif // ARRAY_DE_EMPLOYEE_H_INCLUDED
