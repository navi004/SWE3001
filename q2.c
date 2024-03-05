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
    int time,btime = 0;
    int wait[4],tot[4];
    for(int i =0;i<4;i++){
        printf("Enter number of vehicles in road %d: ",i);
        scanf("%d",&road[i]);
    }
    //printf("10 vehicles cross the junction in 1 min.\nScheduling...");
    //printf("sum=%d\n",road[0]+road[1]+road[2]+road[3]);
    
    while((road[0]+road[1]+road[2]+road[3])>0){
        printf(">Time %d\t Road %d\t Vehicles %d",time,turn,road[turn]);
        road[turn]-=10;
        if(road[turn]<=0){
            printf("\t>>Road %d empty.",turn);
        }
        printf("\n");
        
        if(((time%TimeQuantum==0) && (time!=0)) || (road[turn]==0)){
            do{
                turn = (turn+1)%4;
            }while((road[turn]<=0) && (road[0]+road[1]+road[2]+road[3]>0));
        }
        time+=1;
        
    }


}
