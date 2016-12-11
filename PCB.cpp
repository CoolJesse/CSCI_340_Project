#include "PCB.h"
int PCB::getPriority() const
{	return priority;
}
int PCB::getPCB_ID() const
{	return PCB_ID;
}
int PCB::getSize() const
{	return size;
}
int PCB::getAddress() const
{	return address;
}
void PCB::setPriority(int thePriority)
{	priority = thePriority;
}
void PCB::setPCB_ID(int thePCB_ID)
{	PCB_ID = thePCB_ID;
}
void PCB::setSize(int theSize)
{	size = theSize;
}
void PCB::setAddress(int theAddress)
{	address = theAddress;
}
