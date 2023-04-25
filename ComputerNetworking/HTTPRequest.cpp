#include "HTTPRequest.h"
#include <iostream>
#include <string>
using namespace std;
#include <fstream> 
#include <vector>
#include <map>
//#include "ApplicationLayer.h"


HTTPRequest::HTTPRequest() {
    Buffer = parseBuffer();
}

std::map<std::string, std::string> HTTPRequest::parseBuffer() {
    std::ifstream getFile("getRequest.txt");
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
            std::cout << "Key: " << key << ", Value: " << value << std::endl;
        }
    }

    // Close the file
    getFile.close();

    return request;
}
