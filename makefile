output: main.o Process.o RoundRobin.o SRTF.o Pre-emptiveScheduler.o PriorityScheduler.o CPUfunctions.o 
	g++ main.o Process.o RoundRobin.o SRTF.o Pre-emptiveScheduler.o PriorityScheduler.o CPUfunctions.o -o output 

main.o: main.cpp Pre-emptiveScheduler.h PriorityScheduler.h CPUfunctions.h 
	g++ -c main.cpp -o main.o

Process.o: Process.cpp Process.h
	g++ -c Process.cpp -o Process.o

RoundRobin.o: RoundRobin.cpp RoundRobin.h Process.h CPUfunctions.h
	g++ -c RoundRobin.cpp -o RoundRobin.o

SRTF.o: SRTF.cpp SRTF.h Process.h CPUfunctions.h
	g++ -c SRTF.cpp -o SRTF.o

Pre-emptiveScheduler.o: Pre-emptiveScheduler.cpp Pre-emptiveScheduler.h Process.h RoundRobin.h SRTF.h PriorityScheduler.h CPUfunctions.h 
	g++ -c Pre-emptiveScheduler.cpp -o Pre-emptiveScheduler.o

PriorityScheduler.o: PriorityScheduler.cpp PriorityScheduler.h Process.h CPUfunctions.h
	g++ -c PriorityScheduler.cpp -o PriorityScheduler.o

CPUfunctions.o: CPUfunctions.cpp CPUfunctions.h Process.h
	g++ -c CPUfunctions.cpp -o CPUfunctions.o

clean:
	rm -f *.o output
