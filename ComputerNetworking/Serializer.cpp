#include "Serializer.h"
#include <iostream>
#include <fstream>
#include <string>

Serializer::Serializer(string fileName,string message) {
    setfileName(fileName);
    setMessage(message);

    serializeFile(fileName, message);

}

void Serializer::setfileName(string filename) {
    fileName = filename;
}

string Serializer::getFileName() {
    return fileName;
}

void Serializer::setMessage(string message) {
    Message = message;
}

string Serializer::getMessage() {
    return Message;
}

void Serializer::serializeFile(string FileName, string message) {
    ifstream infile(FileName);
    if (infile.good()) {
        //infile.close();
        ofstream outfile(fileName, ios_base::app);
        outfile << message << endl;
        outfile.close();
        cout << "Text added to file." << endl;
    }
    else {
        // File does not exist, create file and add text
        //infile.close();
        ofstream outfile(fileName);
        outfile << message << endl;
        outfile.close();
        cout << "File created and text added to file." << endl;
    }
}