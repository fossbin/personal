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
        name=n;
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
    friend void del(int n);
    friend void bonus(int num);
    friend void ded(int num);
    ~employee()
    {
        //Destructor called
    }
} emp[15];
int n{0};bool check{0};
employee add(employee e1)
{
    int ch, n;
    float s, a;
    std::string name;
    if(::check==1)
        ::++n;
    std::cout << "\n1)Exisiting Employee\t\t2)New employee\nEnter your choice: ";
    std::cin >> ch;
    if (ch == 1)
    {
        std::cout << "\nEnter the following details of the employee: ";
        std::cout << "Employee Number, Employee Name, Salary and Allowance\n";
        std::cin >> n;
        std::getline(std::cin >> std::ws, name);
        std::cin >> s >> a;
        e1.input(s, name, a, n);
    }
    else if (ch == 2)
    {
        std::cout << "\nEnter the following details of the new employee: ";
        std::cout << "Employee Number, Employee Name\n";
        std::cin >> n;
        std::getline(std::cin >> std::ws, name);
        e1.input(name, n);
    }
    return e1;
}
void del(int num)
{
    if(::n==0)
        std::cout<<"\nNo employees found";
    else {
        for (int i = 0; i < n; i++)
            if (num == emp[i].empno)
            { 
                std::cout<<"\nDetails of the Employee";
                emp[i].disp();
                for(int j=i;j<n;j++)    
                    emp[j] = emp[j + 1];
                break;
                ::--n;
                ::check=1;
            }
    }
}
void bonus(int num)
{
    std::cout << "\nEmployee has been awarded bonus\n";
    for(int i=0;i<n;i++)
        if(emp[i].empno==num) {
            emp[i]++;
            emp[i].disp();
            break;
        }
}
void ded(int num)
{
    std::cout << "\nEmployee's pay has been deducted\n";
    for (int i = 0; i < n; i++)
        if (emp[i].empno == num)
        {
            emp[i]--;
            emp[i].disp();
            break;
        }
}
int main()
{
    int ch, num;
    std::cout << "\nEnter Number of Employees: ";
    std::cin >>::n;
    while (1)
    {
        std::cout << "\nMENU\n1.Add Employee\n2.Delete Employee\n3.Award Bonus\n4.Deduction";
        std::cout << "\n5.Display\n6.Exit\nEnter your choice: ";
        std::cin >> ch;
        switch (ch)
        {

        case 1:
            for (int i = 0; i < n; i++)
                emp[i]=add(emp[i]);
            break;

        case 2:
            std::cout << "Enter Empno of employee: ";
            std::cin >> num;
            del(num);
            break;

        case 3:
            std::cout << "Enter Empno of employee: ";
            std::cin >> num;
            bonus(num);
            break;

        case 4:
            std::cout << "Enter Empno of employee: ";
            std::cin >> num;
            ded(num);
            break;

        case 5:
            for (int i = 0; i < ::n; i++)
                emp[i].disp();
            break;

        case 6:
            exit(0);
            break;
        default:
            std::cout << "\nINVALID OPTION";
        }
    }
}
