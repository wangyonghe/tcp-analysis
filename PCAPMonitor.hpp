#ifndef PCAPMONITOR_HPP
#define PCAPMONITOR_HPP

#include <string>
#include <cstdlib>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <pcap.h>
#include<net/ethernet.h>
#include<netinet/tcp.h>
#include<netinet/ip.h> 
#include <sys/socket.h>
#include <arpa/inet.h>

using namespace std;

class PCAPMonitor
{
	public:
		PCAPMonitor();
		void start();
		void stop();
		~PCAPMonitor();
	
	private:
		static void * startThread(void * object);
		static void callback(u_char * user, const struct pcap_pkthdr * handle, const u_char * buffer);
	
		string 			mDevice;
		pcap_t * 		mHandle;
		bool 			mRunning;
		bool			mStopRequested;
		pthread_mutex_t	mMutex;
		pthread_t		mThread;
		
};

#endif
