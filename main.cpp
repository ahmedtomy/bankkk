#include <iostream>
#include <string>
#include <cctype>
using namespace std;
bool checkname(const string& str) {
    for (int i = 0; i < (int)str.length(); i++) {
        if (!isalpha(str[i])) {
            return false;
        }
    }
    return true;
}
class Validation{
public:
    static bool IsValidpassword(string pass){
            return (pass.length()>=8 && pass.length()<=20);
        }
    static bool IsValidName(string name){
        return (name.length()>=8 && name.length()<=20 && checkname(name));
    }
    };



class Person{
protected:
     int id;string name;string password;
public:
    Person() {
        id=10000;
        id++;

    }
    Person(string name,string password) {
        this->name=name;
        this->password=password;
    }
    void setname(string n){
        if (Validation::IsValidName(n))
        name=n;
        else
            cerr<<"name not valid";
    }
    void setpassword(string p) {
        if (Validation::IsValidpassword(p))
            password = p;
        else
            cerr<<"password not valid";
    }
    string getpassword(){
        return password;
    }
    string getname(){
        return name;
    }
    int getid(){
        return id;
    }
};



class Client : public Person{
private:
    double balance;
public:
    Client(){
    this->balance = 0;

    }
    Client(double balance,int id,string name,string password){
       this-> balance = balance;
       this-> id = id;
       this-> name = name;
       this-> password = password;



    }
 void setbalance(int b){
    this->balance = balance;
}
int getbalance(){
    return balance;
}
double deposit(double amount){
    balance += amount;
    return balance;
}
double withdraw(double amount){
    if(amount<=balance){
        balance -= amount;
    }
    else{
        cout<<"not found"<<endl;
    }
    return balance;

}
void transferto(Client m,double amount){
 if(amount<=balance){
        balance -= amount;
        m.deposit(amount);
}
 else{
        cout<<"not found"<<endl;
    }

}

double checkbalance(){
    return balance;
}

void display(){
    cout<<"name     = "<<name;
    cout<<"id       = "<<id;
    cout<<"password = "<<password;
    cout<<"balance  = "<<balance;
}
};
class Employee :public Person  {
private :
    //data 
    double balance;
public:
    //con
    Employee() {
        balance = 0;
    }
    Employee(int i, string n, string p, double b) {
        id = i;
        name = n;
        password = p;
        balance = b;
    }
    //sett
    void setbalance(double b) {
        balance = b;
    }
    //get 
    double gitbalance() {
        return balance;
    }
    //methods 
    void disblay() {
        cout << "id =" << id << endl;
        cout << "name =" << name << endl; 
        cout << "password =" << name << endl;
        cout << "balance = " << balance << endl;
    }


};
int main(){
cout<<"welcome to bank system";
cout << "salah essa ";
}
