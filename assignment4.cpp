#include <iostream>
#include <string>
#include <cstring>
class employee
{
private:
    int empno{};
    std::string name{};
    float salary{}, allowance{};

public:
    employee()
    {
        empno = 0;
        name = "NULL";
        salary = 0;
        allowance = 0;
    }
    void input(std::string n, int num)
    {
        name = n;
        empno = num;
        salary = 30000;
        allowance = 10000;
    }
    void input(float s, std::string n, float a, int num)
    {
        empno = num;
        name = n;
        salary = s;
        allowance = a;
    }
    employee operator++(int)
    {
        employee e = *this;
        salary += 5000;
        allowance += 500;
        return e;
    }
    employee operator--(int)
    {
        employee e = *this;
        salary -= 1000;
        allowance -= 500;
        return e;
    }
    employee operator=(employee e)
    {
        empno = e.empno;
        name = e.name;
        salary = e.salary;
        allowance = e.allowance;
        return *this;
    }
    void disp()
    {
        std::cout << "\nEmpno: " << empno << "\t\tEmployee Name: " << name;
        std::cout << "\nSalary: " << salary << "\t\tAllowance: " << allowance;
        std::cout << "\n";
    }
    ~employee() {}
}
class manager:public employee
{
    int empno{};
    std::string name{};
    float salary{}, allowance{};
    public:
        manager operator++(int)
        {
            manager e = *this;
            salary += 5000;
            allowance += 500;
            return e;
        }

        //Operator overloading for the purpose of deducting the salary of an employee
        manager operator--(int)
        {
            manager e = *this;
            salary -= 1000;
            allowance -= 500;
            return e;
        }

        //Operator overloading to copy values from one employee object to another
        manager operator=(manager e)
        {
            empno = e.empno;
            name = e.name;
            salary = e.salary;
            allowance = e.allowance;
            return *this;
        }
}