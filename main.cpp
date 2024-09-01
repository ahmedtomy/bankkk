#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
#include "Validation.h"
#include "Admin.h"
#include "Client.h"
#include "Employee.h"
#include "Parser.h"
#include <vector>
using namespace std;

int main() {
    cout << "Welcome to the bank system" << endl;
    Admin admin("tmatmayaa","midomidos",400000);
    admin.display();
    Employee employee;
    Client Client("tofyyyyy","jkasjhk",9300);
    Client.savetofile("Clientfile");
    admin.savetofile("Adminfile");
    employee.setsalary(760000);
   employee.savetofile("Employeefile");
   
}
