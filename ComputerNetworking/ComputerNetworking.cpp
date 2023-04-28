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
		TransportLayer T(req);
		NetworkLayer N(T);
		DataLinkLayer D(N);

		for (const auto& pair : D.getMessage()) {
			std::cout << pair.first << ":" << pair.second << std::endl;
		}


		cout << endl;
		PhysicalLayer P(D);
		cout << endl;
		requestQueue.pop();


	}
   
}




