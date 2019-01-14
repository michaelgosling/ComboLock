#include <iostream>
#include <algorithm>
#include "LinkedList.h"

std::string StringToUpper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    return str;
}

int main() {
    LinkedList list;
    int currPosition = 0;
    std::string userInput;

    // debugging
//    srand(time(nullptr));
//    for (int i = 0; i < 7; i++){
//        std::cout << "Init "<< i << ": " << ((list.Get(i)->direction == Left) ? "L" : "R") << list.Get(i)->data << std::endl;
//        int newNum = rand() % 50;
//        list.Set(i, newNum);
//        std::cout << "After "<< i << ": " << ((list.Get(i)->direction == Left) ? "L" : "R") << list.Get(i)->data << std::endl;
//    }


    while (userInput != "Q" || userInput != "E") {
        // print list
        std::cout << list << std::endl;
        // highlight current working position
        for (int i = 0; i < NUM_OF_TURNS; i++) {
            if (i == currPosition)
                std::cout << " ^^";
            else
                std::cout << "   ";
        }
        std::cout << std::endl << "(Q)uit without save. (E)xit with saving. (G)oto position. " << std::endl
                  << " (S)ubstitute. (D)elete. (R)eset";
        std::cout << std::endl << "Choice: ";
        std::cin >> userInput;
        userInput = StringToUpper(userInput);
        auto firstLetter = userInput.c_str()[0];
        if (firstLetter == 'Q') {
            std::cout << std::endl << "Quitting without saving...";
        } else if (firstLetter == 'E') {
            // TODO: Save and exit code
        } else if (firstLetter == 'G') {
            // TODO: Goto Position code
        } else if (firstLetter == 'S') {
            // TODO: Substitution code
        } else if (firstLetter == 'D') {
            // TODO: Deletion code
        } else if (firstLetter == 'R') {
            // TODO: Reset code
        } else {
            std::cout << std::endl << "Invalid command!" << std::endl;
        }


    }



    return 0;
}