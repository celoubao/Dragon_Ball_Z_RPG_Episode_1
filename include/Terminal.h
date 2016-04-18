//
// Created by cloubao on 4/8/16.
//

#ifndef TERMINAL_H
#define TERMINAL_H

#include <cstdlib>

using namespace std;

void clearScreen();

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
    getString();
}

string getString() {
    string input;
    getline(cin, input);
    return input;
}

int getInt() {
    int input;
    cin >> input;
    return input;
}

#endif //TERMINAL_H
