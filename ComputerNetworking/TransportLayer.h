#pragma once
#include <vector>
#include "HTTPRequest.h" 
/*
* The transport layer has a composition relationship with the HTTPRequest class 
* It serves the Application layer by taking in the object and encapsulating data
* The transport layer creates a source port and destination port 
* Newly encapsulated message is stored with the Message data member
* the size of each port number is limited to 2 bytes
* The constructor gives random port values for individual data members.
*/

class TransportLayer {

private:
    map <string, string> Message;
    uint16_t SourcePort;
    uint16_t DestinationPort;
    uint16_t generatePort();
    void destPortGenerator();
    void sourcePortGenerator();
public:
    TransportLayer(HTTPRequest &Request); 

    void setMessage(map<string, string>);
    map<string, string> getMessage();

    void setSourcePort(uint16_t sourcePort);
    uint16_t getSourcePort();

    void setDestinationPort(uint16_t destPort);
    uint16_t getDestinationPort();



};

