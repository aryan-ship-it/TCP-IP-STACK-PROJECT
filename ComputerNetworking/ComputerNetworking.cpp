// ComputerNetworking.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <string>
#include <fstream>
#include "ApplicationLayer.h"
#include "TransportLayer.h"
#include "NetworkLayer.h"
#include "DataLinkLayer.h"
#include "PhysicalLayer.h"
#include "Buffer.h"
#include <vector>

using namespace std;




int main()
{
    ApplicationLayer A; 
    A.Layer1Parse();
    A.RandomIPset();
    for (const auto& str : A.getMessage()) {
        cout << str << endl;
    }


   
}




