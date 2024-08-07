// write a c program to implement dynamic memory allocation technique for the given memory partition sizes 20KB, 100KB, 40KB, 200KB and 10KB 
//for the various processes of size 90KB, 50KB, 30KB and 40KB. Display the allocation of all the processes by applying the algorithms on the screen.
/*
write a c program to implement dynamic memory allocation technique for the given memory partition sizes 20KB, 100KB, 40KB, 200KB and 10KB for the various processes of size 90KB, 50KB, 30KB and 40KB. Display the allocation of all the processes by applying the algorithms on the screen.
*/

#include <stdio.h>

void implimentBestFit(int blockSize[], int blocks, int processSize[], int proccesses)
{
    // This will store the block id of the allocated block to a process
    int allocation[proccesses];
    int occupied[blocks];
    
    // initially assigning -1 to all allocation indexes
    // means nothing is allocated currently
    for(int i = 0; i < proccesses; i++){
        allocation[i] = -1;
    }
    
    for(int i = 0; i < blocks; i++){
        occupied[i] = 0;
    }
 
    // pick each process and find suitable blocks
    // according to its size ad assign to it
    for (int i = 0; i < proccesses; i++)
    {
        
        int indexPlaced = -1;
        for (int j = 0; j < blocks; j++) { 
            if (blockSize[j] >= processSize[i] && !occupied[j])
            {
                // place it at the first block fit to accomodate process
                if (indexPlaced == -1)
                    indexPlaced = j;
                    
                // if any future block is smalller than the current block where
                // process is placed, change the block and thus indexPlaced
		// this reduces the wastage thus best fit
                else if (blockSize[j] < blockSize[indexPlaced])
                    indexPlaced = j;
            }
        }
 
        // If we were successfully able to find block for the process
        if (indexPlaced != -1)
        {
            // allocate this block j to process p[i]
            allocation[i] = indexPlaced;
            
            // make the status of the block as occupied
            occupied[indexPlaced] = 1;
        }
    }
 
    printf("\nProcess No.\tProcess Size\t\t\tBlock Size\n");
    for (int i = 0; i < proccesses; i++)
    {
        printf("%d \t\t\t %d \t\t\t", i+1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n",blockSize[i]);
        else
            printf("Not Allocated\n");
    }
}

 
// Driver code
int main()
{
    int blockSize[] = {20,100,40,200,10};
    int processSize[] = {90,50,30,40};
    int blocks = sizeof(blockSize)/sizeof(blockSize[0]);
    int proccesses = sizeof(processSize)/sizeof(processSize[0]);
    
    printf("Best Fit");
    implimentBestFit(blockSize, blocks, processSize, proccesses);
 
    return 0 ;
}


#include <stdio.h>

void implementBestFit(int blockSize[],int blocks,int processSize[],int processes){
    int allocation[processes];
    int occupied[blocks];
    for(int i=0;i<processes;i++){
        allocation[i] = -1;
    }
    for(int i=0;i<blocks;i++){
        occupied[i] = 0;
    }

    for(int i=0;i<processes;i++){
        int index = -1;
        for(int j=0;j<blocks;j++){
            if(blockSize[j] >= processSize[i] && !occupied[j]){
                if((index == -1)||(blockSize[j] < blockSize[index])){
                    index = j;
                }
            }
        }
        if(index != -1){
            allocation[i] = index;
            occupied[index] = 1;
        }
    }
    printf("Process No.\tProcess Size\tBlock No\n");
    for(int i=0;i<processes;i++){
        printf("%d\t\t\t%d\t\t\t",i+1,processSize[i]);
        if(allocation[i] != -1){
            printf("%d\n",allocation[i]+1);
        }
        else{
            printf("Not Allocated\n");
        }
    }
}

void implementFirstFit(int blockSize[],int blocks,int processSize[],int processes){
    int allocation[processes];
    int occupied[blocks];
    for(int i=0;i<processes;i++){
        allocation[i] = -1;
    }
    for(int i=0;i<blocks;i++){
        occupied[i] = 0;
    }

    for(int i=0;i<processes;i++){
        for(int j=0;j<blocks;j++){
            if(blockSize[j] >= processSize[i] && !occupied[j]){
                allocation[i] = j;
                occupied[j] = 1;
                break;
            }
        }
    }
    printf("Process No\tProcessSize\tBlock No\n");
    for(int i=0;i<processes;i++){
        printf("%d\t\t\t%d\t\t\t",i+1,processSize[i]);
        if(allocation[i]!= -1){
            printf("%d\n",allocation[i]+1);
        }
        else{
            printf("Not allocated\n");
        }
    }

}

void implementWorstFit(int blockSize[],int blocks,int processSize[],int processes){
    int allocation[processes];
    int occupied[blocks];
    for(int i=0;i<processes;i++){
        allocation[i] = -1;
    }
    for(int i=0;i<blocks;i++){
        occupied[i] = 0;
    }

    for(int i=0;i<processes;i++){
        int index = -1;
        for(int j=0;j<blocks;j++){
            if(blockSize[j] >= processSize[i] && !occupied[j]){
                if((index == -1) || (blockSize[j] > blockSize[index])){
                    index = j;
                }
            }
        }
        if(index != -1){
            allocation[i] = index;
            occupied[index] = 1;
        }
    }
    printf("Process No.\tProcess Size\tBlock No\n");
    for(int i=0;i<processes;i++){
        printf("%d\t\t\t%d\t\t\t",i+1,processSize[i]);
        if(allocation[i] != -1){
            printf("%d\n",allocation[i]+1);
        }
        else{
            printf("Not Allocated\n");
        }
    }
}

int main(){
    int blockSize[] = {20,100,40,200,10};
    int processSize[] = {90,50,30,40};
    int blocks = sizeof(blockSize)/sizeof(blockSize[0]);
    int processes = sizeof(processSize)/sizeof(processSize[0]);
    implementBestFit(blockSize,blocks,processSize,processes);
    implementFirstFit(blockSize,blocks,processSize,processes);
    implementWorstFit(blockSize,blocks,processSize,processes);
    return 0;

}
