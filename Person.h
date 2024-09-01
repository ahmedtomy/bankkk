//
// Created by Admin on 8/22/2024.
//

#ifndef BANK_MTB_PERSON_H
#define BANK_MTB_PERSON_H

#include "Validation.h"
#include <string>
#include <iostream>
#include <fstream>
using namespace std;
class Person {
protected:
    int id;
    string name;
    string password;
    static int nextid;

public:
    Person() {
        id = 0;
    }

    Person(string name, string password) {
        this->name = name;
        this->password = password;
    }

    Person(int id, string name, string password) {
        this->id = id;
        this->name = name;
        this->password = password;
    }

    void setname(string n) {
        if (Validation::IsValidName(n))
            name = n;
        else
            cerr << "name not valid" << endl;
    }

    void setpassword(string p) {
        if (Validation::IsValidpassword(p))
            password = p;
        else
            cerr << "password not valid" << endl;
    }

    string getpassword() const {
        return password;
    }

    string getname() const{
        return name;
    }

    int getid() const{
        return id;
    }

    virtual void display() = 0;


    virtual void savetofile(const string& filename) {
        fstream file;
        file.open(filename, ios::out | ios::app);
        if (file.is_open()) {
            file << "ID = " << getid() << "&";
            file << "Name = " << getname() << "&";
            file << "Password = " << getpassword() << "&";
            file << endl;
        } else {
            cout << "Error with file" << endl;
        }
        file.close();
    }

};


#endif //BANK_MTB_PERSON_H
