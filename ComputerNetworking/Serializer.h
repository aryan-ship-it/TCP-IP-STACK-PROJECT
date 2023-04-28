#pragma once
#include <string>
#include <fstream>
#include <iostream>


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

