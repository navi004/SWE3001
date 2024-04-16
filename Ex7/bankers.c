// Banker's Algorithm  

/*
1.In a academic institution, Consider an electronics lab where a set of components will be provided to the students to complete their mini project. 
    Assume that a group of 5 students are currently working on a project in the lab and they require 3 types of components A, B, C to finish the project
    on that day itself. 
    The total quantities of the 3 components available in the lab are as follows:
        A - 10
        B - 7
        C - 8
    When the students have started doing their work each student has been provided with initial set of components and remaining will be given later. On
    entering to the lab the students should submit the maximum requirement of components.
    WAP in C to implement the Banker's algorithm to satisfy the requirements of each student by avoiding the student to wait for indefinite time.
    Display the following output on the screen 
    1) Need Matrix
    2) Available vector
    3) If the system is in safe state, find out safe sequence. 
    The initial allocation and maximum requirement of each student is given below:
    
    Student    Allocation      Max
    -------    ----------     -----
               A   B   C      A B C
               
      S0       1   1   2      5 4 4
      S1       2   1   2      4 3 3
      S2       3   0   1      9 1 3
      S3       0   2   0      8 6 4
      S4       1   1   2      2 2 3
*/
#include <stdio.h>  
int main()  
{  
    // P0, P1, P2, P3, P4 are the Process names here  
  
    int n, m, i, j, k;  
    n = 5;                         // Number of processes  
    m = 3;                         // Number of resources  
    int alloc[5][3] = {{1, 1, 2},  // P0 // Allocation Matrix  
                       {2, 1, 2},  // P1  
                       {3, 0, 1},  // P2  
                       {0, 2, 0},  // P3  
                       {1, 1, 2}}; // P4  
  
    int max[5][3] = {{5, 4, 4},  // P0 // MAX Matrix  
                     {4, 3, 3},  // P1  
                     {9, 1, 3},  // P2  
                     {8, 6, 4},  // P3  
                     {2, 2, 3}}; // P4  
  
    int avail[3] = {3,2,1}; // Available Resources  

    
    printf("2) Available vector\n");
    for(int i=0;i<3;i++){
        printf("%d ",avail[i]);
    }
    printf("\n");
    
  
    int f[n], ans[n], ind = 0;  
    for (k = 0; k < n; k++)  
    {  
        f[k] = 0;  
    }  
    int need[n][m];  
    for (i = 0; i < n; i++)  
    {  
        for (j = 0; j < m; j++)  
            need[i][j] = max[i][j] - alloc[i][j];  
    }  
    int y = 0;  
    for (k = 0; k < 5; k++)  
    {  
        for (i = 0; i < n; i++)  
        {  
            if (f[i] == 0)  
            {  
                int flag = 0;  
                for (j = 0; j < m; j++)  
                {  
                    if (need[i][j] > avail[j])  
                    {  
                        flag = 1;  
                        break;  
                    }  
                }  
                if (flag == 0)  
                {  
                    ans[ind++] = i;  
                    for (y = 0; y < m; y++)  
                        avail[y] += alloc[i][y];  
                    f[i] = 1;  
                }  
            }  
        }  
    }  
        printf("1) Need Matrix : \n");
    for(int i=0;i<5;i++){
        for(int j=0;j<3;j++){
            printf("%d ",need[i][j]);
        }
        printf("\n");
    }
    printf("\n");
    
    int flag = 1;  
    for (int i = 0; i < n; i++)  
    {  
        if (f[i] == 0)  
        {  
            flag = 0;  
            printf("The following system is not safe");  
            break;  
        }  
    }  
    if (flag == 1)  
    {  
        printf("Following is the SAFE Sequence\n");  
        for (i = 0; i < n - 1; i++)  
            printf(" P%d ->", ans[i]);  
        printf(" P%d", ans[n - 1]);  
    }  
    return (0);  
}  
