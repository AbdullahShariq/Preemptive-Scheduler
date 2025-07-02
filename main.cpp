#include "Pre-emptiveScheduler.h"

int menu() {
    int choice;
 //   system("clear");
    cout << "\n-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "\t\tOS Project by M.Abdullah Shariq (22K-4497) " << endl;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    cout << "\n\n\t\tPREEMPTIVE SCHEDULER\n";
    cout << "\n\n\t\tPress 1 for Round Robin Scheduling.\n";
    cout << "\t\tPress 2 for Shortest Remaining Time First Scheduling.\n";
    cout << "\t\tPress 3 for Priority Scheduling.\n";
    cout << "\t\tPress 4 to exit Scheduler.\n";
    cout << "\t\tEnter: ";
    cin >> choice;
    cout << "-----------------------------------------------------------------------------------------------------------" << endl;
    return choice;
}

int main() {
    string filename;
    string filename1="data_set0.txt";
    string filename2="data_set1.txt";
    Process* processes;
    int quantumTime;
    int numProcesses;
    int choice = menu();
  
    do {
    if( choice >=1 && choice <=5) 
       {
        int x; 
        cout << "\nEnter file (1 for same arrival time,2 for different arrival times): ";
        cin >>x ;
        if(x==1) filename=filename1;else filename=filename2; 
     }
        else cout<<"\nInvalid choice"<<endl;
        if (choice == 1) {
            processes = getInputs(choice,&numProcesses, filename,&quantumTime);
            roundRobin(processes, numProcesses,quantumTime);
                    displayCalculations(processes, numProcesses);   
        } else if (choice == 2) {
            processes = getInputs(choice,&numProcesses, filename,NULL);
            SRTF(processes, numProcesses);
                    displayCalculations(processes, numProcesses);   
        } else if (choice == 3) {
            processes = getInputs(choice,&numProcesses, filename,&quantumTime);
            if (!checkifSamePriority(processes, numProcesses))
                prioritySchedulerA(processes, numProcesses);
            else
                prioritySchedulerB(processes, numProcesses,quantumTime);
                        displayCalculations(processes, numProcesses);   
        }
        choice = menu();
    } while (choice != 4);
    
    delete[] processes;
}

