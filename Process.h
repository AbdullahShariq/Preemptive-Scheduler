#ifndef PROCESS_H
#define PROCESS_H

#include<iostream>
using namespace std;

class Process
{
public:
	string processID;
	int arrivalTime;
	int burstTime;
	int waitingTime;
	int turnAroundTime;
	int responseTime;
	int remainingTime;
	bool status;
	int priorityNumber;
		bool inQueue;
	int queueTime;
	Process(int,int,string);
	Process(int,int,int,string);
	Process();
	
};

#endif


