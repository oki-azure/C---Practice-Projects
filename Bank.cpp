#include <cstdio>

struct Logger {
    virtual ~Logger() = default; 

    virtual void log_transfer(long from, long to, float amount) = 0; 
};

struct ConsoleLogger : Logger {
    ConsoleLogger(const char* logString) : logString{logString} {}

    void log_transfer(long from, long to, float amount) override { printf("[cons] %s's transaction: %ld -> %ld: $%.2f", logString, from, to, amount); }

    private:
        const char* logString; 
};

struct AccountDatabase {
    virtual void retrieveAmount(long id) const = 0; 

    virtual void setAmount(long id, float amount) = 0; 
};

struct InMemoryAccountDatabase : AccountDatabase {
    InMemoryAccountDatabase() : Balance{} {}

    void retrieveAmount(long id) const override { printf("\nAmount at id[%ld] is $%.2f", id, Balance[id]); }

    void setAmount(long id, float amount) override {
        Balance[id] = amount; 

        printf("\n$%.2f has been set in account id [%ld]", amount, id); 
    }

    private:
        double Balance[100]{}; 
};

struct Bank {
    Bank(Logger* logger, AccountDatabase& accountDatabase) : logger{logger}, accountDatabase{accountDatabase} {}

    void set_logger(Logger* new_logger) { logger = new_logger; }

    void make_transfer(long from, long to, float amount) { if (logger) logger->log_transfer(from, to, amount); }

    void setBalance(long id, float amount) { accountDatabase.setAmount(id, amount); }

    void getBalance(long id) { accountDatabase.retrieveAmount(id); }

    private:
        Logger* logger; 
        AccountDatabase& accountDatabase; 
};

int main() {
    ConsoleLogger logger{"Azure"};

    InMemoryAccountDatabase inMemory; 
 
    Bank bank{&logger, inMemory};  

    bank.make_transfer(1800, 1801, 10000); 

    bank.setBalance(1,1000); 

    bank.getBalance(1); 
}