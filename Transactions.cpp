#include "Transactions.h"
#include <iostream>
#include <iomanip>
#include <sstream>
#include <openssl/sha.h>
using namespace std;

// this sha256 function was taken from https://stackoverflow.com/questions/2262386/generate-sha256-with-openssl-and-c/10632725
string sha256(const string str)
{
    unsigned char hash[SHA256_DIGEST_LENGTH];
    SHA256_CTX sha256;
    SHA256_Init(&sha256);
    SHA256_Update(&sha256, str.c_str(), str.size());
    SHA256_Final(hash, &sha256);
    stringstream ss;
    for(int i = 0; i < SHA256_DIGEST_LENGTH; i++)
    {
        ss << hex << setw(2) << setfill('0') << (int)hash[i];
    }
    return ss.str();
}


Transaction::Transaction(int amount, string sender, string receiver){ // parameterized constructor for a Transaction
    this->amount = amount;
    this->sender = sender;
    this->receiver = receiver;
    this->nonce = "";
    this->hash="";
}

void Transaction::setHash(string h){ // basic setter function for hash
    this->hash = h;
}

transactionChain::transactionChain(){ // default constructor for the transactionChain
    head = NULL;
}

void Transaction::findNonce(){ // generates a random nonce, sets the blocks nonce to this value.
    char c = char(rand()%26+97);
    char d = char(rand()%26+97);
    string str1(1,c);
    string str2(1,d);
    string str = str1 + str2;
    this->nonce = str;
}

string Transaction::getString(){ // converts the blocks contents into one string in order to feed to sha256 hash function
    return to_string(getAmount()) + sender + receiver + hash + nonce;
}

void transactionChain::addTransaction(int amount, string sender, string receiver){

    // create the transaction
    Transaction *tmp = new Transaction(amount,sender,receiver);
    if(!head){//if this is the first transaction
        tmp->setHash("NULL");
        tmp->setPrev(NULL);
    }else{ // if this is not the first transaction
        tmp->setPrev(head); 
        tmp->setHash(sha256(tmp->getPrev()->getString()));
    }

    //creates the hash
    string temp;
    bool foundNonce = false;
    while(!foundNonce){ // finds a nonce that satisfies the last char being 0
        tmp->findNonce();
        temp = sha256(tmp->getString());
        if(temp[temp.size()-1]=='0'){
            foundNonce=true;
        }
    }

    head = tmp; // sets the newly created transaction as the new head

    cout<<"$"+to_string(amount)+" was sent to " + receiver + " by " + sender<<endl;
}

void transactionChain::getBalance(string name){
    Transaction* tmp = head;
    int balance = 50;
    while(tmp){ // iterates in order through the linked list
        if(tmp->getSender() == name){ // if NAME is the sender, subtract from the balance
            balance -= tmp->getAmount();
        }
        else if (tmp->getReceiver() == name){ // if NAME is the receiver, add to the balance
            balance += tmp->getAmount();
        }
        
        tmp = tmp->getPrev();

    }
    cout<<to_string(balance)<<endl;
}

void transactionChain::printChainHelper(Transaction* head){ // recursive helper function for printChain
    if(!head){
        return;
    }
    printChainHelper(head->getPrev());
    cout<<"Amount: " + to_string(head->getAmount())<<endl;
    cout<<"Sender: " + head->getSender()<<endl;
    cout<<"Receiver: " + head->getReceiver()<<endl;
    cout<<"Nonce: " + head->getNonce()<<endl;
    cout<<"Hash: " + head->getHash()<<endl;
}

void transactionChain::printChain(){ // uses helper function to print the entire transaction chain recursively

    printChainHelper(getHead());

}