#pragma once
#include <string>


using namespace std;

class DataLinkLayer {
public:
	DataLinkLayer();
	string getDataLinkLayer();
	void setDataLinkLayer(string);
private:
	string address;
	string randomDataLinkLayer();

};

