#ifndef PCB_H
#define PCB_H
///////////////////////////////////////////////////////////////////////////////////////////////////////
class PCB
{	public:
		PCB():priority(0),PCB_ID(0),size(0),address(0){} //default constructor represents empty block of mememory
		PCB(int thePriority, int thePCB_ID, int theSize, int theAddress):
		priority(thePriority), PCB_ID(thePCB_ID), size(theSize), address(theAddress){}
		
		int getPriority() const;
		int getPCB_ID() const;
		int getSize() const;
		int getAddress() const;
		
		void setPriority(int thePriority);
		void setPCB_ID(int thePCB_ID);
		void setSize(int theSize);
		void setAddress(int theAddress);
		
	private:
		int priority; //priority of process. Higher number means higher priority, priority >= 0
		int PCB_ID; //number identifying process
		int size; //how much memory process requires
		int address; //location of process in memory
};
////////////////////////////////////////////////////////////////////////////////////////////////////////
#endif
