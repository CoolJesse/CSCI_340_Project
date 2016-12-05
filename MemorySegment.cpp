#include "MemorySegment.h"

void MemorySegment::setEmptyMemory(bool isEmpty)
{	emptyMemory = isEmpty;
}
void MemorySegment::setProcess_ID(int theProcess_ID)
{	process_ID = theProcess_ID;
}
void MemorySegment::setSizeOfSegment(int theSize)
{	sizeOfSegment = theSize;
}
void MemorySegment::setLocation(int theLocation)
{	location = theLocation;
}		
bool MemorySegment::getEmptyMemory() const
{	return emptyMemory;
}
int MemorySegment::getProcess_ID() const
{	return process_ID;
}
int MemorySegment::getSizeOfSegment() const
{	return sizeOfSegment;
}
int MemorySegment::getLocation() const
{	return location;
}
