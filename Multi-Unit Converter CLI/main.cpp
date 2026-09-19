#include <iostream> 
#include <limits> 

void clearInputState(){
    if (std::cin.eof()){
        std::exit(0);
    }

    std::cin.clear();
    std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
}

int mainMenu(){

    std::cout << "Which type of conversion do you want?\n1.] Temperature\n2.] Distance\n3.] Weight\n4.] Exit\n\n";
    int catInput{};
    std::cin >> catInput;
    clearInputState();
    
    return catInput;
}

int main(){
    
    bool running{true}; 
    while (running){

    switch(mainMenu()){

        case 1: 
        std::cout << "Choose your unit conversion: \n1.] °F to °C\n"; 
        running = false; 
        break;

        case 2: 
        std::cout << "Choose your unit conversion: \n1.] kms to Miles\n";
        running = false; 
        break;

        case 3: 
        std::cout << "Choose your unit conversion: \n1.] kgs to lbs\n"; 
        running = false;
        break;

        case 4: 
        std::cout << "Exiting the program... \n";
        running = false;  
        break;

        default:
        std::cout << "Invalid Input! Enter a valid input: ";
        break; 
        }
    }

    return 0; 
}