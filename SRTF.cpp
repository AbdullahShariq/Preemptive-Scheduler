#include "SRTF.h"

int getShortestProcess(Process* processes ,int numProcesses,int currentTime)
{
	int shortestTime=INT_MAX;
        int index;
        
        for(int i=0 ; i < numProcesses ; i++)
        {
            if(processes[i].status || processes[i].arrivalTime > currentTime) continue;
            if(processes[i].remainingTime < shortestTime)
            {
               shortestTime=processes[i].remainingTime;
               index=i;
            }
        }
        return index;
}

void SRTF(Process *processes, int numProcesses)
{
    int timer = 0;
    bool completionCheck = false;
    cout << "\n\nPID\tPrev Timer\tNew Timer\tPriority" << endl;

    int *inCPU = new int[numProcesses]{0};

    // Continue until all processes have completed
    while (!completionCheck)
    {
    	if(noProcessinCPU(processes,numProcesses,&timer)) continue;

        int prevTime = timer;
        int shortest = getShortestProcess(processes, numProcesses, timer);
        // Continue execution while the current shortest process remains the same
        int startingTimer=timer;
        int prevCpuUse=inCPU[shortest];
        if(inCPU[shortest] == 0 ) processes[shortest].responseTime=timer;
        while (getShortestProcess(processes, numProcesses, timer) == shortest)
        {
            processes[shortest].remainingTime--;
            timer++;
            inCPU[shortest]++;
            if(processes[shortest].remainingTime == 0)
            {
               processes[shortest].status=true;
               processes[shortest].waitingTime= startingTimer - processes[shortest].arrivalTime- prevCpuUse;
               processes[shortest].turnAroundTime= timer - processes[shortest].arrivalTime;
               break;
            }
        }
        cout << processes[shortest].processID << "\t" << prevTime << "\t\t" << timer << "\t\t-"<<endl;

        // Check if all processes have completed
        completionCheck = allCompleted(processes,numProcesses);
    }
    
   // delete[] inCPU;
}



