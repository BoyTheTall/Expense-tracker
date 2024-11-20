
#include <iostream>
#include <string>
#include "Transaction.hpp"
#include "sqlite3.h"
#include "transaction_services.hpp"
#include <vector>
using namespace std;

//practice the database connections thing later
int main(){
    Transaction t;
    vector<Transaction> t_lit;
    Transaction_Services ts = Transaction_Services();
    int t_id = NULL;
    string date = NULL;
    double amount = NULL;
    bool is_expense = NULL;
    string category = "groceries";
    t_lit = ts.getTransactions(t_id, date, category, amount, is_expense);
    cout << t_lit[0].getAmount() << endl;
    cout << NULL;
    return 0;
}
