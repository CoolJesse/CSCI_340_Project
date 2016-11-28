#include <iostream>
#include <vector>
#include "PCB.h"
#include "PriorityPCBQueue.h"

using namespace std;

int main()
{	PriorityPCBQueue CPU;
	vector<PCB> PCBVector;
	
	int numberOfPrinters, numberOfDisks, sizeOfMemory;
	int priorityOfProcess, processID(0), sizeOfProcess, processAddress;
	char command;

	
	cout << "How many printers are there?" << endl;
	cin >> numberOfPrinters;
	cout << "How many disks are there?" << endl;
	cin >> numberOfDisks;
	cout << "How large is the memory" << endl;
	cin >> sizeOfMemory;
	
	while(true == true)
	{	cin >> command;
		if(command == 'A') //A indicated the arrival of a process
		{	cout << "How much memory does this process require?"<< endl;
			cin >> sizeOfProcess;
			cout << "What is the priority of this process?" << endl;
			cin >> priorityOfProcess;
			
			PCB temp(priorityOfProcess, processID, sizeOfProcess);
			PCBVector.push_back(temp);
			processID++;
		}
		/*else if()
		{
		}*/
		
	}

	return 0;
}
