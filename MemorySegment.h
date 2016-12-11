#ifndef MEMORY_SEGMENT_H
#define MEMORY_SEGMENT_H
/////////////////////////////////////////////////////////////////////////////////////////////////////////
class MemorySegment
{	public:
		MemorySegment(): emptyMemory(true), process_ID(0), sizeOfSegment(0), location(0){}
		MemorySegment(bool isEmpty, int theProcess_ID, int theSize, int theLocation):
		emptyMemory(isEmpty), process_ID(theProcess_ID), sizeOfSegment(theSize), location(theLocation){}	
		
		void setEmptyMemory(bool isEmpty);
		void setProcess_ID(int theProcess_ID);
		void setSizeOfSegment(int theSize);
		void setLocation(int theLocation);
		
		bool getEmptyMemory() const;
		int getProcess_ID() const;
		int getSizeOfSegment() const;
		int getLocation() const;
	
	private:
		bool emptyMemory; //returns true if the memory segment is empty memory
		int process_ID; //of memory segment is not empty this is the process that occupies it
		int sizeOfSegment; //size of process that occupies memory segment
		int location; //address of first register of process
		
};

#endif
