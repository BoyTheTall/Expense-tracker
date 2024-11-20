
#include <iostream>
#include <string>
#include "Transaction.hpp"
#include "sqlite3.h"
#include "transaction_services.hpp"
#include <vector>
using namespace std;

//practice the database connections thing later
int main(){
    string date = "20/03/2024";
    string category = "Groceries";
    Transaction t;
    vector<Transaction> t_lit;
    Transaction_Services ts = Transaction_Services();
    t_lit = ts.getTransaction(5648554);
    cout << t_lit[0].getAmount() << endl;
    cout << NULL;
    return 0;
}
