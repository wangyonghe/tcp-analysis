all: main.o PCAPMonitor.o
	g++ -lpcap -o main main.cpp PCAPMonitor.cpp
