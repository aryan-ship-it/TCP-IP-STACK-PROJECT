#include "ApplicationLayer.h"
#include "IPAddress.h"
#include <vector>
#include <iostream>


using namespace std; 

void ApplicationLayer:: RandomIPset(){
	IPAddress source; 
	string sourceIP = source.getIPAddress();

	IPAddress dest;
	string destIP = dest.getIPAddress();

	source.setIPAddress(sourceIP);
	dest.setIPAddress(destIP);

	Message.push_back("sourceIP: " + sourceIP);
	Message.push_back("DestIP: " + destIP);
		


}




