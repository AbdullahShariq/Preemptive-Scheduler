# Preemptive Scheduler

This repository contains a C++ implementation of a **Preemptive Scheduler** that simulates three preemptive CPU scheduling algorithms: **Round Robin (RR)**, **Shortest Remaining Time First (SRTF)**, and **Priority Scheduling**. The program reads process details (arrival time, burst time, and priority) from input files and generates a Gantt chart along with performance metrics such as waiting time, turnaround time, and response time for each process.

---

## Overview
The Preemptive Scheduler is designed to demonstrate the behavior of preemptive CPU scheduling algorithms used in operating systems. It supports:
- **Round Robin (RR)**: Processes are executed in a time-sliced manner with a user-defined quantum time.
- **Shortest Remaining Time First (SRTF)**: The process with the shortest remaining burst time is executed first, with preemption if a shorter process arrives.
- **Priority Scheduling**: Processes are executed based on priority, with two modes:
  - **Non-identical priorities**: Executes the process with the highest (or lowest) priority.
  - **Identical priorities**: Applies Round Robin scheduling within groups of processes with the same priority.

The program reads process data from text files (e.g., `data_set0.txt`, `data_set1.txt`, `new.txt`) and outputs a Gantt chart showing the execution timeline, followed by a table of performance metrics (waiting time, turnaround time, and response time) for each process, along with their averages.

---

## Features
- Supports three preemptive scheduling algorithms: Round Robin, SRTF, and Priority Scheduling.
- Handles processes with same or different arrival times.
- Provides a menu-driven interface for selecting the scheduling algorithm and input file.
- Generates a Gantt chart for visualizing process execution.
- Calculates and displays waiting time, turnaround time, and response time for each process.
- Supports priority scheduling with two modes: normal (lower priority number = higher priority) and reverse (higher priority number = higher priority).
- Includes sample input files for testing (`data_set0.txt`, `data_set1.txt`, `new.txt`).

---

## Prerequisites
To compile and run the Preemptive Scheduler, you need:
- A C++ compiler (e.g., `g++`).
- A Unix-like environment (Linux, macOS, or Windows with WSL) for using the provided `makefile`.
- The `ncurses` library for console display (included in `Pre-emptiveScheduler.h`).
- Basic knowledge of operating system scheduling concepts to understand the output.

---

## Installation
1. **Clone the repository**:
   ```bash
    git clone https://github.com/AbdullahShariq/Preemptive-Scheduler.git
    cd Preemptive-Scheduler
   ```

2. **Compile the program**:
   Use the provided `makefile` to compile the source code:
   ```bash
   make
   ```
   This will generate an executable named `output`.

3. **Install dependencies** (if needed):
   Ensure the `ncurses` library is installed. On Ubuntu/Debian, run:
   ```bash
   sudo apt-get install libncurses5-dev libncursesw5-dev
   ```

4. **Clean build artifacts** (optional):
   To remove object files and the executable, run:
   ```bash
   make clean
   ```

---

## Usage
1. **Run the program**:
   ```bash
   ./output
   ```

2. **Select a scheduling algorithm**:
   - The program displays a menu:
     ```
     PREEMPTIVE SCHEDULER
     Press 1 for Round Robin Scheduling.
     Press 2 for Shortest Remaining Time First Scheduling.
     Press 3 for Priority Scheduling.
     Press 4 to exit Scheduler.
     Enter:
     ```
   - Enter a number (1–4) to choose an algorithm or exit.

3. **Select an input file**:
   - Enter `1` for `data_set0.txt` (processes with same arrival times) or `2` for `data_set1.txt` (processes with different arrival times).
   - For Priority Scheduling, select the priority method: `0` (reverse, higher number = higher priority) or `1` (normal, lower number = higher priority).

4. **View output**:
   - The program displays a Gantt chart showing the execution timeline (process ID, previous timer, new timer, and priority).
   - A table of calculations follows, showing each process’s arrival time, burst time, waiting time, turnaround time, and response time, along with averages.

---

## Input File Format
The input files (`data_set0.txt`, `data_set1.txt`, `new.txt`) follow this format:
- **First line**: Two integers, `N Q`, where `N` is the number of processes and `Q` is the quantum time (used for Round Robin and Priority Scheduling with identical priorities).
- **Subsequent lines**: For each of the `N` processes, three integers: `arrival_time burst_time priority`.
  - `arrival_time`: When the process arrives (non-negative integer).
  - `burst_time`: CPU time required by the process (positive integer).
  - `priority`: Priority number (used in Priority Scheduling; lower number = higher priority in normal mode).

---

## File Structure
The repository contains the following files:
- **Source Files**:
  - `main.cpp`: Entry point with the menu-driven interface and scheduling algorithm selection.
  - `Process.cpp`, `Process.h`: Defines the `Process` class to store process attributes (arrival time, burst time, priority, etc.).
  - `RoundRobin.cpp`, `RoundRobin.h`: Implements the Round Robin scheduling algorithm.
  - `SRTF.cpp`, `SRTF.h`: Implements the Shortest Remaining Time First scheduling algorithm.
  - `PriorityScheduler.cpp`, `PriorityScheduler.h`: Implements Priority Scheduling with support for identical and non-identical priorities.
  - `Pre-emptiveScheduler.cpp`, `Pre-emptiveScheduler.h`: Handles input file parsing, priority checking, and performance metric calculations.
  - `CPUfunctions.cpp`, `CPUfunctions.h`: Utility functions for checking CPU status and process completion.
- **Input Files**:
  - `data_set0.txt`: Sample input with processes having the same arrival time.
  - `data_set1.txt`: Sample input with processes having different arrival times.
  - `new.txt`: Additional sample input with 5 processes.
- **Build Files**:
  - `makefile`: Automates compilation of the program.
- **Generated Files** (not in repository):
  - `Pre-emptiveScheduler.h.gch`, `Process.h.gch`: Precompiled headers (generated during compilation).
  - Object files (e.g., `main.o`, `Process.o`) and the `output` executable.
