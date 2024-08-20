#include <iostream>
#include <string>
#include <cctype>
#include <fstream>
using namespace std;

bool checkname(const string& str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}


class Validation {
public:
    static bool IsValidpassword(string pass) {
        return (pass.length() >= 8 && pass.length() <= 20);
    }
    static bool IsValidName(string name) {
        return (name.length() >= 8 && name.length() <= 20 && checkname(name));
    }
    static bool IsValidSalary(double salary) {
        return (salary >= 5000);
    }
};

class Person {
protected:
    int id;
    string name;
    string password;
    static int nextid;

public:
    Person() {
        id = nextid++;
    }

    Person(string name, string password) {
        id = nextid++;
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

    string getpassword() {
        return password;
    }

    string getname() {
        return name;
    }

    int getid() {
        return id;
    }


    virtual void display() = 0;
};

int Person::nextid = 10000;

class Employee : public Person {
private:
    double salary;

public:
    Employee() : Person() {
        salary = 0;
    }

    Employee(int i, string n, string p, double s) {
        id = i;
        name = n;
        password = p;
        salary = s;
    }

    void setsalary(double s) {
        if (Validation::IsValidSalary(s))
            salary = s;
        else
            cout << "salary not accepted less than 5000" << endl;
    }

    double getsalary() {
        return salary;
    }

    void display() {
        cout << "Employee details: " << endl;
        cout << "ID = " << id << endl;
        cout << "Name = " << name << endl;
        cout << "Password = " << password << endl;
        cout << "Salary = " << salary << endl;
    }
    void savetofile(){
        fstream Employeefile;
        Employeefile.open("Employeefile.txt",ios::out);
        if (Employeefile.is_open())
        {

            Employeefile<<"ID = "<<getid()<<endl;
            Employeefile<<"Name = " <<getname()<<endl;
            Employeefile<<"Password = " <<getpassword()<<endl;
            Employeefile<<"Salary ="<<getsalary()<<endl;
            Employeefile<<"=========================="<<endl;
            Employeefile.close();
        }
        else{
            cout<<"erorr with file";
        }

    }
};

class Admin : public Person {
private:
    double salary;

public:
    Admin() : Person() {
        salary = 0.0;
    }
    Admin(double s){
        this->salary=s;
    }
    Admin(int id, string name, string password, double salary) : Person(id, name, password) {
        this->salary = salary;
    }

    void setsalary(double s) {
        if (Validation::IsValidSalary(s))
            salary = s;
        else
            cout << "not valid salary less than 5000";
    }

    double getsalary() {
        return salary;
    }

    void display() {
        cout << "Admin details: " << endl;
        cout << "ID = " << id << endl;
        cout << "Name = " << name << endl;
        cout << "Password = " << password << endl;
        cout << "Salary = " << salary << endl;
    }
    void savetofile(){
        fstream Adminfile;
        Adminfile.open("Adminfile.txt",ios::out);
        if (Adminfile.is_open())
        {

            Adminfile<<"ID = "<<getid()<<endl;
            Adminfile<<"Name = " <<getname()<<endl;
            Adminfile<<"Password = " <<getpassword()<<endl;
            Adminfile<<"Salary ="<<getsalary()<<endl;
            Adminfile<<"=========================="<<endl;
            Adminfile.close();
        }
        else{
            cout<<"erorr with file";
        }

    }
};

class Client : public Person {
private:
    double balance;

public:
    Client() : Person() {
        balance = 0;
    }

    Client(int id, string name, string password,double balance) : Person(id, name, password) {
        this->balance = balance;
        
    }
    

    Client(string name, string password,double balance) : Person(name, password) {
        this->balance = balance;
        
    }
    void setbalance(double b) {
        this->balance = b;
    }

    double getbalance() {
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
   void savetofile(){
    fstream Clientfile;
    Clientfile.open("Clientfile.txt",ios::out);
    if (Clientfile.is_open())
    {

    Clientfile<<"Client ID = "<<getid()<<endl;
    Clientfile<<"Name = " <<getname()<<endl;
    Clientfile<<"Password = "<<getpassword()<<endl;
    Clientfile<<"Balance = "<<getbalance()<<endl;
    Clientfile<<"=========================="<<endl;
    }
    else{
        cout<<"erorr with file";
    }
    Clientfile.close();
    }

    
};

int main() {
    cout << "Welcome to the bank system" << endl;

    Admin admin(30000);
    admin.display();
    Employee employee;
    cout<<employee.getid();
    Client Client("ahmed","Porshe911",6500);
    Client.savetofile();
    admin.savetofile();
    employee.setsalary(8000);
    employee.savetofile();
}
