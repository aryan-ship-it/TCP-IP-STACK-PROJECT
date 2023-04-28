#pragma once
#include <vector>
#include "HTTPRequest.h" 


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

