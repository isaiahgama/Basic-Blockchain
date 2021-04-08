// Isaiah Gama, S21, 4/7/21

#ifndef TRANSACTIONS_H
#define TRANSACTIONS_H

#include <iostream>
#include <openssl/sha.h>
using namespace std;

class Transaction{
    public:
    Transaction(int amount, string sender, string receiver);
    Transaction* getPrev(){
        return prev;
    }
    void setPrev(Transaction* prev){
        this->prev = prev;
    }
    string getHash(){
        return hash;
    }
    int getAmount(){
        return amount;
    }
    string getSender(){
        return sender;
    }
    string getReceiver(){
        return receiver;
    }
    string getNonce(){
        return nonce;
    }
    void findNonce();
    string getString();
    string getNonceString();
    void setHash(string h);


    private:
        Transaction *prev;
        int amount;
        string sender;
        string receiver;
        string nonce;
        string hash;
};

class transactionChain{
    public:
    transactionChain();
    void addTransaction(int amount, string sender, string receiver);
    void getBalance(string name);
    void printChain();
    Transaction* getHead(){
        return head;
    }
    void printChainHelper(Transaction* head);



    private:
        Transaction* head; //the most recent transaction


};

#endif