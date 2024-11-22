
#include <iostream>
#include <string>
#include "Transaction.hpp"
#include "sqlite3.h"
#include "transaction_services.hpp"
#include <vector>
using namespace std;

//practice the database connections thing later
int main(){
    Transaction_Services ts = Transaction_Services();
    int t_id = 5648554;
    vector<Transaction> t_list =  ts.getAllExpenses();
    for(int i = 0; i < t_list.size(); i++){
        cout << t_list[i].toString() << endl << endl;
    }
    return 0;
}
