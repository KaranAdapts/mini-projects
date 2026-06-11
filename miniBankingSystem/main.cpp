#include <iostream> 

// gonna add a confirmation option later on to confirm whether the user wants to proceed with the entered amount or go back. would be cruel not to...

int balance{1000}; // initially are required to have a 1000 rupees 

void checkBalance(){
    std::cout << "\nYour Current Balance is " << balance << '\n';
}

int takeInput(){
    std::cout << "What would you like to do?\nPress 1 to Depost\nPress 2 to Withdraw\nPress 3 to Check Balance\n";
    int userInput{};
    std::cin >> userInput;
    std::cout << "You Entered Option " << userInput << '\n';
    return userInput;
}

double enterAmount(int userInput){
    if (userInput == 3 || userInput > 3){
        return 0;
    } else {
    double amount{};
    std::cout << "\nEnter Your amount to proceed: ";
    std::cin >> amount; 
    std::cout << "Proceeding with Amount: ₹" <<  amount << '\n';
    return amount;
    }
}

void deposit(double amount, double currentBalance){
    balance = amount + currentBalance;
    checkBalance();
}

void withdraw(double amount, double currentBalance){
    if ((currentBalance - amount) >= 0){
        balance = currentBalance - amount; 
    } else {
        std::cout << "Insufficient Funds, Check Bal\n";
    }
    checkBalance();
}

double proceedOperation(int userInput, double balance, double amount){
    
    if (userInput == 1){
        deposit(amount, balance);
        return balance;
    }
    else if (userInput == 2){
        withdraw(amount, balance);
        return balance; 
    }
    else if (userInput == 3){
        checkBalance();
        return balance;
    }
    else {
        std::cout << "\nInvalid Option! Choose again!\n\n";
        int reUserInput{takeInput()};
        proceedOperation(reUserInput, balance, enterAmount(reUserInput));   
        return reUserInput;
    }
}

int main(){

    std::cout << "\nWelcome to Claude Banking!\n\n";
    int takeUserInput{takeInput()};
    proceedOperation(takeUserInput, balance, enterAmount(takeUserInput));
 
    return 0;
}