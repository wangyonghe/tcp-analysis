#include <iostream>

#include "PCAPMonitor.hpp"

int main()
{
	PCAPMonitor * pcap = new PCAPMonitor();
	pcap->startCapture();
	
	delete pcap;
	return 0;
}
