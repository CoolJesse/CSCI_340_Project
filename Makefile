
memoryProject: main.o PCB.o PriorityPCBQueue.o PCBQueue.o
	g++ -std=c++11 -o memoryProject main.o PCB.o PriorityPCBQueue.o PCBQueue.o

main.o: main.cpp PCB.h PriorityPCBQueue.h PCBQueue.h
	g++ -std=c++11 -c main.cpp

PCB.o: PCB.h PCB.cpp
	g++ -std=c++11 -c PCB.cpp

PriorityPCBQueue.o: PriorityPCBQueue.h PriorityPCBQueue.cpp PCB.h
	g++ -std=c++11 -c PriorityPCBQueue.cpp

PCBQueue.o: PCBQueue.h PCBQueue.cpp PCB.h
	g++ -std=c++11 -c PCBQueue.cpp 


