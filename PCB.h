#ifndef PCB_H
#define PCB_H
///////////////////////////////////////////////////////////////////////////////////////////////////////
class PCB
{	public:
		PCB():priority(0),PCB_ID(0),size(0){}
		PCB(int thePriority, int thePCB_ID, int theSize):
		priority(thePriority), PCB_ID(thePCB_ID), size(theSize){}
		int getPriority() const;
		int getPCB_ID() const;
		int getSize() const;
		//unsigned int getAddress() const;
		
		void setPriority(int thePriority);
		void setPCB_ID(int thePCB_ID);
		void setSize(int theSize);
		//void setAddress(unsigned int theAddress);
		
	private:
		int priority; //priority of process. Higher number means higher priority
		int PCB_ID; //number identifying process
		int size; //how much memory process requires
		//unsigned int address; //location of process in memory
};

#endif
