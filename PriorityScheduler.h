#ifndef PRIORITYSCHEDULING_H
#define PRIORITYSCHEDULING_H

#include "Process.h"
#include <iostream>
#include <algorithm>
#include <limits.h>
#include "CPUfunctions.h"
using namespace std;

int getHighestPriorityProcess(Process*,int,int);
void prioritySchedulerA(Process*,int);
void prioritySchedulerB(Process*,int,int);
bool comparePriorityGroups(const vector<int>&,const vector<int>&);
vector<vector<int>> getGroups(Process*,int,int,bool*);
bool isDifferent(vector<vector<int>>,vector<vector<int>>);
void roundRobinPriority(Process*,int,vector<vector<int>>,vector<int>,int*,int*,bool*);
bool groupExecuted(Process*,vector<int>,bool*);
void normalExecution(Process*,int,vector<vector<int>>,vector<int>,int*,int*,bool*,int*);
#endif


