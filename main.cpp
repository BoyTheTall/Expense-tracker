
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
    string t_id = "2714611467";
    vector<Transaction> t_list =  ts.getTransactions(ts.num_default_value, ts.str_default_value, ts.str_default_value, ts.num_default_value);
    for(int i = 0; i < t_list.size(); i++){
        cout << t_list[i].toString() << endl << endl;
    }
    return 0;
}
