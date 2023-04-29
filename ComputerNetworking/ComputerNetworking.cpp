// ComputerNetworking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

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

	HTTPRequest request("GET","getRequest.txt");
	HTTPRequest request2("POST","postRequest.txt");

	queue<HTTPRequest> requestQueue;
	requestQueue.push(request);
	requestQueue.push(request2);
	while(!requestQueue.empty()){		
		HTTPRequest req = requestQueue.front();
		TransportLayer tcpObj(req);
		NetworkLayer netObj(tcpObj);
		DataLinkLayer dataObj(netObj);

		for (const auto& pair : dataObj.getMessage()) {
			std::cout << pair.first << ":" << pair.second << std::endl;
		}


		cout << endl;

		PhysicalLayer binaryOutput(dataObj);
		Serializer serialize("RequestObject.txt", binaryOutput.getMapString());

		cout << endl;
		cout << binaryOutput.getMapString();

		cout << endl;
		cout << endl;
		requestQueue.pop();


	}
   
}




