for(int i=0; i<a->withdrawable_accounts.size(); i++){
        a->withdrawable_accounts[i]->deposit(1000);
        a->withdrawable_accounts[i]->withdraw(500);
    }