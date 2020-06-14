//
//  main.cpp
//  Account_Class_Inheritance_prac
//
//  Created by Afaq Ahmed on 14/06/2020.
//  Copyright © 2020 Afaq Ahmed. All rights reserved.
//

#include <iostream>
using namespace std;
class Account {
    friend ostream &operator<<(ostream& os,Account & account);
private:
    static constexpr const char * def_name = "Unnamed Account";
    static constexpr double def_balance = 0.0;
    /* you can comment line 14 & 15 if you are using the constructor that I commented.
     Actually both upper lines are constants, and the both constructor that are defined below do the
     same work, if nothing is passed to the constructors,these default constants or the default
     values given to second commented constructor will use.
     */
protected:
    string name;
    double balance;
public:
    Account(string name = def_name, double balance = def_balance);
//    Account(string name = "Unnamed Account", double balance = 0.0);
    bool deposite(double ammount);
    bool withdraw(double ammount);
    
};




int main(){
    
    return 0;
}
