#pragma once
#include <vector>
#include "Buffer.h" 
#include "ApplicationLayer.h"

class TransportLayer : public ApplicationLayer {

protected:
    uint16_t SourcePort;
    uint16_t DestinationPort;
    uint16_t generatePort();
public:

    void TransportLayerSet(); 
    void setSourcePort(uint16_t sourcePort);
    uint16_t getSourcePort();

    void setDestinationPort(uint16_t destPort);
    uint16_t getDestinationPort();

    void destPortGenerator();
    void sourcePortGenerator();

};

