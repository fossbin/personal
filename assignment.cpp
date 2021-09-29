#include<iostream>
class worker 
{
    int id;
    std::string name;
    public:
            virtual void enter()
            {
                std::cout << "\nWORKER DETAILS\n";
                std::cout<<"Enter Id and Name: ";
                std::cin>>id;
                std::getline(std::cin>>std::ws,name);

            }
};
class manager:public worker
{
    int id;
    std::string name;
    std::string depart;
    public:
            virtual void enter()
            {
                std::cout << "\nMANAGER DETAILS\n";
                std::cout << "Enter Id and Name: ";
                std::cin >> id;
                std::getline(std::cin >> std::ws, name);
                std::cout<<"Department(Sales/Research/HR): ";
                std::getline(std::cin>>std::ws,depart);
            }
};
class ceo:public manager
{
    int id,personnel;
    std::string name;
    std::string boardID;
    public:
        virtual void enter()
        {
            std::cout << "\nCEO DETAILS\n";
            std::cout << "Enter Id and Name: ";
            std::cin >> id;
            std::getline(std::cin >> std::ws, name);
            std::cout << "Board ID: ";
            std::getline(std::cin >> std::ws,boardID);
            std::cout<<"Personnel Number: ";
            std::cin>>personnel;
        }

};
int main()
{
    worker *ptr1, *ptr2;
    manager *ptr3, m;
    ceo c;
    ptr1=new worker;
    ptr2=&m;    
    ptr3=&c;
    ptr1->enter();
    ptr2->enter();
    ptr3->enter();
}