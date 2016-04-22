//
// Created by cloubao on 4/8/16.
//

#ifndef TERMINAL_H
#define TERMINAL_H

#include <cstdlib>

using namespace std;

void clearScreen();

void drawDivider();

void waitForUser();

int getInt();

string getString();

// Linux utility methods
#if defined(__linux) || defined(__linux__) || defined(linux)

void clearScreen() {
    system("clear");
}
// Windows utility methods
#elif defined(_WIN32) || defined(__WIN32__) || defined(WIN32)
void clearScreen() {
    system("CLS");
}
#endif

void waitForUser() {
    cout << "Press ENTER to continue";
    getString();
}

string getString() {
    string input;
    getline(cin, input);
    return input;
}

int getInt() {
    try {
        return stoi(getString());
    }
    catch (std::invalid_argument e) {
        return -1;
    }
}

void drawDivider() {
    cout << setw(50) << setfill('*') << " " << endl;
}

#endif //TERMINAL_H
