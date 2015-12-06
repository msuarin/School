//================================== file = project.c ========================
//=  A CSIM simulation of a time redirected Master server with an assistant server=
//=============================================================================
//=  Build: standard CSIM build                                               =
//=---------------------------------------------------------------------------=
//=  Execute: project                                                         =
//=---------------------------------------------------------------------------=
//=  Author: Mark Suarin													  =
//=  Notes:  This code is derived from class examples written by Dr. Christensen and Mehrgan Mostowfi=
//=          University of South Florida                                      =
//=          email: msuarin@mail.usf.edu                                      =
//=---------------------------------------------------------------------------=
//=  History: MS  (07/14/12) - Genesis                                        =
//=============================================================================

//----- Includes --------------------------------------------------------------
#include <stdio.h>      // Needed for printf()
#include <stdlib.h>
#include "csim.h"       // Needed for CSIM18 stuff

//----- Defines ---------------------------------------------------------------
#define SIM_TIME   1.0e4  // Total simulation time in seconds
#define SERV_TIMEA 0.001  // Deterministic service time for Assistant server queue
#define SERV_TIMEM 0.010  // Deterministic service time for Master server queue
#define TSERV	   15.0	  //Serving time of Master
#define T_NOT_SERV 10.0	  //Sleep time of Master
#define DELAY 3.0

//----- Globals ---------------------------------------------------------------
FACILITY Assistant;        // Declaration of CSIM Assistant Server facility
FACILITY Master;           // Declaration of CSIM Master Server facility
int drop;				   // Stores dropped requests
int MasterON;			   // Indicates if Server is on or off


//----- Prototypes ------------------------------------------------------------
void generate(double lambda);  // Customer generator
void aqueue(double service_time);         // Assistant single server queue
void mqueue(double service_time);         // Master single server queue
void mastercontroller();			//epoch generator
//=============================================================================
//==  Main program                                                           ==
//=============================================================================

void sim(int argc, char ** argv)
{
  double   lambda;      // Mean arrival rate (cust/sec)
  // Create the simulation
  create("sim");
  
  // CSIM initializations
  Assistant = facility("Assistant Server");
  Master = facility("Master Server");
  
  // Parameter initializations
  lambda = 1.0;
  drop = 0;
  MasterON = 1;
  // Output begin-of-simulation banner
  printf("*** BEGIN SIMULATION *** \n");
  
  // Initiate generate function and hold for SIM_TIME
  mastercontroller();
  generate(lambda);
  hold(SIM_TIME);
  
  // Output results
  printf("============================================================= \n");
  printf("==  *** CSIM time redirected queueing system simulation ***== \n");
  printf("============================================================= \n");
  printf("= Lambda   = %6.3f cust/sec   \n", lambda);
  printf("============================================================= \n");
  printf("= Total CPU time     = %6.3f sec      \n", cputime());
  printf("= Total sim time     = %6.3f sec      \n", clock);
  printf("= Total completions  = %ld cust       \n", completions(Master));
  printf("=------------------------------------------------------------ \n");
  printf("= >>> Simulation results for Assistant                      - \n");
  printf("=------------------------------------------------------------ \n");
  printf("= Utilization        = %6.3f %%       \n", 100.0 * util(Assistant));
  printf("= Mean num in system = %6.3f cust     \n", qlen(Assistant));
  printf("= Mean response time = %6.3f sec      \n", resp(Assistant));
  printf("= Mean service time  = %6.3f sec      \n", serv(Assistant));
  printf("= Mean throughput    = %6.3f cust/sec \n", tput(Assistant));
  printf("=------------------------------------------------------------ \n");
  printf("= >>> Simulation results for Master                         - \n");
  printf("=------------------------------------------------------------ \n");
  printf("= Utilization        = %6.3f %%       \n", 100.0 * util(Master));
  printf("= Mean num in system = %6.3f cust     \n", qlen(Master));
  printf("= Mean response time = %6.3f sec      \n", resp(Master));
  printf("= Mean service time  = %6.3f sec      \n", serv(Master));
  printf("= Mean throughput    = %6.3f cust/sec \n", tput(Master));
  printf("= Dropped Requests   = %6.3d requests \n", drop);
  printf("============================================================= \n");
  
  // Output end-of-simulation banner
  printf("*** END SIMULATION *** \n");
}
  
  //=============================================================================
//==  Function to generate Poisson customers                                 ==
//=============================================================================
void generate(double lambda)
{
  double   interarrival_time;    // Interarrival time to next send
  double   service_time;         // Service time for this customer

  create("generate");

  // Loop forever to create customers
  while(1)
  {
    // Pull an interarrival time and hold for it
    interarrival_time = exponential(1.0 / lambda);
    hold(interarrival_time);

    // Pull a service time and then send the customer to the queue
    service_time = (SERV_TIMEA);
    aqueue(service_time);
  }
}
  
//=============================================================================
//==  Function for single server queue                                       ==
//=============================================================================
void aqueue(double service_time)
{
  create("aqueue");

  // Reserve, hold, and release server
  reserve(Assistant);
  hold(service_time);
  release(Assistant);
   
  if (MasterON == 1)
  {
	mqueue(SERV_TIMEM);
  }
  else
  {
	hold(DELAY);
	if (MasterON == 1)
	{
		mqueue(SERV_TIMEM);
	}
	else
	{	
		hold(DELAY);
		if (MasterON == 1)
		{
			mqueue(SERV_TIMEM);
		}
	}
  }
}  
  
//=============================================================================
//==  Function for single Master server queue                                       ==
//=============================================================================
void mqueue(double service_time)
{
  if(MasterON == 0 || qlength(Master)>49)
  {
	drop++;
  }
  else
  {
	create("mqueue");
	// Reserve, hold, and release server
	reserve(Master);
	hold(service_time);
	release(Master);
  }
}  
  
//=============================================================================
//==  Function to create Master epochs                                       ==
//=============================================================================  
 void mastercontroller()
{
  create("MST");

  // alternates between sleep and wake cycles
  while(1)
  {
	hold(TSERV);
	MasterON = 0;
	hold(T_NOT_SERV);
	MasterON = 1;
  }
} 
  
  
  
  
  
  
  
  
  
  
  