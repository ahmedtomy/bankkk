//
// Created by Admin on 8/22/2024.
//

#ifndef BANKBGD_PARSER_H
#define BANKBGD_PARSER_H
#include <vector>
#include <string>
#include "Client.h"
#include"Employee.h"
#include"Admin.h"
using namespace std;
class Parser {
public:

    static vector<string> split(string &line) {
        vector<string> Vector;
        string string1 = "";
        for (char c: line) {
            if (c == '&') {
                Vector.push_back(string1);
            } else {
                string1 += c;
            }
        }
        if (!string1.empty()) {
            Vector.push_back(string1);
            string1.clear();
        }
        return Vector;
    }



    static Client parseToClient(string& line) {

        vector<string> Vector= split(line);

        if (Vector.size() >= 4) {
            int id = stoi(Vector[0]);
            string name = Vector[1];
            string password= Vector[2];
            double balance = stod(Vector[3]);



            Client client(id, name, password,balance);
            client.setbalance(balance);
            client.setname(name);
            client.setpassword(password);

            return client;
        }


    }
    static Employee parseToEmployee(string &line){
        vector<string> Vector1=split(line);
        int id = stoi(Vector1[0]);
        string name = Vector1[1];
        string password= Vector1[2];
        double salary= stod(Vector1[3]);
       
       Employee Employee(id,name,password,salary);
       Employee.setsalary(salary);
       Employee.setname(name);
       Employee.setpassword(password);

       return Employee;

    }

    static Admin parseToAdmin(string &line){
        vector<string> Vector2=split(line);
        int id = stoi(Vector2[0]);
        string name = Vector2[1];
        string password= Vector2[2];
        double salary= stod(Vector2[3]);
       
       Admin admin(id,name,password,salary);
       admin.setsalary(salary);
       admin.setname(name);
       admin.setpassword(password);

       return admin;
       //inherit parsetoemployee 

    }
};


#endif //BANKBGD_PARSER_H
