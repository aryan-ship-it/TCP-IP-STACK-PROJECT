#include "TransportLayer.h"
#include "Buffer.h"
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

void TransportLayer::TransportLayerSet() {
    sourcePortGenerator(); 
    destPortGenerator(); 


    string source = to_string(getSourcePort()); 
    string dest = to_string(getDestinationPort());


    Message.push_back("Source Port : " + source);
    Message.push_back("Destination Port : " + dest);

}

void TransportLayer::setSourcePort(int sourcePort) { SourcePort = sourcePort; }



void TransportLayer::setDestinationPort(int destPort) { DestinationPort = destPort; }

int TransportLayer::getSourcePort() { return SourcePort; }

void TransportLayer::sourcePortGenerator() { SourcePort = generatePort();}

void TransportLayer::destPortGenerator() {
    do {
        DestinationPort = generatePort();
    } while (DestinationPort == SourcePort);

}
int TransportLayer::getDestinationPort() { return DestinationPort; }

int TransportLayer::generatePort() {
    srand(time(nullptr));
    int port;
    do {
        port = (rand() % 65536);
    } while (port == 80 || port == 8080 || port == 443 || port == 8888 || port == 8000);
    return port;
}