// FileManager.h
#ifndef FILEMANAGER_H
#define FILEMANAGER_H

#include "DataSourceInterface.h"
#include "FilesHelper.h"
#include <iostream>
using namespace std;
class FileManger : public DataSourceInterface {
public:
    void addClient(Client& client) {
        FilesHelper::saveClient(client);
    }
    void addEmployee(Employee& employee){
        FilesHelper::saveEmployee("Employeefile","ClientLastid",employee);
    }
    void addAdmin(Admin& admin){
       FilesHelper::saveEmployee("Adminfile","ClientLastid",admin);
    }
    void getAllClients(){
        FilesHelper::getclients("Clientfile");
        for (int i = 0; i < FilesHelper::clients.size(); i++)
        {
            cout<<FilesHelper::clients[i]<<endl;
        }
    }
    void getAllEmployees(){
        FilesHelper::getclients("Employeefile");
        for (int i = 0; i < FilesHelper::employees.size(); i++)
        {
            cout<<FilesHelper::employees[i]<<endl;
        }
    }
    void getAllAdmins(){
        FilesHelper::getclients("Adminfile");
        for (int i = 0; i < FilesHelper::admins.size(); i++)
        {
            cout<<FilesHelper::admins[i]<<endl;
        }
    }
    void removeAllClients(){
        FilesHelper::clearFile("Clientfile","ClientLastid");
    }
    void removeAllEmployees(){
        FilesHelper::clearFile("Employeefile","ClientLastid");
    }
    void removeAllAdmins(){
        FilesHelper::clearFile("Adminfile","ClientLastid");
    }
};
#endif // FILEMANAGER_H