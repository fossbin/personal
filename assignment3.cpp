#include<iostream>
#include<string>
#include<cstring>
class employee{
    private:
            int empno{};
            char* name{};
            float salary{},allowance{};
    public:
            employee(){
                empno=0;
                name=NULL;
                salary=0;
                allowance=0;
            }
            void input(char* n,int num){
                name=n;
                empno=num;
                salary=30000;
                allowance=10000;
            }
            void input(float s,char *n, float a, int num)
            {
                empno=num;
                strcpy(name,n);
                salary=s;
                allowance=a;
            }
            employee operator++(int)
            {
                employee e=*this;
                salary += 5000;
                allowance += 500;
                return e;
            }
            employee operator--(int){
                employee e=*this;   
                salary-=1000;
                allowance-=500;
                return e;
            }
            employee operator =(employee e){
                empno=e.empno;
                name=e.name;
                salary=e.salary;
                allowance=e.allowance;
                return *this;
            }
            friend void disp(employee e);
            friend void del(int n);
            ~employee(){
                delete name;
            }
}emp[15];int n{0};
void add(){
    int ch,n;
    float s,a;
    std::string name;
    employee e1;
    std::cout<<"\n1)Exisiting Employee\t\t2)New employee\nEnter your choice: ";
    std::cin>>ch;
    if(ch==1)
    {
        std::cout<<"\nEnter the following details of the employee: ";
        std::cout<<"Employee Number, Employee Name, Salary and Allowance\n";
        std::cin>>n;
        std::getline(std::cin>>std::ws,name);
        std::cin>>s>>a;
        e1.input(s,&name[0],a, n);
    }
    else if(ch==2)
    {
        std::cout<<"\nEnter the following details of the new employee: ";
        std::cout<<"Employee Number, Employee Name\n";
        std::cin>>n;
        std::getline(std::cin>>std::ws,name);
        e1.input(&name[0], n);
    }

}
void del(int num){
    for(int i=0;i<n;i++)
        if(num==emp[i].empno)
            emp[i]=emp[i+1];
}
void bonus(int n){
    std::cout<<"\nEmployee has been awarded bonus\n";
    emp[n]++;
    disp(emp[n]);
}
void ded(int n){
    std::cout<<"\nEmployee's pay has been deducted\n";
    emp[n]--;
    disp(emp[n]);

}
void disp(employee e){
    std::cout<<"\nEmpno: "<<e.empno<<"\t\tEmployee Name: "<<e.name;
    std::cout<<"\nSalary: "<<e.salary<<"\t\tAllowance: "<<e.allowance;
    std::cout<<"\n";
}
int main(){
    int ch,num;
    std::cout<<"\nEnter Number of Employees: ";
    std::cin>>n;
    while (1)
    {
        std::cout << "\nMENU\n1.Add Employee\n2.Delete Employee\n3.Award Bonus\n4.Deduction";
        std::cout<<"\n5.Display\n6.Exit\nEnter your choice: ";
        std::cin >> ch;
        switch(ch){

            case 1: for(int i=0;i<n;i++)
                    add();
                    break;

            case 2: std::cout << "\nEnter Empno of employee: ";
                    std::cin >> num;
                    del(num);
                    break;

            case 3: std::cout<<"\nEnter Empno of employee: ";
                    std::cin>>num;
                    bonus(num);
                    break;

            case 4: std::cout << "\nEnter Empno of employee: ";
                    std::cin >> num;
                    ded(num);
                    break;

            case 5: for(int i=0;i<n;i++)
                        disp(emp[i]);
                    break;

            case 6: exit(0);
                    break;
            default:std::cout<<"\nINVALID OPTION";
        }
    }
}