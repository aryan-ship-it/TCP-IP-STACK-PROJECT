// ComputerNetworking.cpp : This file contains the 'main' function. Program execution begins and ends here.
/*
* This file's main program is responsible for handling incoming requests and passing the message through different layers.
* it uses different classes such as the Application Layer, Transport Layer, Network Layer, Data Link Layer and the Physical Layer.
* To handle incoming requests the program uses a singleton design pattern (Similar to the event loop). 
* Incoming requests are put in a queue called requestQueue. Elements from this request queue are popped by the First Layer which is the Application Layer
* The application generates the first object from the text file and encapsulates the message. This message is then served by the transport layer
* Each Layer encapsulates the message and adds different headers to it . For example : IP Address, Port Number, MAC address etc
* The Physical Layer, Also the final layer takes the encapsulated message serializes it to different text files such as the request.txt, requestObject.txt
* RequestObject.txt has the string object representation of the message
* Request.txt has the binary representation of the message 
*/


#include <iostream>
#include <string>
#include <fstream>
#include "TransportLayer.h"
#include "NetworkLayer.h"
#include "DataLinkLayer.h"
#include "PhysicalLayer.h"
#include "HTTPRequest.h"
#include "Serializer.h"
#include <vector>
#include <queue>

using namespace std;






int main()
{
	//parse  GET and POST messages from the text files 
	HTTPRequest request("GET","getRequest.txt");
	HTTPRequest request2("POST","postRequest.txt");

	//request queue to handle incoming requests
	queue<HTTPRequest> requestQueue;
	requestQueue.push(request);
	requestQueue.push(request2);

	//event loop to process incoming requests 
	while(!requestQueue.empty()){
		//takes the latest request from the queue
		HTTPRequest req = requestQueue.front();
		//tcp layer serves the httpRequest layer by encapsulating port number
		TransportLayer tcpObj(req);
		//network layer encapsulates the IP address
		NetworkLayer netObj(tcpObj);

		//data link layer encapsulates the mac address
		DataLinkLayer dataObj(netObj);

		//logger 
		for (const auto& pair : dataObj.getMessage()) {
			std::cout << pair.first << ":" << pair.second << std::endl;
		}


		cout << endl;

		//binaryoutput object
		PhysicalLayer binaryOutput(dataObj);
		//write the string object to a file
		Serializer serialize("RequestObject.txt", binaryOutput.getMapString());

		cout << endl;
		cout << binaryOutput.getMapString();

		cout << endl;
		cout << endl;
		//clear the obj from the stack
		requestQueue.pop();


	}
   
}




