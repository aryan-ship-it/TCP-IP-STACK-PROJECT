#include "Buffer.h"
#include <iostream>
#include <string>
using namespace std;
#include <fstream> 
#include <vector>
#include "ApplicationLayer.h"


void Buffer::Layer1Parse() {
    ifstream getFile("getRequest.txt");
    if (!getFile.is_open()) {
        cout << "Unable to open file." << endl;
        return;
    }

    const int NUM_LINES = 8;
    vector<string> lines;
    string line;
    while (getline(getFile, line)) {
        if (lines.size() == 0) {
            lines.push_back(line.substr(0, line.find("HTTP") + 8));
        }
        else {
            size_t position = line.find(':');
            if (position != string::npos) {
                lines.push_back(line.substr(position + 2, line.length() - position - 6));
            }
        }
    }
    getFile.close();

    // assign the vector to the private member variable message
    Message = lines;
}


void Buffer::setMessage(vector<string> message ) { Message = message; }
vector <string> Buffer::getMessage() { return Message;}