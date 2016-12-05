#include <iostream>
#include <vector>
#include <string>

#include "PCB.h"
#include "PriorityPCBQueue.h"
#include "PCBQueue.h"
//#include "MemorySegment.h

void memoryManagerAdd(PCB newProcess, vector<PCB> theProcesses);
void memoryManagerRemove(PCB terminatedProcess, vector<PCB> theProcesses);
using namespace std;

int main()
{	PriorityPCBQueue CPU; //ready queue
	vector<PCBQueue> Disks; //I/O queues
	vector<PCBQueue> Printers; //I/O queues
	vector<PCB> Processes; //processes
	//vector<MemorySegment> Memory;
	
	int numberOfPrinters, numberOfDisks, sizeOfMemory;
	int priorityOfProcess, processID(0), sizeOfProcess;
	char command;

	
	cout << "How many printers are there?" << endl;
	cin >> numberOfPrinters;
	cout << "How many disks are there?" << endl;
	cin >> numberOfDisks;
	cout << "How large is the memory" << endl;
	cin >> sizeOfMemory;
	
	PCB empty(-1, -1, sizeOfMemory); //initilizes one PCB to represent the empty memory
	Processes.push_back(empty);
	
	do
	{	int temp1, temp2, temp3;
		
	
		cout << "What is the process priority?\n";
		cin >>temp1;
		
		temp2 = processID;
		cout << "The Process ID is " << temp2 << endl;
		processID++;
		
		cout << "What is the size of the process?\n";
		cin >>temp3;
		
		PCB temp(temp1, temp2, temp3);
		Processes.push_back(temp);
		
		cout << "would you like to create another process y/n ?\n" << endl;
		cin >> command;
		
	}while(command != 'n' && command != 'N');
	
	cout << endl;
	
	for(vector<PCB>::iterator it = Processes.begin(); it != Processes.end(); ++it)
	{	cout << it->getPriority() <<" "<< it->getPCB_ID() <<" "<<  it->getSize() << endl;
	}
/*	while(true == true)
	{	cin >> command;
		if(command == "A") //A indicated the arrival of a process
		{	cout << "How much memory does this process require?"<< endl;
			cin >> sizeOfProcess;
			cout << "What is the priority of this process?" << endl;
			cin >> priorityOfProcess;
			
			PCB temp(priorityOfProcess, processID, sizeOfProcess);
			PCBVector.push_back(temp);
			processID++;
		}
		else if(command == "Sr")
		{
		}
		else if(command == "Si")
		{
		}
		else if(command == "Sm")
		
	}*/

	return 0;
}
//Memory Management Add function iterates through the PCB Vector and looks for the empty slots of memory,
//which it identifies by a process ID of -1. It then looks to see which slot if the best fit for the
//new process
void memoryManagerAdd(PCB newProcess, vector<PCB>& theProcesses)
{////////////////////////////////////////////////////////////////////////////////////////////////////
	
	bool success = false;

	vector<PCB>::iterator newAddress = theProcesses.begin();
	if( newAddress->getPCB_ID() == -1 && newAddress->getSize() >= newProcess.getSize() )
	{
		success = true; //newAddress defines an empty memory slot large enough to place the process
	}
	
/////////////////////////////////////////////////////////////////////////////////////////////////////

	for(vector<PCB>::iterator it_1 = theProcesses.begin(); it_1 != theProcesses.end(); ++it_1)
	{	if(it_1->getPCB_ID() == -1 && it_1->getSize() >= newProcess.getSize())
		{	if(success == true && it_1->getSize() < newAddress->getSize())
			{	newAddress = it_1;
			}
			else if(success == false)
			{	newAddress = it_1;
				success = true;
			}
		}
	}
		
/////////////////////////////////////////////////////////////////////////////////////////////////////
	if(success = false) //There is no empty slot large enough in the memory to add process
	{
		cout << "Sorry, there is not enough memory to add the process." << endl;
		return;	
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////	
	int sizeDifference = newAddress->getSize() - newProcess.getSize();
	
	if(sizeDifference == 0)
	{	newAddress->setPriority(newProcess.getPriority()) ;
		newAddress->setPCB_ID(newProcess.getPCB_ID());

	}
	if(sizeDifference != 0)
	{	theProcesses.insert(newAddress, newProcess);
		newAddress++;
		PCB temp(-1,-1, sizeDifference);
		theProcesses.push_back(temp);
	}
}
void memoryManagerRemove(PCB terminatedProcess, vector<PCB> theProcesses)
{
}
