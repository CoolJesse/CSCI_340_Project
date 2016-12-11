#include <iostream>
#include <vector>
#include <string>
//#include <regex>

#include "PCB.h"
#include "PriorityPCBQueue.h"
#include "PCBQueue.h"


bool memoryManagerAdd(PCB& newProcess, vector<PCB>& theProcesses);
bool memoryManagerRemove(int terminatedProcess, vector<PCB> theProcesses);
void mergeEmptyMemory(vector<PCB> theProcesses);

using namespace std;

int main()
{		
	PriorityPCBQueue CPU; //ready queue
	vector<PCBQueue> Disks; //I/O queues
	vector<PCBQueue> Printers; //I/O queues
	vector<PCB> Processes; //processes
	//vector<MemorySegment> Memory;

	int numberOfPrinters, numberOfDisks, sizeOfMemory;
	int priorityOfProcess, processID(0), sizeOfProcess, memoryAddress(0);
	string command;

	cout << "How many printers are there?" << endl;
	cin >> numberOfPrinters;
	cout << "How many disks are there?" << endl;
	cin >> numberOfDisks;
	cout << "How large is the memory" << endl;
	cin >> sizeOfMemory;

	PCB empty(-1, -1, sizeOfMemory,memoryAddress); //initilizes one PCB to represent the empty memory at address 0
	Processes.push_back(empty);	

	while(true)
	{	cout << "Enter Command\n";
		cin >> command;
///////////////////////////////////////////////////////////////////////////////////////////////////////
		if(command.size()>2)
		{	cout << "Please enter a valid command\n";
		}		
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command == "A") //A indicated the arrival of a process
		{	int temp1, temp2, temp3;
			cout << "You have created a process, what is the process priority?\n";
			cin >>temp1;

			temp2 = processID;
			processID++;
			
			cout << "What is the size of the process?\n";
			cin >>temp3;
		
			PCB temp(temp1, temp2, temp3, memoryAddress); //creates temp PCB object
			memoryManagerAdd(temp, Processes);//inserts new PCB into PCB<vector> Processes
			memoryAddress += temp3;//increments address by size of process added
			
			CPU.add(temp1, temp2);
		}
////////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command == "t")//terminates process
		{	int PCB_to_remove = CPU.remove();
			memoryManagerRemove(PCB_to_remove, Processes);			
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command[0] == 'd')//Process currently in CPU requests disk queue d%
		{	int value = command[1] - '0';
			if(value > Disks.size()||value < 0)
			{	cout << "Please enter a valid command\n";
			}
			else
			{	int tempPCB_ID = CPU.remove();
				Disks[value-1].addPCB(tempPCB_ID);
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command[0] == 'D')//Disk signals completion of task at head of queue
		{	int value = command[1] - '0';
			if(value > Disks.size()||value < 0)
			{	cout << "Please enter a valid command\n";
			}
			else
			{	int tempPCB_ID = Disks[value-1].remove();//removes process from I/O queue
				for(int i=0; i<Processes.size(); ++i)
				{	if(Processes[i].getPCB_ID() == tempPCB_ID)
					{	CPU.add(Processes[i].getPriority(), Processes[i].getPCB_ID());//adds process to ready queue
						break;
					}
				}
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command[0] == 'p')//Process curently running on CPU request printer
		{	int value = command[1] - '0';
			if(value > Printers.size()||value < 0)
			{	cout << "Please enter a valid command\n";
			}
			else
			{	int tempPCB_ID = CPU.remove();
				Printers[value-1].addPCB(tempPCB_ID);
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command[0] == 'P')
		{	int value =  command[1] - '0';
			if(value > Printers.size()||value < 0)
			{	cout << "Please enter a valid command\n";
			}
			else
			{	int tempPCB_ID = Printers[value-1].remove();//removes process from I/O queue
				for(int i=0; i<Processes.size(); ++i)
				{	if(Processes[i].getPCB_ID() == tempPCB_ID)
					{	CPU.add(Processes[i].getPriority(), Processes[i].getPCB_ID());//adds process to ready queue
						break;
					}
				}	
			}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command == "S") //snapshot
		{
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////		
		else if(command == "Sr")//show contents of ready-queue and PID of process using CPU
		{	CPU.readContents();
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command == "Si")//show contents of each I/O queue and PID of process using device
		{	for(int i=0; i<Disks.size(); ++i)
			{	cout << "Disk queue " << i+1 <<":\n";
				Disks[i].readContents(); 	
			}
			for(int i=0; i<Printers.size(); ++i)
			{	cout << "Printer queue " << i+1 << ":\n";
				Printers[i].readContents();
			}
		}
//////////////////////////////////////////////////////////////////////////////////////////////////////
		else if(command == "Sm")//show state of memory
		{		for(vector<PCB>::iterator it = Processes.begin(); it != Processes.end(); ++it)
				{	if(it->getPriority()==-1)
					{	cout<<"Empty "<<it->getAddress()<<"-"<<it->getAddress() + it->getSize()<<endl;
					}
					else
					{
						cout<<"PCD ID:" <<it->getPCB_ID()<<" "<<"Priority:"<<it->getPriority() <<" "<<
					"size:"<<it->getSize() <<" "<<"address:"<<it->getAddress()<<"-"<<it->getSize() + it->getAddress()<<endl;
					}
				}
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
		else//invalid command entered
		{	cout << "Please enter a valid command\n";
		}
///////////////////////////////////////////////////////////////////////////////////////////////////////
	}//end of while loop
///////////////////////////////////////////////////////////////////////////////////////////////////////
return 0;
}//end of main() function

///////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
//Memory Management Add function iterates through the PCB Vector and looks for the empty slots of memory,
//which it identifies by a process ID of -1. It then looks to see which slot if the best fit for the
//new process//////////////////////////////////////////////////////////////////////////////////////////
bool memoryManagerAdd(PCB& newProcess, vector<PCB>& theProcesses)
{	bool success = false;

	vector<PCB>::iterator newAddress = theProcesses.begin(); //points to beginning of array to begin search
	
	if( newAddress->getPCB_ID() == -1 && newAddress->getSize() >= newProcess.getSize() )
	{
		success = true; //newAddress defines an empty memory slot large enough to place the process
	}	
/////////////////////////////////////////////////////////////////////////////////////////////////////
//for loop travels through vector looking for any block of memory marked as empty denoted by a PCB_ID = -1.
//When it encounters such a block it looks to see if this block of empty memory is large enough to fit 
//the new process. If the block of memory is both empty and large enough to fit the process the conditional
//statements look to see if the process has already been assigned to a potential block of memory and if it
//has, looks to see if the new block of memory is a smaller and thus a better fit for the new process.
//Assignes the process to the block of empty memory if it is a better fit. If the process hasn't yet been 
//assigned to a block of memory this function now does so and marks success as true indicating the process
//has been allocated some memory/////////////////////////////////////////////////////////////////////
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
		return success;	
	}
//////////////////////////////////////////////////////////////////////////////////////////////////////
	
	int sizeDifference = newAddress->getSize() - newProcess.getSize();
		
	if(sizeDifference == 0) // If block of memory is a perfect fit for the new process
	{	newAddress->setPriority(newProcess.getPriority()) ;
		newAddress->setPCB_ID(newProcess.getPCB_ID());
	} 
	
	if(sizeDifference != 0)
	{	newAddress->setSize(sizeDifference);
		int tempAddress = newAddress->getAddress()+sizeDifference;
		newAddress->setAddress(tempAddress);
		
		theProcesses.insert(newAddress, newProcess); //Inserts process at newAddress location in vector
	}
	return success;
}
/////////////////////////////////////////////////////////////////////////////////////////////////////////
bool memoryManagerRemove(int terminatedProcess, vector<PCB> theProcesses)
{	bool locatedProcess = false;
	vector<PCB>::iterator theAddress = theProcesses.begin();
	
	for(vector<PCB>::iterator it_1 = theProcesses.begin(); it_1 != theProcesses.end(); ++it_1)
	{	if(it_1->getPCB_ID() == terminatedProcess)
		{	locatedProcess = true;
			theAddress = it_1;
			break;
		}
	}
	if(locatedProcess == false)
	{	cout << "could not locate the process to delete it." << endl;
	}
	else if(locatedProcess == true)
	{	theAddress->setPriority(-1);
		theAddress->setPCB_ID(-1);
		
		mergeEmptyMemory(theProcesses); //helper function to merge any sequential empty memory
	}
	return locatedProcess;
}
//////////////////////////////////////////////////////////////////////////////////////////////////////	
void mergeEmptyMemory(vector<PCB> theProcesses)
{	for(vector<PCB>::iterator it_1 = theProcesses.begin(), it_2 = theProcesses.begin()+1; it_2 != theProcesses.end(); ++it_1, ++it_2)
	{	if(it_1->getPCB_ID() == -1 && it_2->getPCB_ID() == -1) //two consecutive empty memory segments
		{	it_2->setSize(it_1->getSize() + it_2->getSize()); //empty memory sizes are added
			it_2->setAddress(it_1->getAddress()); //second empty memory segment now holds address of first
			
			theProcesses.erase(it_1); //removes the first of the consecutive empty memory segments
		}	
	}
}
//////////////////////////////////////////////////////////////////////////////////////////////////////
