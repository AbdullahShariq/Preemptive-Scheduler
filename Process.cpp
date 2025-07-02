#include "Process.h"

Process :: Process(int arrivalTime,int burstTime,string processID)
{
	this->arrivalTime=arrivalTime;
	this->turnAroundTime=this->responseTime=this->waitingTime=this->queueTime=0;
	this->burstTime=this->remainingTime=burstTime;
	this->processID=processID;
	this->status=this->inQueue=false;
}

Process :: Process(){}

Process :: Process(int arrivalTime,int burstTime,int priorityNumber,string processID)
{
	this->arrivalTime=arrivalTime;
	this->turnAroundTime=this->responseTime=this->waitingTime=this->queueTime=0;
	this->burstTime=this->remainingTime=burstTime;
	this->priorityNumber=priorityNumber;
	this->processID=processID;
	this->status=this->inQueue=false;
}


