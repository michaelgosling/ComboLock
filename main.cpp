#include <iostream>
#include <algorithm>
#include <cstring>
#include "LinkedList.h"

std::string StringToUpper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    return str;
}

int main() {
    LinkedList list;
    int currPosition = 0;
    bool programFinished = false;

    // debugging
//    srand(time(nullptr));
//    for (int i = 0; i < 7; i++){
//        std::cout << "Init "<< i << ": " << ((list.Get(i)->direction == Left) ? "L" : "R") << list.Get(i)->data << std::endl;
//        int newNum = rand() % 50;
//        list.Set(i, newNum);
//        std::cout << "After "<< i << ": " << ((list.Get(i)->direction == Left) ? "L" : "R") << list.Get(i)->data << std::endl;
//    }

    while (!programFinished) {
        // print list
        std::cout << list << std::endl;
        // highlight current working position
        for (int i = 0; i < NUM_OF_TURNS; i++) {
            if (i == currPosition)
                std::cout << " ^^ ";
            else
                std::cout << "    ";
        }
        std::cout << std::endl << "(Q)uit without save. (E)xit with saving. (G)oto position. " << std::endl
                  << " (S)ubstitute. (D)elete. (R)eset";
        std::cout << std::endl << "Choice: ";
        char *userInput;
        std::cin.getline(userInput, 256);
        auto firstLetter = StringToUpper(userInput).c_str()[0];
        if (firstLetter == 'Q') {
            std::cout << std::endl << "Quitting without saving...";
            programFinished = true;
        } else if (firstLetter == 'E') {
            // TODO: Save and exit code
        } else if (firstLetter == 'D')
            list.Set(currPosition, 0);
        else if (firstLetter == 'R')
            for (int i = 0; i < NUM_OF_TURNS; i++)
                list.Set(i, 0);
        else {
            // copy user input to a char array, split into tokens via space character
            char input[strlen(userInput) + 1];
            for (int i = 0; i < strlen(userInput); i++)
                input[i] = userInput[i];
            char *token;
            strtok(input, " "); // toss first token
            token = strtok(nullptr, " ");
            int value = 0;
            if (token != nullptr)
                value = atoi(token);

            // use second token differently depending on first token
            if (firstLetter == 'G')
                currPosition = value - 1;
            else if (firstLetter == 'S')
                list.Set(currPosition, value);
            else
                std::cout << std::endl << "Invalid command!" << std::endl;
        }
    }


    return 0;
}