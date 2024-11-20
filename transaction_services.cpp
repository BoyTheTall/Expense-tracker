#include "transaction_services.hpp"
#include <iostream>
#include "sqlite3.h"
using namespace std;


Transaction_Services::Transaction_Services(){
    connect();
}
//private function for initialising the connection. Although there'll be one constructor I dont want to copy and paste code in case i add another
void Transaction_Services::connect() {

    this->connection_established = sqlite3_open(this->directory, &this->db);
    if (connection_established != SQLITE_OK) {
        cerr << "Can't open the database: " << sqlite3_errmsg(db) << endl;
        this->is_connected = false;
    }
    else {
        cout << "Database opened successfully" << endl;
        this->is_connected = true;
    }

    }

vector<Transaction> Transaction_Services::getTransaction(int transaction_id){
    sqlite3_stmt* stmt;
    vector<Transaction> t_list;
    string sql = "SELECT * FROM tblTransactions WHERE transaction_id = " + to_string(transaction_id);
    int exit_code = sqlite3_prepare_v2(this->db, sql.c_str(), -1, &stmt, nullptr);
    if(exit_code != SQLITE_OK){
        cerr << "Failed to prepare statement " << sqlite3_errmsg(this->db) << endl;
    }else{
        t_list = this->traverse_result_set(stmt);
    }

    return t_list;
    }

    //only call this function if the sql statement actually executed
vector<Transaction> Transaction_Services::traverse_result_set(sqlite3_stmt* stmt){
    vector<Transaction> t_list;
    while(sqlite3_step(stmt) == SQLITE_ROW){
            int t_id = sqlite3_column_int(stmt, 0);
            double amount = sqlite3_column_double(stmt, 1);
            string category = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 2));
            bool transaction_type = static_cast<bool>(sqlite3_column_int(stmt, 3));
            string t_date = reinterpret_cast<const char*>(sqlite3_column_text(stmt, 4));
            Transaction t = Transaction(t_id, t_date, category, amount, transaction_type);
            t_list.push_back(t);
        }
    return t_list;
}

vector<Transaction> Transaction_Services::getAllTransactions(){
    vector<Transaction> tr_arr;
    tr_arr.push_back(Transaction());
    tr_arr.push_back(Transaction());

    return tr_arr;
}
Transaction_Services::~Transaction_Services(){
    if(this->is_connected == true)
        sqlite3_close(this->db);
}
