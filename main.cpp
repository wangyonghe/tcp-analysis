#include <iostream>

#include "PCAPMonitor.hpp"

int main()
{
	PCAPMonitor * pcap = new PCAPMonitor();
	
	delete pcap;
	return 0;
}
