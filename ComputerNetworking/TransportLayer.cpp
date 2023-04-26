#include "TransportLayer.h"
#include "HTTPRequest.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
//Layer3::Layer3() {
//    sourcePort = setsourcePort();
//    destinationPort = setdestinationPort();;
// }

TransportLayer::TransportLayer(HTTPRequest &Request) {
    sourcePortGenerator(); 
    destPortGenerator(); 


    string source = to_string(getSourcePort()); 
    string dest = to_string(getDestinationPort());
    

    map<string, string> TPBuffer = Request.getBuffer();
    TPBuffer["SourcePort"] = source;
    TPBuffer["DestPort"] = dest; 

    Request.setBuffer(TPBuffer);

    
    


}

void TransportLayer::setSourcePort(uint16_t sourcePort) { SourcePort = sourcePort; }



void TransportLayer::setDestinationPort(uint16_t destPort) { DestinationPort = destPort; }

uint16_t TransportLayer::getSourcePort() { return SourcePort; }

void TransportLayer::sourcePortGenerator() { SourcePort = generatePort();}

void TransportLayer::destPortGenerator() {
    do {
        DestinationPort = generatePort();
    } while (DestinationPort == SourcePort);

}
uint16_t TransportLayer::getDestinationPort() { return DestinationPort; }

uint16_t TransportLayer::generatePort() {
    uint16_t port;
    do {
        port = (rand() % 65536);
    } while (port == 80 || port == 8080 || port == 443 || port == 8888 || port == 8000);
    return port;
}