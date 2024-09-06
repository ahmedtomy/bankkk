//
// Created by Admin on 8/22/2024.
//

#ifndef BANK_MTB_EMPLOYEE_H
#define BANK_MTB_EMPLOYEE_H
#include "Person.h"
#include <fstream>
#include "Client.h"
#include "FilesHelper.h"
class Employee : public Person{
private:
    double salary;

public:
    Employee() {
        salary=0;
    }

    Employee(int i, string n, string p, double s):Person(i,n,p) {
        setsalary(s);
    }
    Employee(string n, string p, double s):Person (n,p){
        setsalary(s);
    }

    void setsalary(double s) {
        if (Validation::IsValidSalary(s))
            salary = s;
        else
            cout << "salary not accepted less than 5000" << endl;
    }

    double getsalary() const{
        return salary;
    }

    void display() {
        cout << " details: " << endl;
        cout << "ID = " << id << endl;
        cout << "Name = " << name << endl;
        cout << "Password = " << password << endl;
        cout << "Salary = " << salary << endl;
    }
    friend std::ostream& operator<<(std::ostream& os, const Employee& employee) {
        os << "Client ID: " << employee.getid() << "\n"
           << "Name: " << employee.getname() << "\n"
           << "Password"<<employee.getpassword()<<"\n"
           << "Salary " << employee.getsalary();
        return os;
    }

    void addclient(Client &client){
     FilesHelper::clients.push_back(client);       
    }



    Client searchClient(int id){
    for (int i = 0; i < FilesHelper::clients.size(); i++)
    {
        if(FilesHelper::clients[i].getid()==id){
            return FilesHelper::clients[i];
        }
    }
    
    }



    void listClient(){
        for (int i = 0; i < FilesHelper::clients.size(); i++)
        {
             FilesHelper::clients[i].display();
        }
        
    }





    void editClient(int id, string name, string password, double balance){
         for (int i = 0; i < FilesHelper::clients.size(); i++)
         {
            if(FilesHelper::clients[i].getid()==id){
               FilesHelper::clients[i].setname(name);
               FilesHelper::clients[i].setpassword(password);
               FilesHelper::clients[i].setbalance(balance);
            }
            else{
                continue;
            }
         }
         
    }

    // void savetofile(const string& filename) {
    //     Person::savetofile(filename);
    //     fstream file;
    //     file.open(filename, ios::out | ios::app);
    //     if (file.is_open()) {
    //         file << getsalary() <<"&"<<endl;
    //         file << "==========================" << endl;
    //         file.close();
    //     } else {
    //         cout << "Error with file" << endl;
    //     }
    // }
};


#endif //BANK_MTB_EMPLOYEE_H
