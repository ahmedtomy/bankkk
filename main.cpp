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
int main(){
cout<<"welcome to bank system";
}


