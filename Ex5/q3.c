/*
3. Consider a junction of road where 4 roads meet at this junction, every often
there is a problem of jamming of vehicles at this junction. To overcome this 
problem a traffic signal was planned to be installed at the signal. The 
operation of the signal is planned in such a way that, the vehicles in each lane
of the road will be allowed only for 3 minutes and then stopped. The chance will
be given to next lane of the road. write a c program implement a scheduling 
algorithm to illustrate how the vehicles crossed the junction with the minimum
waiting time. Calculate average waiting time and average turnaround time, 
dislpay gant chart and all results on screen.(busttime = #vehicles)
*/
#include <stdio.h>
#define TimeQuantum 3


int main(){
    int road[4] = {0,0,0,0};
    int turn = 0;
    int time,ttime = 0;
    int wait[4] = {0,0,0,0};
    int tot[4] = {0,0,0,0};
    
    for(int i =0;i<4;i++){
        printf("Enter number of vehicles in road %d: ",i);
        scanf("%d",&road[i]);
    }
    //printf("10 vehicles cross the junction in 1 min.\nScheduling...");
    //printf("sum=%d\n",road[0]+road[1]+road[2]+road[3]);
    
    while((road[0]+road[1]+road[2]+road[3])>0){
        printf(">Time %d\t Road %d\t Vehicles %d",ttime,turn,road[turn]);
        
        road[turn]-=10;
        if(road[turn]<=0){
            //road[turn] = 0;
            printf("\t>>Road %d empty.",turn);
        }
        printf("\n");
        
        for(int i=0;i<4;i++){
            if(road[i]!=0){
                if(i!=turn){
                    wait[i]++;
                }
                tot[i]++;
            }
        }
        
        time++;
        ttime++;
        
        if((time == TimeQuantum) || (road[turn]<=0)){
            printf(">>Switching light>> Road %d remaining cars %d.\n",turn,road[turn]);
            do{
                time = 0;
                turn = (turn+1)%4;
            }while((road[turn]<=0) && (road[0]+road[1]+road[2]+road[3]>0));
        }
        
    }
    printf("\nLane\t\t Waiting time\t\tTurnaround time\n");
    for(int i=0; i<4; i++){
        printf("%d\t\t\t%d\t\t\t%d\n",i,wait[i],tot[i]);
    }

}






#include <stdio.h>

#define NumLanes 4
#define QuantumTime 3
#define VehiclesPerMinute 10

void simulateTrafficSignal(int lanes[], int n, int quantum) {
    int time = 0, totalVehicles = 0;
    int wait[n], turnaround[n];

    for (int i = 0; i < n; i++) {
        wait[i] = 0;
        turnaround[i] = 0;
        totalVehicles += lanes[i];
    }

    printf("Gantt Chart:\n");

    while (totalVehicles > 0) {
        int laneIndex = time % n;

        if (lanes[laneIndex] > 0) {
            int vehiclesCrossed = (lanes[laneIndex] >= VehiclesPerMinute * quantum) ? VehiclesPerMinute * quantum : lanes[laneIndex];
            lanes[laneIndex] -= vehiclesCrossed;
            totalVehicles -= vehiclesCrossed;

            wait[laneIndex] += time;
            turnaround[laneIndex] = wait[laneIndex] + vehiclesCrossed;
            
            printf("Lane %d: %d - %d\n", laneIndex + 1, time, time + quantum);
        }

        time += quantum;
    }

    printf("\nLane\tWaiting Time\tTurnaround Time\n");
    float avgWait = 0, avgTurnaround = 0;
    for (int i = 0; i < n; i++) {
        printf("%d\t%d\t\t%d\n", i + 1, wait[i], turnaround[i]);
        avgWait += wait[i];
        avgTurnaround += turnaround[i];
    }

    avgWait /= n;
    avgTurnaround /= n;

    printf("\nAverage Waiting Time: %.2f minutes\n", avgWait);
    printf("Average Turnaround Time: %.2f minutes\n", avgTurnaround);
}

int main() {
    int lanes[NumLanes];
    printf("Enter the number of vehicles in each lane:\n");
    for (int i = 0; i < NumLanes; i++) {
        printf("Lane %d: ", i + 1);
        scanf("%d", &lanes[i]);
    }

    printf("\nSimulation Results:\n");
    simulateTrafficSignal(lanes, NumLanes, QuantumTime);

    return 0;
}
