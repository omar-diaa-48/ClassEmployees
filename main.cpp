#include <iostream>
#include <string.h>
#include <myHeader.h>
#define EmployeeNumber 10

using namespace std;

class Employee
{
    char *Name, *Address, Gender;
    int Salary, Check;
    static int lastEmp;
    static Employee Emps[EmployeeNumber];

public:
    ///Constructor
    Employee(char *_Name = "Undefined", char *_Address = "Undefined", char _Gender = '/', int _Salary = 0, int _Check = 0)
    {
        Name = new char[20];
        strcpy(Name, _Name);
        Address = new char[50];
        strcpy(Address, _Address);
        Gender = _Gender;
        Salary = _Salary;
        if(Gender != '/')
            Check = 1;
        else
            Check = _Check;
        Emps[lastEmp++] = *this;
        cout<<"Constructor"<<endl;
    }

    ///Copy Constructor
    Employee(const Employee & EmployeeObj)
    {
        Name = new char[20];
        Name = EmployeeObj.Name;
        Address = new char[50];
        Address = EmployeeObj.Address;
        Salary = EmployeeObj.Salary;
        Gender = EmployeeObj.Gender;
        cout<<"Copy Constructor"<<endl;
    }

    //Set and Get
    int getCheck(){return Check;}
    char* getName(){return Name;}
    void setName(char* _Name){Name = _Name; Check = 1;}
    void setAddress(char* _Address){Address = _Address; Check = 1;}
    void setSalary(int _Salary){Salary = _Salary; Check = 1;}
    void setGender(char _Gender){Gender = _Gender; Check = 1;}

    ///Functions
    void PrintData ();
    Employee operator ++(int)
    {
        Employee tempEmp(*this);
        Salary += 100;
        return tempEmp;
    }
    Employee operator ++()
    {
        Salary += 100;
        return *this;
    }
    static void numberOfEmployees()
    {
        cout<<"Number of employees entered are "<<lastEmp<<endl;
    }
    static void namesOfEmployees()
    {
        cout<<"Number of employees are "<<lastEmp<<" and their names are : "<<endl;
        for(int i=0; i<lastEmp; i++)
        {
            cout<<Employee::Emps[i].getName()<<"\t";
        }
        cout<<endl;
    }

    ///Destructor
    ~Employee()
    {
        delete [] Name;
        delete [] Address;
        cout<<"Destructor"<<endl;
    }

    ///Static Function
     /*
    static Employee& getHighestSalary()
    {
        int highSalary = 0, i;
        for(int i=0; i<lastEmp; i++)
        {
            if(Emps[i].Salary > highSalary)
                highSalary = Emps[i].Salary;
        }
        return Emps[i];
    }
     */
};

///Static declaration
int Employee :: lastEmp = 0;

///Functions scoop operator
void Employee::PrintData()
{
    //system("cls");
    if(Check == 0)
    {
        cout<<"Employee's data is empty"<<endl;
        return;
    }
    cout<<"Employee Name : "<<Name<<endl;
    cout<<"Employee Gender : "<<Gender<<endl;
    cout<<"Employee Address : "<<Address<<endl;
    cout<<"Employee Salary : "<<Salary<<endl;
    return;
}

int main()
{
    Employee E1("Omar","Sheraton",'m',5000);
    Employee E2("Mohamed","Makram",'m',4500);

    E1.PrintData();
    E2.PrintData();

    Employee::numberOfEmployees();

    return 0;
}
