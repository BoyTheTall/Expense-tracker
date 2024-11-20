#include "Transaction.hpp"
#include "sqlite3.h"
#include <vector>
using namespace std;

class Transaction_Services{
private:
    const char* directory = "transactions.db";
    sqlite3* db;
    int connection_established;//this is for checking if the connection was established
    void connect();
    vector<Transaction> traverse_result_set(sqlite3_stmt* stmt);
public:
    bool is_connected;
    Transaction_Services();
    void add_transaction();
    vector<Transaction> getAllTransactions();
    vector<Transaction> getTransaction(int transaction_id);
    vector<Transaction> getTransactions(int t_id = NULL, string date = NULL, string category = NULL, double amount = NULL, bool is_expense = NULL);
    ~Transaction_Services();
};
