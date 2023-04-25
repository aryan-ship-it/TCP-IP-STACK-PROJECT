#pragma once
#include <vector>
#include "Buffer.h" 
#include "ApplicationLayer.h"

class TransportLayer : public ApplicationLayer {

protected:
    int SourcePort;
    int DestinationPort;
    int generatePort();
public:

    void TransportLayerSet(); 
    void setSourcePort(int sourcePort);
    int getSourcePort();

    void setDestinationPort(int destPort);
    int getDestinationPort();

    void destPortGenerator();
    void sourcePortGenerator();

};

