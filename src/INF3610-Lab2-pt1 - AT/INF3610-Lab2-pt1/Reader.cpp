///////////////////////////////////////////////////////////////////////////////
//
//	Reader.cpp
//
///////////////////////////////////////////////////////////////////////////////
#include "Reader.h"

///////////////////////////////////////////////////////////////////////////////
//
//	Constructor
//
///////////////////////////////////////////////////////////////////////////////
Reader::Reader(sc_module_name name)
/* └ complÚter */
{
	/*
	
	└ complÚter
	
	*/
	SC_METHOD(thread);
	sensitive << clk;
}

///////////////////////////////////////////////////////////////////////////////
//
//	Destructor
//
///////////////////////////////////////////////////////////////////////////////
Reader::~Reader()
{
	/*
	
	└ complÚter
	
	*/
}

///////////////////////////////////////////////////////////////////////////////
//
//	Thread
//
///////////////////////////////////////////////////////////////////////////////
void Reader::thread(void)
{
	/*
	
	└ complÚter
	
	*/
	// Synchronize to gather the reading address 
	do
	{
		wait(request.posedge_event());
	} while (!request.read());

	unsigned int adrs = address.read();

	// Write the corresponding data
	data.write(dataPortRAM->Read(adrs));

	ack.write(true);

	return;
}