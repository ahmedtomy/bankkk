//
// Created by Admin on 8/22/2024.
//

#ifndef BANK_MTB_CLIENT_H
#define BANK_MTB_CLIENT_H
#include "Person.h"
#include <fstream>
class Client : public Person {
private:
    double balance;

public:
    Client() : Person() {
        balance = 0;
    }

    Client(int id, string name, string password,double balance) : Person(id, name, password) {
        this->setbalance(balance) ;
    }
    Client(string name, string password,double balance) : Person(name, password) {
        this->setbalance(balance) ;
    }
    void setbalance(double b) {
        if( Validation::IsValidBalance(b))
        balance = b;
        else
            cout<<"not enough balance";
    }

    double getbalance() const {
        return balance;
    }

    double deposit(double amount) {
        balance += amount;
        return balance;
    }

    double withdraw(double amount) {
        if (amount <= balance) {
            balance -= amount;
        } else {
            cout << "Not enough balance" << endl;
        }
        return balance;
    }

    void transferto(Client& m, double amount) {
        if (amount <= balance) {
            balance -= amount;
            m.deposit(amount);
        } else {
            cout << "Not enough balance" << endl;
        }
    }

    double checkbalance() {
        return balance;
    }

    void display() {
        cout << "Client details: " << endl;
        cout << "ID = " << id << endl;
        cout << "Name = " << name << endl;
        cout << "Password = " << password << endl;
        cout << "Balance = " << balance << endl;
    }
    // void savetofile(const string& filename)  {
    //     Person::savetofile(filename);
    //     fstream file;
    //     file.open(filename, ios::out | ios::app);
    //     if (file.is_open()) {
    //         file << getbalance() <<"&";
    //         file << "==========================" << endl;
    //         file.close();
    //     } else {
    //         cout << "Error with file" << endl;
    //     }
    // }

};


#endif //BANK_MTB_CLIENT_H
