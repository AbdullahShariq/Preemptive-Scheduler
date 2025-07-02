#include "PriorityScheduler.h"
#include<limits.h>
#include<vector>

int QUANTUM_TIME;

int method;
bool comparePriorityGroups(const vector<int>& group1, const vector<int>& group2) {
if(method == 0 )
    return group1[0] > group2[0]; // Compare based on priority number (first element)
else return group1[0] < group2[0];
}

bool isDifferent(vector<vector<int>> newGroups, vector<vector<int>> oldGroups) {
    return newGroups == oldGroups;
}

bool groupExecuted(Process* processes, vector<int> group, bool* marked) {
    bool flag = true;
    for (int i = 1; i < group.size(); i++) {
        if (!processes[group[i]].status) {
            marked[i] = false;
            flag = false;
        }
    }
    return flag;
}

void roundRobinPriority(Process* processes, int numProcesses, vector<vector<int>> allGroups, vector<int> group, int* inCPU, int* timer, bool* marked) {
    for (int i = 1; i < group.size(); i++) {
        int prevTime = *timer;
        int processIndex = group[i];
        if (processes[processIndex].status) continue;
        if (inCPU[processIndex] == 0)
            processes[processIndex].responseTime = prevTime;
        for (int j = 0; j < QUANTUM_TIME && processes[processIndex].remainingTime > 0; j++) {
            processes[processIndex].remainingTime--;
            (*timer)++;
            cout << processes[processIndex].processID << "\t" << prevTime << "\t\t" << *timer << "\t\t" << processes[processIndex].priorityNumber << endl;
            if (ifHigherPriority(processes, numProcesses, *timer, processes[processIndex].priorityNumber)) return;
            prevTime = *timer;
        }
        if (processes[processIndex].remainingTime == 0) {
            processes[processIndex].status = true;
            processes[processIndex].waitingTime = prevTime - processes[processIndex].arrivalTime - (inCPU[processIndex] * QUANTUM_TIME);
            processes[processIndex].turnAroundTime = (*timer) - processes[processIndex].arrivalTime;
        }
        inCPU[processIndex]++;
    }
}

void normalExecution(Process* processes, int numProcesses, vector<vector<int>> allGroups, vector<int> group, int* inCPU, int* timer, bool* marked, int* index) {
    int startingTimer = *timer;
    int prevCpuUse = inCPU[group[1]];
    do {
        if (inCPU[group[1]] == 0) processes[group[1]].responseTime = *timer;
        (*timer)++;
        processes[group[1]].remainingTime--;
        if (processes[group[1]].remainingTime == 0) {
            processes[group[1]].status = true;
            processes[group[1]].waitingTime = startingTimer - processes[group[1]].arrivalTime - prevCpuUse;
            processes[group[1]].turnAroundTime = *timer - processes[group[1]].arrivalTime;
            (*index)++;
        }
        if (*index >= allGroups.size()) {
            cout << processes[group[1]].processID << "\t" << startingTimer << "\t\t" << *timer << "\t\t" << processes[group[1]].priorityNumber << endl;
            inCPU[group[1]]++;
        } else {
            cout << processes[group[1]].processID << "\t" << startingTimer << "\t\t" << *timer << "\t\t" << processes[group[1]].priorityNumber << endl;
            inCPU[group[1]]++;
        }
        startingTimer = *timer;
        if (ifHigherPriority(processes, numProcesses, *timer, processes[group[1]].priorityNumber)) return;
    } while (!isDifferent(getGroups(processes, numProcesses, *timer, marked), allGroups) && *index < allGroups.size() && processes[group[1]].status == false);
}

vector<vector<int>> getGroups(Process* processes, int numProcesses, int currentTime, bool* marked) {
    for (int i = 0; i < numProcesses; i++)
        marked[i] = false;
    vector<vector<int>> GROUPS;
    for (int i = 0; i < numProcesses; i++) {
        if (processes[i].arrivalTime > currentTime || processes[i].status) continue;
        if (!marked[i]) {
            vector<int> group;
            group.push_back(processes[i].priorityNumber);
            group.push_back(i);
            marked[i] = true;
            for (int j = i + 1; j < numProcesses; j++) {
                if (processes[i].priorityNumber == processes[j].priorityNumber && !marked[j]) {
                    group.push_back(j);
                    marked[j] = true;
                }
            }
            GROUPS.push_back(group);
        }
    }
    sort(GROUPS.begin(), GROUPS.end(), comparePriorityGroups);
    return GROUPS;
}

int getHighestPriorityProcess(Process* processes, int numProcesses, int currentTime) {
//cout<<"in"<<endl;
    int highest;
    if(method == 1 ) highest = INT_MAX;
    else highest= INT_MIN;
    int index;
    for (int i = 0; i < numProcesses; i++) {
        if (processes[i].status || processes[i].arrivalTime > currentTime) continue;
        if(method == 1){
        if (processes[i].priorityNumber < highest) {
            highest = processes[i].priorityNumber;
            index = i;
        }}
        else {
         if(processes[i].priorityNumber > highest) {
            highest = processes[i].priorityNumber;
            index = i;
        }}
    }
   // cout<<processes[index].priorityNumber<<endl;
    return index;
}

void prioritySchedulerA(Process* processes, int numProcesses) {
            cout<<"Choose priority method( reverse (0) / normal (1) ): ";
            cin>>method;
    int timer = 0;
    bool completionCheck = false;
    cout << "PID\tPrev Timer\tNew Timer\tPriority" << endl;
    int *inCPU = new int[numProcesses]{0};
    while (!completionCheck) {
        if (noProcessinCPU(processes, numProcesses, &timer)) continue;
        int prevTime = timer;
        int highestPriority = getHighestPriorityProcess(processes, numProcesses, timer);
        int startingTimer = timer;
        int prevCpuUse = inCPU[highestPriority];
        if (inCPU[highestPriority] == 0) processes[highestPriority].responseTime = timer;
        while (getHighestPriorityProcess(processes, numProcesses, timer) == highestPriority) {
            processes[highestPriority].remainingTime--;
            timer++;
            inCPU[highestPriority]++;
            if (processes[highestPriority].remainingTime == 0) {
                processes[highestPriority].status = true;
                processes[highestPriority].waitingTime = startingTimer - processes[highestPriority].arrivalTime - prevCpuUse;
                processes[highestPriority].turnAroundTime = timer - processes[highestPriority].arrivalTime;
                break;
            }
        }
        cout << processes[highestPriority].processID << "\t" << prevTime << "\t\t" << timer << "\t\t" << processes[highestPriority].priorityNumber << endl;
        completionCheck = allCompleted(processes, numProcesses);
    }
   // delete[] inCPU;
}

void prioritySchedulerB(Process* processes, int numProcesses,int qt) {
            cout<<"Choose priority method( reverse (0) / normal (1) ): ";
            cin>>method;
            
    QUANTUM_TIME =qt;
    bool *marked = new bool[numProcesses]{false};
    bool completionCheck = false;
    int timer = 0;
    cout << "\n\nPID\tPrev Timer\tNew Timer\tPriority" << endl;
    int *inCPU = new int[numProcesses]{0};
    while (!completionCheck) {
        if (noProcessinCPU(processes, numProcesses, &timer)) continue;
        vector<vector<int>> priorityGroupsIndexes = getGroups(processes, numProcesses, timer, marked);
        int index = 0;
        do {
            if (index < priorityGroupsIndexes.size()) {
                if (priorityGroupsIndexes[index].size() == 2) {
                    normalExecution(processes, numProcesses, priorityGroupsIndexes, priorityGroupsIndexes[index], inCPU, &timer, marked, &index);
                } else {
                    roundRobinPriority(processes, numProcesses, priorityGroupsIndexes, priorityGroupsIndexes[index], inCPU, &timer, marked);
                    if (groupExecuted(processes, priorityGroupsIndexes[index], marked)) {
                        index++;
                    }
                }
            }
        } while (!isDifferent(getGroups(processes, numProcesses, timer, marked), priorityGroupsIndexes) && index < priorityGroupsIndexes.size() && !ifHigherPriority(processes, numProcesses, timer, priorityGroupsIndexes[index][0]));
        completionCheck = allCompleted(processes, numProcesses);
    }
   // delete[] marked;
   // delete[] inCPU;
}


