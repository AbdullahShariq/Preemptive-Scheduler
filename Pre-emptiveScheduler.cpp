#include "Pre-emptiveScheduler.h"

Process * getInputs(int choice,int * numProcesses,string filename,int * quantumTime  )
{ 
    ifstream inputFile(filename);
    Process * processes;
    if (!inputFile.is_open())
    {
        cerr << "Error: Unable to open file " << filename << endl;
        return NULL;
    }
    
    int num,x; 
    inputFile >> num >> x;
    *numProcesses = num;
    processes = new Process[*numProcesses];
    if(choice == 1 || choice == 3 )
       {
           *quantumTime = x;
       //    cout<< *quantumTime<<endl;      
       }
 
    for (int i = 0; i < *numProcesses; i++)
    {
        int arrival, burst ,priority;
        string id = "P" + to_string(i);
        inputFile >> arrival >> burst>>priority;
        if(choice == 1 || choice == 2 )
        processes[i] = Process(arrival, burst, id);
        else processes[i] = Process(arrival, burst, priority ,id);
    }

    inputFile.close();
    cout<<"\n---------------------------------------------------------------------------------------"<<endl;
cout<<"\t\tGantt Chart"<<endl;
cout<<"---------------------------------------------------------------------------------------"<<endl;
    return processes;
}

bool checkifSamePriority(Process* processes, int numProcesses)
{
   for(int i=0 ; i <numProcesses ;i++)
   {
     for(int j=i+1; j <numProcesses;j++)
     {
         if(processes[i].priorityNumber == processes[j].priorityNumber)
          return true;
     }     
   }
   return false;

}


void displayCalculations(Process * processes ,int numProcesses)
{
cout<<"\n---------------------------------------------------------------------------------------"<<endl;
cout<<"\t\tDisplaying Calculations"<<endl;
cout<<"---------------------------------------------------------------------------------------"<<endl;
	int totalWaiting=0,totalTurn=0,totalResponse=0;
	cout<<endl<<endl<<"PID\tArrival Time\tBurst Time\tWaiting Time\tTurn Around Time\tResponse Time"<<endl;
	for(int i = 0 ; i < numProcesses ; i++)
	{
		cout<<processes[i].processID<<"\t"<<processes[i].arrivalTime<<"\t\t"<<processes[i].burstTime<<"\t\t"<<processes[i].waitingTime<<"\t\t"
		<<processes[i].turnAroundTime<<"\t\t\t"<<processes[i].responseTime<<endl;
		totalWaiting+=processes[i].waitingTime;
		totalTurn+=processes[i].turnAroundTime;
		totalResponse+=processes[i].responseTime;
	}
	
	cout<<"\n\nAverage waiting time: "<<(float)totalWaiting/numProcesses<<endl;
	cout<<"Average turn around time: "<<(float)totalTurn/numProcesses<<endl;
	cout<<"Average response time: "<<(float)totalResponse/numProcesses<<endl;


}
