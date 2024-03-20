/*
1. Consider a ticket counter in a railway station where the people waits in a queue for booking the ticket. 
   The person who arrives first in the queue can buy the ticket first and then the next person, this continues 
   until the queue becomes empty.The order of arrival of a person in the queue decides their chance to buy the 
   ticket.Write a program in C to implement an appropriate scheduling algorithm to calculate the average waiting 
   time and average turn around time,taken by the person in the queue for the booking process. Display the ghant 
   chart to represent the order of the person in the queue and also waiting time and turnaround time for each person.
*/

//First Come First Serve

#include<stdio.h>

struct Process {

    int Pnum;
    int burstTime;
    int arrivalTime;
    int waitingTime;
    int turnaroundTime;
};

int main() {
    int n, i, j;
    float averageWaitingTime = 0.0, averageTurnaroundTime = 0.0;

    printf("Enter the total number of people: ");
    scanf("%d", &n);

    struct Process processes[n];

    printf("Enter Process Burst Time\n");                 
    for(i=0;i<n;i++)
    {   
        processes[i].Pnum = i+1;
        printf("P[%d]:",processes[i].Pnum);
        scanf("%d",&processes[i].burstTime);
    }
    
    printf("\nEnter the Arrival Time\n");
    for(i=0;i<n;i++){
        printf("P[%d]:",processes[i].Pnum);
        scanf("%d",&processes[i].arrivalTime);
    }

    // Sort the processes based on arrival time
    for(i = 0; i < n-1; i++) {
        for(j = 0; j < n-i-1; j++) {
            if(processes[j].arrivalTime > processes[j+1].arrivalTime) {
                struct Process temp = processes[j];
                processes[j] = processes[j+1];
                processes[j+1] = temp;
            }
        }
    }

    processes[0].waitingTime = 0;

    // Calculate waiting time for each process
    for(i = 1; i < n; i++) {
        processes[i].waitingTime = 0;
        for(j = 0; j < i; j++) {
            processes[i].waitingTime += processes[j].burstTime;
        }
        processes[i].waitingTime -= processes[i].arrivalTime;
    }

    printf("\nProcess\t\tArrival Time\tBurst Time\tWaiting Time\tTurnaround Time\n");

    // Calculate turnaround time and display process details
    for(i = 0; i < n; i++) {
        processes[i].turnaroundTime = processes[i].burstTime + processes[i].waitingTime;
        averageWaitingTime += processes[i].waitingTime;
        averageTurnaroundTime += processes[i].turnaroundTime;
        printf("P[%d]\t\t%d\t\t%d\t\t%d\t\t%d\n", processes[i].Pnum , processes[i].arrivalTime, processes[i].burstTime, processes[i].waitingTime, processes[i].turnaroundTime);
    }

    averageWaitingTime /= n;
    averageTurnaroundTime /= n;
    printf("\nAverage Waiting Time: %.2f", averageWaitingTime);
    printf("\nAverage Turnaround Time: %.2f", averageTurnaroundTime);
    printf("\n\nGantt Chart:\n");
    printf("__________________________________________\n");
    printf("|");

    for(i = 0; i < n; i++) {
        printf("| P[%d] |", processes[i].Pnum);
    }
    printf("|\n");
    printf("__________________________________________\n");

    return 0;
}
