#include "CPUfunctions.h"

bool noProcessinCPU(Process* processes, int numProcesses, int *timer) {
    for(int i = 0; i < numProcesses; i++) {
        if(processes[i].arrivalTime <= *timer)
            return false;
    }
    // If no process arrived yet, print CPU idle and increment timer
    cout << "idle\t" << *timer << "\t\t" << ++(*timer) <<"\t\t-"<< endl;
    return true;
}

bool allCompleted(Process* processes,int numProcesses){
    for(int i=0; i<numProcesses;i++){
        if(processes[i].status == false)
          return false;
    }
    return true;
}

bool ifHigherPriority(Process* processes, int numProcesses, int timer, int priorityCurrent) {
    for(int i = 0; i < numProcesses; i++) {
            if (processes[i].arrivalTime <= timer && !processes[i].status && processes[i].priorityNumber < priorityCurrent) {
                
                return true;
        }
    }
    return false;
}
