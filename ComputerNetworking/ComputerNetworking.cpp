// ComputerNetworking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>

using namespace std;
void parseMessage() {
    fstream getFile;
    getFile.open("getRequest.txt", ios::in); //reading from file gerRequest.txt
    if (getFile.is_open()) {
        string line;
        while (getline(getFile, line)) {
            string name;
            string value;
            size_t position = line.find("\r");
            if (position != std::string::npos) {
                name = line.substr(0, position);
                value = line.substr(position + 1);
            }
            else {                
                value = line;
            }

            cout  << value << endl;
        }
        getFile.close();
    }
    else {
        cout << "unable to open file" << endl;
    }


}

int main()
{
    std::cout << "Hello World!\n";
    parseMessage();
}

