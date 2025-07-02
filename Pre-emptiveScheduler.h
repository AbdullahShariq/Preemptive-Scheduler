#ifndef PREEMPTIVESCHEDULER_H
#define PREEMPTIVESCHEDULER_H

#include "Process.h"
#include "RoundRobin.h"
#include "SRTF.h"
#include "PriorityScheduler.h"
#include <fstream>
#include <cstdlib> 
#include <ncurses.h>
 
Process* getInputs(int,int*,string,int*a);
bool checkifSamePriority(Process*,int);
void displayCalculations(Process*,int);

#endif


