#include <iostream>
#include <algorithm>
#include <cstring>
#include <fstream>
#include "LinkedList.h"
#include <regex>

std::string StringToUpper(std::string str) {
    std::transform(str.begin(), str.end(), str.begin(), ::toupper);

    return str;
}

int main(int argc, char *args[]) {
    std::string fileName;


    // deal with arguments
    if (argc == 2)
        fileName = args[1];
    else {
        std::cout << "You must provide a file name!";
        return 0;
    }

    LinkedList list;
    int currPosition = 0;
    bool programFinished = false;
    bool save = false;
    std::regex numRegex("[0-9]|[0-4][0-9]");

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
        char userInput[20] = "";
        std::cin.getline(userInput, 20);
        auto firstLetter = StringToUpper(userInput).c_str()[0];
        if (firstLetter == 'Q') {
            std::cout << std::endl << "Quitting without saving...";
            programFinished = true;
        } else if (firstLetter == 'E') {
            std::cout << std::endl << "Quitting and saving...";
            programFinished = true;
            save = true;
        } else if (firstLetter == 'D')
            list.Set(currPosition, 0);
        else if (firstLetter == 'R') {
            for (int i = 0; i < NUM_OF_TURNS; i++)
                list.Set(i, 0);
        } else {
            // copy user input to a char array, split into tokens via space character
            char input[strlen(userInput) + 1];
            for (int i = 0; i < strlen(userInput); i++)
                input[i] = userInput[i];
            char *token;
            strtok(input, " "); // toss first token
            token = strtok(nullptr, " ");
            int value = 0;
            if (token != nullptr) {
                bool validNum = false;
                if (std::regex_match(token, numRegex)) {
                    validNum = true;
                    value = atoi(token);
                }

                // use second token differently depending on first token
                if (firstLetter == 'G' && validNum)
                    currPosition = value - 1;
                else if (firstLetter == 'S' && validNum)
                    list.Set(currPosition, value);
                else
                    std::cout << std::endl << "Invalid command!" << std::endl;

            }
        }
    }

    // save routine
    if (save) {
        std::ofstream myFile;
        myFile.open(fileName, std::ios::out);
        if (myFile.is_open()) {
            myFile << list;
            myFile.close();
        } else
            std::cout << std::endl << "Could not open file!";
    }

    return 0;
}