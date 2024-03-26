#include <stdio.h>
#include <stdlib.h>

int finish[3] = {0};
int availale[3];
int need[5][3];
int max[5][3];
int allocation[5][3];
int sequence[5];
int s = 0;
void safety(int available[],int finish[],int need[],int allocation[],int sequence[]){
    int work[3];
    
    for(int i=0;i<3;i++){
        work[i] = available[i];
    }
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (finish[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > available[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    sequence[s++] = i;  
                    for (y = 0; y < m; y++)  
                        available[y] += allocation[i][y];  
                    finish[i] = 1;  
                }  
            }  
        }  
    }  
}

void resource_Request()
