#include <iostream>
#include <string>
#include <cstring>
class badch{};
class invalid{};
class employee
{ 
public:
    int empno{};
    std::string name{};
    float salary{}, allowance{};
    employee()
    {
        empno = 0;
        name = "NULL";
        salary = 0;
        allowance = 0;
    }
    void input()
    {
        std::cout<<"Enter Id and Name\n";
        std::cin>>empno;
        if(empno<0)
            throw invalid();
        std::getline(std::cin>>std::ws,name);
        for (int i = 0; i < name.length(); i++)
            if (std::isdigit(name[i]) == 0)
                throw invalid();
        salary = 30000;
        allowance = 10000;
    }
    void input(int n)
    {
        if(n==2)
        {
            std::cout << "Enter Id, Name, Salary and Allowance\n";
            std::cin >> empno;
            if (empno < 0)
                throw invalid();
            std::getline(std::cin >> std::ws, name);
            for(int i=0;i<name.length();i++)
                if (std::isdigit(name[i]) == 0)
                    throw invalid();
            std::cin>>salary>>allowance;
        }
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
    void disp()
    {
        std::cout << "\nEmpno: " << empno << "\t\tEmployee Name: " << name;
        std::cout << "\nSalary: " << salary << "\t\tAllowance: " << allowance<< "\n";
    }
    ~employee() {}
};
class manager:public employee
{
    public:
        manager()
        {
            empno = 0;
            name = "NULL";
            salary = 0;
            allowance = 0;
        }
        manager operator++(int)
        {
            manager e = *this;
            salary += 50000;
            allowance += 5000;
            return e;
        }
        manager operator--(int)
        {
            manager e = *this;
            salary -= 5000;
            allowance -= 2000;
            return e;
        }
};
void details(int n,employee *e,manager *m)
{
    if(n==1)
    {
        std::cout<<"\nEmployee\n";
        e->input();
        e->disp();
        std::cout <<"\nManager\n";
        m->input();
        m->disp();
    }
    else if(n==2)
    {
        std::cout << "\nEmployee\n";
        e->input(n);
        e->disp();
        std::cout << "\nManager\n";
        m->input(n);
        m->disp();
    }
}
int main()
{
    int ch;
    employee e;
    manager m;
    try
    {
        std::cout<<"1.New Recruits\n2.Existing\nChoice: ";
        std::cin>>ch;
        if(ch!=1 && ch!=2)
            throw badch();
        details(ch,&e,&m);
        e.disp();
        m.disp();
        std::cout<<"\nAwarding Bonuses\n";
        e++;
        m++;
        std::cout<<"\nEmployee";
        e.disp();
        std::cout<<"\nManager";
        m.disp();
    }
    catch(badch) 
    {
        std::cout<<"\nINVALID ENTRY OF CHOICE(1|2 ONLY)"; 
    }
    catch(invalid) 
    {
        std::cout<<"\nIMPROPER DATA ENTRY";
    }
}