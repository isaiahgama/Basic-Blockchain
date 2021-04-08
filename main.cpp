// Isaiah Gama, S21, 4/7/21
#include <iostream>
#include  "Transactions.h"
using namespace std;

void printOptions(){ // Prints all of the options, does actually take any user input.
    cout <<"Welcome to the transaction-chain application . . ." << endl;
    cout << "1) Add a transaction to the chain."<<endl;
    cout << "2) Find balance of a person" <<endl;
    cout << "3) Print the chain" <<endl;
    cout << "4) Exit" <<endl;
    cout << "Which operation would you like to perform? (1,2,3,4): "<<endl;
}

int userSelection(){ // does not print anything, only records the user input.
    int userSelection = 0;
    cin >> userSelection;
    return userSelection;
}

bool isInt(string input) { // used to make sure that the input for transactions is an integer
   for (size_t i = 0; i < input.size(); i++){
        if (isdigit(input[i]) == false){
            return false;
        }
    }
      return true;
}


int main(){
    // print out the prompt, take the input, and create the transaction chain object.
    printOptions();
    int userInput = userSelection();
    transactionChain tchain;

    while(userInput!=4){
        if(userInput == 1){ // if input is 1, then we create a transaction
            cout<<"Add transaction"<<endl;
            cout<<"Integer amount of money:"<<endl;
            string moneyInt;
            cin>>moneyInt;
            int money;
            if(!isInt(moneyInt)){ // input is not an integer, try again
                cout<<"Not an integer! Please input an integer."<<endl;
                userInput=1;
                continue;
            }else{
                money = stoi(moneyInt); // convert string input to an integer, prompt for sender name and receiver name
                cout<<"Sender Name"<<endl;
                string sender;
                cin >> sender;
                cout<<"Receiver Name"<<endl;
                string receiver;
                cin >> receiver;

                tchain.addTransaction(money,sender,receiver); // all inputs have been OK, add the transaction
            }
        }
        else if(userInput == 2){ // if input is 2, then we find the balance for someone
            cout<<"Person Name:"<<endl; // prompt the name
            string name;
            cin >> name;
            tchain.getBalance(name); // find the balance of the person
        }
        else if(userInput == 3){ // if input is 3, no further inputs, just print the entire chain
            tchain.printChain();
        }
        else if(userInput == 4){ // if input is 4, we break from the while loop and go to the thank you message
            break;
        }
        else{ // if input is not in [1,4], we prompt for a new input
            cout << "Wrong input! Try again!"<<endl;
        }
        printOptions(); // after the action has been completed, we print the main prompt and get another input
        userInput = userSelection();
    }

    cout<<"Thank you for using the transaction-chain application!"<<endl;


    return 0;
}