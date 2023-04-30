#pragma once
#include <string>
#include <fstream>
#include <iostream>

/*
Helper class that serializes the message into a given file
* takes in parameters such as message and file name
* if the file does not exist creates a new file in the same path and writes the message to the file
* setters and getters allow you to customize message as well as filename
*/
using namespace std;

class Serializer
{
private:
    string fileName;
    string Message;
    void serializeFile(string fileName, string message);

public:
    Serializer(string filename, string message);
    void setfileName(string filename);
    string getFileName();

    void setMessage(string message);
    string getMessage();


};

