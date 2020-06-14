# Account_Class_Inheritance_prac
You are provided with a simple Account class hierarchy that contains
**Account - Base class  **
**Savings Account - Derived class  **

An Account has a name and a balance.  
A Savings Account is an Account and adds an interest rate.  

Checking account - Derived class  
Trust account - Derived class  

A Checking account has a name and a balance and has a fee of $1.50 per withdrawal transaction.  
Every withdrawal transaction will be assessed this flat fee.  

A Trust account has a name, a balance, and an interest rate  
The Trust account deposit works just like a savings account deposit.  
However, any deposits of $5000.00 or more will receive a $50.00 bonus deposited to the account.  
    
The Trust account withdrawal should only allow 3 withdrawals per year and each of these must be less than 20% of the account balance.  
You don't have to keep track of calendar time for this application, just make sure the 4th withdrawal fails :)  
