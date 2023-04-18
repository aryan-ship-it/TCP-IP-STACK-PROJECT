#include "Buffer.h"
#include <iostream>
#include <string>
using namespace std;
#include <fstream> 


void Buffer::parseMessage() {
    ifstream getFile("getRequest.txt");
    if (!getFile.is_open()) {
        cout << "Unable to open file." << endl;

        return;
    }

    const int NUM_LINES = 8;
    string lines[NUM_LINES];
    int i = 0;
    string line;
    while (getline(getFile, line)) {
        if (i == 0) {
            lines[i] = line.substr(0, line.find("HTTP") + 8);
        }
        else {
            size_t position = line.find(':');
            if (position != std::string::npos) {
                lines[i] = line.substr(position + 2, line.length() - position - 6);
            }
        }
        i++;
    }
    getFile.close();

    // print the lines in the array
    for (int i = 0; i < NUM_LINES; i++) {
        cout << lines[i] << endl;
    }

    cout << lines[2];


    return;
}