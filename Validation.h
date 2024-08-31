//
// Created by Admin on 8/22/2024.
//

#ifndef BANK_MTB_VALIDATION_H
#define BANK_MTB_VALIDATION_H

#include <string>
#include <cctype>
using namespace std;
bool checkname(const string& str) {
    for (int i = 0; i < (int) str.length(); i++) {
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
    static bool IsValidBalance(double balance){
        return (balance >=1500);
    }
};


#endif //BANK_MTB_VALIDATION_H
