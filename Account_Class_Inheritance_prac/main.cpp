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
    friend ostream &operator<<(ostream& os,const Account & account);
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
    bool deposit(double ammount);
    bool withdraw(double ammount);
    double get_balance() const;
};

Account::Account(string name, double balance)
:name{name}, balance{balance} {
    
}

bool Account::deposit(double amount) {
    if (amount < 0) {
        return false;
    }else{
        balance += amount;
        return true;
    }
}

bool Account::withdraw(double amount){
    if (balance-amount >= 0) {
        balance -= amount;
        return true;
    }else{
        return false;
    }
}

double Account::get_balance() const {
    return balance;
}

ostream &operator<<(ostream& os,const Account& account) {
    os << "[Account: "<< account.name << ":" << account.balance << "]";
    return os;
}
/* In case if you don't know operator overloading, what this operator<< function is doing, it would cout any object of Account class directly withour using any display function */

//MARK: - Saving Account

class SavingAccount: public Account {
    friend ostream &operator<<(ostream& os,const SavingAccount & account);
private:
//    static constexpr const char * defName = "Unnamed Saving account";
//    static constexpr const double defBalance = 0.0;
//    static constexpr const double defIntRate = 0.0;
// These upper three lines are commented to ellaborate the upper explanation that was in Saving account.
protected:
    double intRate;
public:
//    SavingAccount(string name = defName, double balance = defBalance, double intRate = defIntRate);
    SavingAccount(string name = "Unnamed Saving account", double balance = 0.0, double intRate = 0.0);
    bool deposit(double amount);
    //Inherits the Account::withdraw function
};

SavingAccount::SavingAccount(std::string name, double balance, double intRate)
: Account {name, balance}, intRate{intRate} {
}

// Deposit:
//      Amount supplied to deposit will be incremented by (amount * intRate/100)
//      and then the updated amount will be deposited
//
bool SavingAccount::deposit(double amount) {
    amount += amount * (intRate/100);
    return Account::deposit(amount);
}

std::ostream &operator<<(std::ostream &os, const SavingAccount &account) {
    os << "[SavingAccount: " << account.name << ": " << account.balance << ", " << account.intRate << "%]";
    return os;
}

class CheckingAccount: public Account {

public:
    CheckingAccount(string name = "UnnameCheckingAccount", double balance = 0.0);
    bool withdraw(double amount);
    //Inherits the Account::deposit
};

CheckingAccount::CheckingAccount(string name, double balance)
:Account{name,balance} {
    
}

bool CheckingAccount::withdraw(double amount){
    if (balance-amount >= 0) {
        balance -= amount - 1.5;
        return true;
    }else{
        return false;
    }
}

class TrustAccount: public SavingAccount {

public:
    TrustAccount(string name = "UnnamedTrustAccount", double balance = 0.0, double intRate = 0.0);
    bool deposit(double amount);
    bool withdraw(double amount);
};

TrustAccount::TrustAccount(string name, double balance, double intRate)
:SavingAccount{name,balance,intRate} {
    
}

bool TrustAccount::deposit(double amount){
    if(amount > 0){
        if (amount >= 5000)
            balance += amount + 50;
        else
            balance += amount;
        return true;
    }else{
        return false;
    }
}

bool TrustAccount::withdraw(double amount){
    static int times = 1;
    double percentageOfBalance = balance * 0.2;
    
    if (balance-amount >= 0 && times <= 3 && amount < percentageOfBalance) {
        balance -= amount;
        return true;
    }else{
        return false;
    }
}

int main(){
    
    return 0;
}
