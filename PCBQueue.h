#ifndef PCB_QUEUE_H
#define PCB_QUEUE_H
#include <string>
using namespace std;
////////////////////////////////////////////////////////////////////////////////////////////////////////
class PCBNode
{	public:
		PCBNode(): PCB_ID(0), next(nullptr){} //default constructor 
		PCBNode(int thePCB_ID, PCBNode* nextPCBNode): PCB_ID(thePCB_ID), next(nextPCBNode){} //constructor
		
		const int getPCB_ID() const {return PCB_ID;} //accessor function returns int PCB_ID value
		PCBNode* getNext() const {return next;} //accessor funtion returns node pointer
		
		void setPCB_ID(const int thePCB_ID) {PCB_ID = thePCB_ID;} //mutator function sets PCB_ID value
		void setNext(PCBNode* pointer) {next = pointer;} //mutator function sets next pointer	
	private:
		int PCB_ID; //process identifier
		PCBNode* next; //pcbnode pointer points to address of next pcbnode in linked list or nullptr
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PCBQueue
{	public:
		PCBQueue(); //Initilizes the object to an empty queue and names the queue
		
		PCBQueue(const PCBQueue& aQueue); //copy constructor
		
		PCBQueue& operator= (const PCBQueue& rightSide); //overloaded = operator
		
		void deletePCBQueue(); //deletes entire contents of queue
		
		virtual ~PCBQueue(); //destructor implements deletePCBQueue function
		
		void addPCB(int thePCB_ID); //Postconditiion:PCB has been added to the back of queue
		
		string getDeviceName() const; //returns the device name
		
		int remove(); //Precondition: the queue is not empty. Returns the item at front of queue
		             //and removes it
		bool isEmpty() const; //returns true only if queue is empty
		
		void readContents() const; //ouputs contents of queue
		
	private:
		string deviceName; //the name assigned by the OS to the device queue
		PCBNode* head; //points to head of queue
		PCBNode* tail; //points to end of queue
};

#endif
