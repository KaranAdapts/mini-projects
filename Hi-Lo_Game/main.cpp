#include <iostream>
#include <limits>
#include "Random.h"

int min; int max; int maxGuesses;

void resetInputState(){
    if (std::cin.eof()){
        std::exit(0);
    }
    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

char askOptionInput(){
    char c{};
    std::cin >> c;
    resetInputState();
    return c;
}

void playConfirm();

void defaultHiLo(){

    std::cout << "\nLet's play a game. I'm thinking of a number between 1 and 100.\nYou have 7 tries to guess what it is.\n\n";

    int randomNum{ Random::get(1, 100) };

    for (int tries{1}; tries <= 7; ++tries){
        int guessNum{};
        std::cout << "Guess #" << tries << ": ";
        std::cin >> guessNum; 
        resetInputState();
        if (guessNum > randomNum){
            std::cout << "Your guess is too high.\n";
        } else if (guessNum < randomNum) {
            std::cout << "Your guess is too low.\n";
        } else if (guessNum == randomNum){
            std::cout << "Correct! You win!\n";
            break;
        }  
        
        if (tries == 7){
            std::cout << "Sorry, you lose. The correct number was " << randomNum << ".\n";
        }

    }

    std::cout << "Would you like to play again (y/n)? ";
    playConfirm();
}

void customHiLo(){

    std::cout << "Enter Minimum Range Limit: ";
    int min{};
    std::cin >> min; 
    resetInputState();

    std::cout << "Enter Maximum Range Limit: ";
    int max{};
    std::cin >> max;
    resetInputState();
    while (min > max){
        std::cout << "Invalid, Maximum cannot be lesser than Minimum!\nRe-Enter Max Range Limit: ";
        std::cin >> max; 
        resetInputState();
    }

    std::cout << "Enter the amount of guesses you want: ";
    int maxGuesses{};
    std::cin >> maxGuesses;
    resetInputState();
    while (maxGuesses <= 0){
        std::cout << "Invalid, Enter Positive Number of Guesses: ";
        std::cin >> maxGuesses; 
        resetInputState();
    }

    int randomNum{ Random::get(min, max) };

    for (int tries{1}; tries <= maxGuesses; ++tries){
        int guessNum{};
        std::cout << "Guess #" << tries << ": ";
        std::cin >> guessNum; 
        resetInputState();
        if (guessNum > randomNum){
            std::cout << "Your guess is too high.\n";
        } else if (guessNum < randomNum) {
            std::cout << "Your guess is too low.\n";
        } else if (guessNum == randomNum) {
            std::cout << "Correct! You win!\n";
            break;
        }  
        
        if (tries == 7){
            std::cout << "Sorry, you lose. The correct number was " << randomNum << ".\n";
        }

    }

    std::cout << "Would you like to play again (y/n)? ";
    playConfirm();
}

void playConfirm(){

    char replayInput{askOptionInput()};
    resetInputState();

    while (replayInput != 'y' || replayInput != 'Y' || replayInput != 'n' || replayInput != 'N' || replayInput != 'c' || replayInput != 'C' || replayInput != 'd' || replayInput != 'D' || replayInput != 'e' || replayInput != 'E') {
        std::cout << "Invalid Input! Enter y/n: ";
        replayInput = askOptionInput();
        resetInputState();
    }

    if (replayInput == 'y' || replayInput == 'Y'){
        std::cout << "\nReplaying...\n\nPlay with Custom settings (Press C)\nPlay with Default Settings (Press D)\nExit (Press E)\nChoose an Option: ";
    }

    replayInput = askOptionInput();
    resetInputState();

     switch (replayInput){
        
        case 'c': 
        case 'C': 
        customHiLo();
        break;

        case 'd':
        case 'D': 
        defaultHiLo();
        break;

        case 'e': 
        case 'E': 
        std::exit(0);
    }
}


int main(){

    std::cout << "\nLet's play a game of Hi-Lo.\nPlay with Custom settings (Press C)\nPlay with Default Settings (Press D)\nExit (Press E)\n\nChoose an Option: ";

    playConfirm();
     
    return 0;
}