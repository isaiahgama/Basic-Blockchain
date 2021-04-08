#include <iostream>
using namespace std;

void printOptions(){
    cout <<"Welcome to the transaction-chain application . . ." << endl;
    cout << "1) Add a transaction to the chain."<<endl;
    cout << "2) Find balance of a person" <<endl;
    cout << "3) Print the chain" <<endl;
    cout << "4) Exit" <<endl;
    cout << "Which operation would you like to perform? (1,2,3,4): "<<endl;
}

int userSelection(){
    int userSelection = 0;
    cin >> userSelection;
    return userSelection;
}


int main(){

    printOptions();
    int userInput = userSelection();

    while(userInput!=4){
        if(userInput == 1){
            cout<<"Add transaction stub"<<endl;
        }
        else if(userInput == 2){
            cout<<"Find a balance stub"<<endl;
        }
        else if(userInput == 3){
            cout<<"print the chain stub"<<endl;
        }
        else if(userInput == 4){
            break;
        }
        else{
            cout << "Wrong input! Try again!"<<endl;
        }
        printOptions();
        userInput = userSelection();
    }

    cout<<"Thank you for using the transaction-chain application!"<<endl;


    return 0;
}