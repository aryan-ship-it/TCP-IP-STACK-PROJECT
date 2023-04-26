#pragma once
#include <vector>
#include "HTTPRequest.h" 
#include "ApplicationLayer.h"

class TransportLayer {

protected:
    uint16_t SourcePort;
    uint16_t DestinationPort;
    uint16_t generatePort();
public:

    TransportLayer(HTTPRequest &request); 
    void setSourcePort(uint16_t sourcePort);
    uint16_t getSourcePort();

    void setDestinationPort(uint16_t destPort);
    uint16_t getDestinationPort();

    void destPortGenerator();
    void sourcePortGenerator();

};

