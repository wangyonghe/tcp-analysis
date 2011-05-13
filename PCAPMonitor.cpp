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
void PCAPMonitor::startCapture()
{
	char buffer[PCAP_ERRBUF_SIZE];
	pcap_t * handle = pcap_open_live(mDevice.c_str(), 2048, 1, 10, buffer);
    
    u_char buff[2048];
    pcap_loop(handle, -1, callback, buff);
}
void PCAPMonitor::callback(u_char * user, const struct pcap_pkthdr * header, const u_char * packet)
{
	int size = header->len;
	
	struct ether_header * ethh;
	ethh = (struct ether_header*) packet;
	
	if(ntohs(ethh->ether_type) == ETHERTYPE_IP)
	{
		char * buffer = (char*) packet + sizeof(*ethh);
		size = size - sizeof(ethh);
		
		struct iphdr *iph = (struct iphdr*) buffer;
		if (iph->protocol == 6)
		{
			unsigned short iphdrlen;

			struct iphdr * iph = (struct iphdr *) buffer;
			iphdrlen = iph->ihl*4;

			struct tcphdr * tcph=(struct tcphdr*)(buffer + iphdrlen);
			
			struct sockaddr_in source,dest;
			memset(&source, 0, sizeof(source));
			source.sin_addr.s_addr = iph->saddr;

			memset(&dest, 0, sizeof(dest));
			dest.sin_addr.s_addr = iph->daddr;

			cout<<"TCP Packet: "<<endl<<" |- Source: "<<inet_ntoa(source.sin_addr)<<":"<<ntohs(tcph->source)<<endl<<" |- Destination: "<<inet_ntoa(dest.sin_addr)<<":"<<ntohs(tcph->dest)<<endl;
		}
	}
}
