// DataSourceInterface.h
#ifndef BANKBGD_DATASOURCEINTERFACE_H
#define BANKBGD_DATASOURCEINTERFACE_H

#include "Client.h"
#include "Employee.h"
#include "Admin.h"

class DataSourceInterface {
public:


    virtual void addClient(const Client& client) = 0;
    virtual void addEmployee(const Employee& employee) = 0;
    virtual void addAdmin(const Admin& admin) = 0;

    virtual void getAllClients() const = 0;
    virtual void getAllEmployees() const = 0;
    virtual void getAllAdmins() const = 0;

    virtual void removeAllClients() = 0;
    virtual void removeAllEmployees() = 0;
    virtual void removeAllAdmins() = 0;


};

#endif // BANKBGD_DATASOURCEINTERFACE_H
