#include "PCAPMonitor.hpp"

PCAPMonitor::PCAPMonitor()
{
	char buffer[PCAP_ERRBUF_SIZE];
	char * device;
	device = pcap_lookupdev(buffer);
	
	if (device == 0)
		throw string(buffer);
	else
		mDevice = device;

	cout<<"Device found: "<<mDevice<<endl;
}
