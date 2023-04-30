#include "HTTPRequest.h"
#include <iostream>
#include <string>
using namespace std;
#include <fstream> 
#include <vector>
#include <map>

/*
* The http request Layer is the first layer that processes the message.
* Message is a map data type that creates key value pairs from the text file
* parseMessage() function parses the message from the text message from the text file and generates a map
* The parseMessage() function then calls the setter for Message and sets the key value pair
* Headers is a private data members that stores all the headers retrieved from the request
* Method clarifies whether the incoming request is a POST request or a GET request
* The constructor of this class  parses the message and sets the key value pair
*/


HTTPRequest::HTTPRequest(string Method,string fileName) {

    if (Method == "GET") { setMethod("GET"); Message["Method"] = "GET"; }
    else { setMethod("POST"); Message["Method"] = "POST";}

    Message = parseMessage(fileName);
}

void HTTPRequest::setMethod(string method) { Method = method; }
string HTTPRequest::getMethod(){ return Method;}



std::map<std::string, std::string> HTTPRequest::parseMessage(string file) {
    std::ifstream getFile(file);
    if (!getFile.is_open()) {
        std::cout << "Unable to open file." << std::endl;
        return std::map<std::string, std::string>(); // Return an empty map
    }

    std::map<std::string, std::string> request; // Map to store key-value pairs

    std::string line;
    // Read the text file line by line
    while (std::getline(getFile, line)) {
        // Skip empty lines
        if (line.empty()) {
            continue;
        }

        // Find the position of ':' separator
        std::size_t colonPos = line.find(':');
        if (colonPos != std::string::npos) {
            // Extract key and value from the line
            std::string key = line.substr(0, colonPos);
            
            std::string value = line.substr(colonPos+1);
            value.erase(value.size() - 4);
            // Add key-value pair to the map
            request[key] = value;
        }
    }

    // Close the file
    getFile.close();

    return request;
}

void HTTPRequest::setHeaders(map<string, string> map) {
    if (map.empty()) {
        return;
    }
    else {
        for (const auto& key : map) {
            Headers.push_back(key.first);
        }
    }

}

vector <string> HTTPRequest::getHeaders() {return Headers;}


void HTTPRequest::setMessage(map <string, string> buffer) { Message = buffer; }
map <string, string> HTTPRequest::getMessage() { return Message; }
