#include<iostream>
#include<vector>
using namespace std;

class Non_Withdrawable_Account{
public:
    // Non_Withdrawable_Account(){}
    virtual void deposit(double amount)=0;
};

class withdrawable_Account: public Non_Withdrawable_Account{
public:
    // withdrawable_Account(){}
    virtual void withdraw(double amount)=0;
};
class FD_Account: public Non_Withdrawable_Account{
public:
    int amount;
    FD_Account(){
        this->amount=0;
    }
    void deposit(double amount){
        this->amount+=amount;
        cout<<"Amount after deposit: "<<this->amount<<endl;
    }
};
class Saving_Account: public withdrawable_Account{
public:
    int amount;
    Saving_Account(){
        this->amount=0;
    }
    void deposit(double amount){
        this->amount+=amount;
        cout<<"Amount after deposit: "<<this->amount<<endl;
    }
    void withdraw(double amount){
        if(this->amount<amount){
            cout<<"Insufficient balance"<<endl;
            return;
        }
        this->amount-=amount;
        cout<<"Amount after withdraw: "<<this->amount<<endl;
    }
};
class Current_Account: public withdrawable_Account{
public:
    int amount;
    Current_Account(){
        this->amount=0;
    }
    void deposit(double amount){
        this->amount+=amount;
        cout<<"Amount after deposit: "<<this->amount<<endl;
    }
    void withdraw(double amount){
        if(this->amount<amount){
            cout<<"Insufficient balance"<<endl;
            return;
        }
        this->amount-=amount;
        cout<<"Amount after withdraw: "<<this->amount<<endl;
    }
};

class Client{
public:
    vector<Non_Withdrawable_Account*> non_withdrawable_accounts;
    vector<withdrawable_Account*> withdrawable_accounts;

    Client(vector<Non_Withdrawable_Account*> non_withdrawable_accounts,vector<withdrawable_Account*> withdrawable_accounts){
        this->non_withdrawable_accounts=non_withdrawable_accounts;
        this->withdrawable_accounts=withdrawable_accounts;
    }
};

int main(){
    vector<Non_Withdrawable_Account*> non_withdrawable_accounts;
    vector<withdrawable_Account*> withdrawable_accounts;
    non_withdrawable_accounts.push_back(new FD_Account());
    non_withdrawable_accounts.push_back(new FD_Account());
    withdrawable_accounts.push_back(new Saving_Account());
    withdrawable_accounts.push_back(new Saving_Account());
    withdrawable_accounts.push_back(new Current_Account());

    Client *a= new Client(non_withdrawable_accounts, withdrawable_accounts);
    
    // for(int i=0; i<a->non_withdrawable_accounts.size(); i++){
    //     a->non_withdrawable_accounts[i]->deposit(1000);
    // }
    for(int i=0; i<a->withdrawable_accounts.size(); i++){
        a->withdrawable_accounts[i]->deposit(1000);
        a->withdrawable_accounts[i]->withdraw(500);
    }
    for(int i=0; i<a->withdrawable_accounts.size(); i++){
        a->withdrawable_accounts[i]->withdraw(0);
    }
}