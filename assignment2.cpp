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
//Constructor to assign a default NULL value to all the members of class employee
    employee()                                               
    {                                      
        empno = 0;
        name = "NULL";
        salary = 0;
        allowance = 0;
    }

//Overloaded function input for giving predefined values for a new employee (eg:salary, allowance)  
    void input(std::string n, int num)
    {
        name = n;
        empno = num;
        salary = 30000;
        allowance = 10000;
    }

//Overloaded function input for accepting the info of a exisiting employee i.e. their info and expenses
    void input(float s, std::string n, float a, int num)
    {
        empno = num;
        name=n;
        salary = s;
        allowance = a;
    }

//Operator overloading for the purposes of giving the employee a raise when needed
    employee operator++(int)
    {
        employee e = *this;
        salary += 5000;
        allowance += 500;
        return e;
    }

//Operator overloading for the purpose of deducting the salary of an employee
    employee operator--(int)
    {
        employee e = *this;
        salary -= 1000;
        allowance -= 500;
        return e;
    }

//Operator overloading to copy values from one employee object to another
    employee operator=(employee e)
    {
        empno = e.empno;
        name = e.name;
        salary = e.salary;
        allowance = e.allowance;
        return *this;
    }

//A normal display member function of class employee
    void disp()
    {
        std::cout << "\nEmpno: " << empno << "\t\tEmployee Name: " << name;
        std::cout << "\nSalary: " << salary << "\t\tAllowance: " << allowance;
        std::cout << "\n";
    }

//A few friend functions have been declared for access private members of the classes
//Without adding extra unnecessary member functions 
    friend void del(int n);
    friend void bonus(int num);
    friend void ded(int num);

//A userdefined destructor altho works as a default destructor
    ~employee(){}
} emp[15];                      //Global variables including a class arrray which can be accessed by 
int n{0};bool check{0};         //functions including the main()

//Function for the purpose of adding new employees depending on whether they are new or exisiting 
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

//Function to delete employees from the registry 
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

//A function used to allocate bonuses to a specific employee
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

//A function to deduct pay of a specific employee
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

//main() of the program
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
