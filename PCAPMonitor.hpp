#ifndef PCAPMONITOR_HPP
#define PCAPMONITOR_HPP

#include <string>
#include <iostream>
#include <pcap.h>

using namespace std;

class PCAPMonitor
{
	public:
		PCAPMonitor();
	
	private:
		string mDevice;
		
};

#endif
