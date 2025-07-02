#ifndef CPUUTIL_H
#define CPUUTIL_H

#include<vector>
#include "Process.h"
#include <iostream>
using namespace std;

bool noProcessinCPU(Process* processes, int numProcesses, int *timer);
bool allCompleted(Process*,int);
bool ifHigherPriority(Process*,int,int,int);

#endif // CPUUTIL_H

