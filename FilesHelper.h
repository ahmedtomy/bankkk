//
// Created by Admin on 9/1/2024.
//

#ifndef BANKBGD_FILESHELPER_H
#define BANKBGD_FILESHELPER_H
#include <iostream>
#include <fstream>
#include <string>
#include<vector>
#include"Client.h"
#include"Employee.h"
#include"Admin.h"
#include"Parser.h"
using namespace std;

class FilesHelper {
public:
static vector<Client> clients;
    static vector<Employee> employees;
    static vector<Admin> admins;





    static void savelast(const string& file,int lastid) {
        
        // id++;

        
        ofstream lastidfileOut(file);
        
        if (!lastidfileOut) {
            cerr << "Error opening file for writing!\n";
            return;
        }
        lastidfileOut.close();
        ofstream lastIdFileOut(file, ios::trunc);
        // Write the incremented ID back to the file
        lastidfileOut << lastid;
        lastidfileOut.close();
    }






    static int getlast(const string& file){

        ifstream lastidfileIn(file);
        if (!lastidfileIn) {
            cerr << "Unable to open file for reading\n";
            return;
        }

        // Declare a variable to store the number
        int id;

        // Read the number from the file
        if (!(lastidfileIn >> id)) {
            cerr << "Error reading number from file\n";
            lastidfileIn.close();
            return;
        }
        lastidfileIn.close();

        return id;
    }





    static void saveClient(Client client){
        vector<Client>clients;
        clients.emplace_back(client);
    }





    static void saveEmployee(string fileName, string lastIdFile, Employee e){
       vector<Employee>employees;
       vector<Admin>admins;
       if (fileName=="Employeefile")
       {
        employees.emplace_back(e);
       }
       else if (fileName=="Adminfile")
       {
        admins.emplace_back(e);
       }
    }
    
       




static void getclients(string&filename){
// Function to read client data from a file and store it in the global vector
    ifstream file(filename);

        if (!file) {
            cerr << "Unable to open file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
                Client client = Parser::parseToClient(line);
                clients.emplace_back(client);
  
    }file.close();
}








static void getemployees(string&filename){
    ifstream file(filename);
    if (!file) {
            cerr << "Unable to open file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
                Employee employee = Parser::parseToEmployee(line);
                employees.emplace_back(employee);
  
    }file.close();
}







static void getadmins(string&filename){
ifstream file(filename);

        if (!file) {
            cerr << "Unable to open file: " << filename << endl;
            return;
        }

        string line;
        while (getline(file, line)) {
            
                Admin admin = Parser::parseToAdmin(line);
                admins.emplace_back(admin);
        }

        file.close();
}










static void clearFile(string fileName, string lastIdFile){
 ofstream fileOut(fileName, ios::trunc);  // Open file with truncation to clear it
    if (!fileOut) {
        cerr << "Error opening file: " << fileName << " for clearing!\n";
        return;
    }
    fileOut.close();  // Close the file to apply truncation

   
    ofstream lastIdFileOut(lastIdFile, ios::trunc);  
    if (!lastIdFileOut) {
        cerr << "Error opening last ID file: " << lastIdFile << " for clearing!\n";
        return;
    }
    lastIdFileOut << 0;  // Write 0 to the file
    lastIdFileOut.close(); 
}


};



#endif //BANKBGD_FILESHELPER_H
