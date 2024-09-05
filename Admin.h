//
// Created by Admin on 8/22/2024.
//

#ifndef BANK_MTB_ADMIN_H
#define BANK_MTB_ADMIN_H

#include "Person.h"
#include "Employee.h"
class Admin : public Employee {
public:
    Admin(int id, string name, string password, double salary)
            : Employee(id, name, password, salary) {
    }

    Admin(string name, string password, double salary)
            : Employee(name, password, salary) {
    }

    void display()  {
        cout << "Admin details: " << endl;
        Employee::display();
    }
    // void savetofile(const string &filename) {
    //     Person::savetofile(filename);
    //     fstream file;
    //     file.open(filename, ios::out | ios::app);
    //     if (file.is_open()) {
    //         file << getsalary() <<"&";
    //         file << "==========================" << endl;
    //         file.close();
    //     } else {
    //         cout << "Error with file" << endl;
    //     }
    // }


};


#endif //BANK_MTB_ADMIN_H
