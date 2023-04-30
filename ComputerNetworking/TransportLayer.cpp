#include "TransportLayer.h"
#include "HTTPRequest.h"
#include <string>
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <vector>

using namespace std;
/*
* The transport layer has a composition relationship with the HTTPRequest class
* It serves the Application layer by taking in the object and encapsulating data
* The transport layer creates a source port and destination port
* Newly encapsulated message is stored with the Message data member
* the size of each port number is limited to 2 bytes
* The constructor gives random port values for individual data members.
*/

//constructor
TransportLayer::TransportLayer(HTTPRequest &Request) {
    sourcePortGenerator(); //generate source port 
    destPortGenerator(); //generate destport

    setMessage(Request.getMessage()); //getMessage from the HTTP Layer
 

    Message["SourcePort"] = to_string(getSourcePort()); //add source port to the map
    Message["DestPort"] = to_string(getDestinationPort()); //add dest port to the map

    
    


}

//setters and getters
void TransportLayer::setSourcePort(uint16_t sourcePort) { SourcePort = sourcePort; }
void TransportLayer::setDestinationPort(uint16_t destPort) { DestinationPort = destPort; }

uint16_t TransportLayer::getSourcePort() { return SourcePort; }
void TransportLayer::sourcePortGenerator() { SourcePort = generatePort();}

void TransportLayer::setMessage(map<string, string> message) {Message = message;}
map<string, string> TransportLayer::getMessage() { return Message; }

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