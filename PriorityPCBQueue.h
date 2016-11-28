#ifndef PRIORITY_PCB_QUEUE_H
#define PRIORITY_PCB_QUEUE_H
#include "PCB.h"
////////////////////////////////////////////////////////////////////////////////////////////////////////
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class PriorityPCBNode
{	public:
		PriorityPCBNode(): priority(0), PCB_ID(0), next(nullptr){} //default constructor 
		PriorityPCBNode(int thePriority, int thePCB_ID, PriorityPCBNode* nextNode): 
		priority(thePriority), PCB_ID(thePCB_ID), next(nextNode){} //constructor
		
		const int getPriority() const {return priority;} //accessor function returns int priority value
		const int getPCB_ID() const {return PCB_ID;} //accessor function returns int PCB_ID value
		PriorityPCBNode* getNext() const {return next;} //accessor funtion returns PriorityPCBNode pointer
		//void setPriority(const int thePriority) {priority = thePriority;} //mutator function sets var value
		 
		void setNextNode(PriorityPCBNode* pointer) {next = pointer;} //mutator function sets next pointer	
	private:
		int priority; //priority of process. Higher number means higher priority
		int PCB_ID; //number identifying process 
		PriorityPCBNode* next; //node pointer point to address of next node in linked list or nullptr
};
/////////////////////////////////////////////////////////////////////////////////////////////////////////
////////////////////////////////////////////////////////////////////////////////////////////////////////
class PriorityPCBQueue
{	public:
		PriorityPCBQueue(); //Initilizes the object to an empty queue
		
		PriorityPCBQueue(const PriorityPCBQueue& aQueue); //copy constructor
		
		PriorityPCBQueue& operator= (const PriorityPCBQueue& rightSide);
		
		void deletePriorityPCBQueue();
		
		virtual ~PriorityPCBQueue();
		
		void add(int thePriority, int thePCB_ID); //Postconditiion:item has been added to the back of queue
		
		int remove(); //Precondition: the queue is not empty. Returns the item at front of queue
		             //and removes it
		bool isEmpty() const; //returns true only if queue is empty
		
	private:
		PriorityPCBNode* head; //points to head of queue
		PriorityPCBNode* tail; //points to end of queue
};
#endif
