#include <iostream>

#include "PCAPMonitor.hpp"

int main()
{
	PCAPMonitor * pcap = new PCAPMonitor();
	pcap->start();
	
	getchar();
	
	pcap->stop();
	delete pcap;
	return 0;
}
