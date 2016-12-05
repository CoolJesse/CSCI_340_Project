#include "PCBQueue.h"
#include <iostream>
using namespace std;

PCBQueue::PCBQueue(string theDeviceName) //default constructor
{	deviceName = theDeviceName;
	head = nullptr;
	tail = nullptr;
}
PCBQueue::PCBQueue(const PCBQueue& aQueue) //copy consturctor
{
	if(aQueue.isEmpty() == true) //if aQueue is empty make this->queue empty
	{   head = nullptr;
		tail = nullptr;
	}
	else                         //if aQueue is not empty
	{	PCBNode* temp = aQueue.head; //create Node ptr temp and use to move through aQueue starting at aQueue.head
	
		head = new PCBNode(temp->getPCB_ID(), nullptr); //set head ptr equal to new node object
		tail = head;             //set tail ptr equal to head ptr since there is only one node currently in list
		temp = temp->getNext();  //temp ptr points to second node in aQueue or nullptr if there is now second node
		while(temp != nullptr)   //if temp does not point to nullptr there are more nodes in aQueue
		{	tail->setNext(new PCBNode(temp->getPCB_ID(), nullptr)); //sets next of the node tail points to
			tail = tail->getNext(); //tail now points at the new node object just created by setNextNode()
			temp = temp->getNext();	//temp now point at next node in aQueue or nullptr if end of aQueue
		}
	}
}
PCBQueue& PCBQueue::operator= (const PCBQueue& rightSide) // overload = sign
{	deletePCBQueue(); //first deletes any queue that might already exist

	PCBNode* temp = rightSide.head; //creates temp Node ptr to move through rightSide queue
		
	head = new PCBNode(temp->getPCB_ID(), nullptr); //head now points at new Node object
	tail = head; //tail now point at same Node object as head
	temp = temp->getNext();  //temp ptr points to second node in rightSide or nullptr if there is now second node
		
	while(temp != nullptr)   //if temp does not point to nullptr there are more nodes in rightSide
	{	tail->setNext(new PCBNode(temp->getPCB_ID(), nullptr)); //sets next of the node tail points to
		tail = tail->getNext(); //tail now points at the new node object just created by setNextNode()
		temp = temp->getNext();	//temp now point at next node in rightSide or nullptr if end of aQueue
	}		
	return *this;
}
void PCBQueue::deletePCBQueue() //delete function
{	if(head != nullptr) //checks to see if queue is already empty
	{	PCBNode* temp = head; // if queue is not empty creat temp Node pointer to move through queue
		
		while(head != nullptr) // while head ptr doesn't point to a nullptr we have not yet reached the end
		{	head = head->getNext(); // head now points to the next node in the queue
		    delete temp; // the node head used to point to is now deleted
		    temp = head; // temp again point to the same node as head
		}
		tail = nullptr; //set tail to nullptr to avoid dangling pointer
	}
}
PCBQueue::~PCBQueue()
{
	deletePCBQueue();
}
void PCBQueue::addPCB(int thePCB_ID) //mutator function to add item to queue
{
	if(isEmpty()==true) //if queue is empty 
	{	head = new PCBNode(thePCB_ID, nullptr); //add item to head of queue
		tail = head; //tail and head both point to the one object in the queue
	}
	else //if queue is not empty
	{	tail->setNext(new PCBNode(thePCB_ID, nullptr)); //create new node and add item to end of queue
		tail = tail->getNext(); //tail now point at new node at end of queue
	}
}
string PCBQueue::getDeviceName() const
{	return deviceName;
} 
int PCBQueue::remove() //access item in queue and remove it
{	if(isEmpty()==true) //if the queue is empty
	{	cout << "Queue is empty" << endl; //print line informing user queue is empty
		return 0;
	}
	else           //if the queue is not empty
	{	int PCB_ID = head->getPCB_ID(); // create tempVar to return item at head of queue
		PCBNode* tempPtr = head; // create tempPtr to delete the node head points to without deleting head
		head = head->getNext(); //head now point to next node in list
		delete tempPtr;      // the node that was at the head of the queue is now deleted
		tempPtr = nullptr;   //tempPtr now point to nullptr 
		return PCB_ID;      //return the item that was at the head of the queue
	}
}
bool PCBQueue::isEmpty() const //test to see if queue is empty
{
	if(head==nullptr) // if head ptr point to nullptr we know the queue is empty
		return true;
	else              // if head ptr does not point to nullptr then it points to a node and the queue is not empty
		return false;
}
