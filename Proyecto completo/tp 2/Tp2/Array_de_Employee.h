#ifndef ARRAY_DE_EMPLOYEE_H_INCLUDED
#define ARRAY_DE_EMPLOYEE_H_INCLUDED

struct
{
int id;
char name[51];
char lastName[51];
float salary;
int sector;
int isEmpty;
}typedef Employee;

//2.1 Función initEmployees
int initEmployees(Employee* list, int len);
//2.2 Función addEmployees
int addEmployee(Employee* list, int len, int id, char name[],char lastName[],float salary,int sector);
//2.3 Función findEmployeeById

//2.4 Función removeEmployee

//2.5 Función sortEmployeeByName

//2.6 Función printEmployees

#endif // ARRAY_DE_EMPLOYEE_H_INCLUDED
