all: main.o PCAPMonitor.o
	g++ -lpcap -lpthread -o main main.cpp PCAPMonitor.cpp
