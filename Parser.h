//
// Created by Admin on 8/22/2024.
//

#ifndef BANKBGD_PARSER_H
#define BANKBGD_PARSER_H
#include <vector>
#include <string>
#include "Client.h"
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
};


#endif //BANKBGD_PARSER_H
