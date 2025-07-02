#include "RoundRobin.h"


void roundRobin(Process *processes, int numProcesses,int quantumTime )
{
    int timer = 0;
    bool completionCheck = false;
    cout<<"\nQuantum time: "<<quantumTime<<endl<<endl;
    cout<<"\n\nPID\tPrev Timer\tNew Timer\tPriority"<<endl;
 
    
    int * inCPU=new int[numProcesses]{0};
    while (!completionCheck)
    {
    	if(noProcessinCPU(processes,numProcesses,&timer)) continue;

        for (int i = 0; i < numProcesses; i++)
        {
        	int prevTime=timer;
        	if(processes[i].arrivalTime > timer) continue;
            if (processes[i].remainingTime == 0)
            {
                processes[i].status = true;
            }
            else if (processes[i].remainingTime > 0)
            {
                completionCheck = false;
                 if(inCPU[i] == 0)
                   processes[i].responseTime=prevTime;
                if (processes[i].remainingTime >= quantumTime)
                {
                    processes[i].remainingTime -= quantumTime;
                    timer += quantumTime;
                    processes[i].waitingTime= prevTime-processes[i].arrivalTime-( inCPU[i] * quantumTime);
                    processes[i].turnAroundTime=timer-processes[i].arrivalTime;
                }
                else
                {
                    timer += processes[i].remainingTime;
                    processes[i].remainingTime = 0;
                    processes[i].waitingTime= prevTime-processes[i].arrivalTime-( inCPU[i] * quantumTime);
                    processes[i].turnAroundTime=timer-processes[i].arrivalTime;
                }

                cout<<processes[i].processID << "\t" << prevTime<<"\t\t"<<timer<<"\t\t-"<<endl;
                inCPU[i]++;
         
            }
           
        }
        completionCheck=allCompleted(processes,numProcesses);
       // delete[] inCPU;
}
}
