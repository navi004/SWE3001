 /* 2. i. Consider an online delivery app, which delivers the product to the customer
          who have booked online. The app always chooses the nearest customer first
          for deliver and then next customer. Suppose 2 customers are booking the product
          at the same time then the nearest customer will be chosen first.Consider the
          booking time as arrival time. Choose an appropriate scheduling algorithm to 
          delivery the product in an efficient manner(bustime = distance)

      ii. For the same app compute for the frequent customer will be given discount 
          and consider that the customer is chosen with discount code as highest 
          protity(busttime = distance, priority = frequency)

    Write a program in c to implement 2 scheduling algorithm for case i and ii.
    Display all results on screen.
 */

#include <stdio.h>

struct Customer {
    int id;
    int BTime;
    int distance;
    int waitingTime;
    int priority;
    int turnaroundTime
};

int main() {
    int n, i, j;
    float avgWt = 0.0, avgTat = 0.0;
    printf("Enter the number of customers: ");
    scanf("%d", &n);

    struct Customer customers[n];

    printf("Enter the customer Booking Time and distance from the delivery location:\n");
    for (i = 0; i < n; i++) {
        customers[i].id = i+1;
        printf("Customer %d: ", i + 1);
        scanf("%d %d", &customers[i].BTime, &customers[i].distance);
    }
    
    int flag;
    printf("Enter an option(Priority-1 / SJF - 0):");
    scanf("%d",&flag);
    
    if(flag == 1){
        printf("Enter the discount code for each customer :\n");
        for(i=0;i<n;i++){
            printf("C[%d]:",i+1);
            scanf("%d",&customers[i].priority);
        }
        
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (customers[j].priority > customers[j+1].priority){
                    // Swap the customers
                    struct Customer temp = customers[j];
                    customers[j] = customers[j + 1];
                    customers[j + 1] = temp;
                }
            }
        }
    }
    else {
        // Sort the customers based on distance using bubble sort
        for (i = 0; i < n - 1; i++) {
            for (j = 0; j < n - i - 1; j++) {
                if (customers[j].distance > customers[j + 1].distance) {
                    // Swap the customers
                    struct Customer temp = customers[j];
                    customers[j] = customers[j + 1];
                    customers[j + 1] = temp;
                }
            }
        }
      
        for(i=0;i<n;i++){
            for(j = i+1;j<n;j++)
            if(customers[i].distance == customers[j].distance){
                if(customers[i].BTime > customers[i].BTime){
                    struct Customer temp = customers[i];
                    customers[i] = customers[j];
                    customers[j] = temp;
                }
            }
        }
    }
  
    customers[0].waitingTime = 0;

    // Calculate waiting time for each process
    for(i = 1; i < n; i++) {
        customers[i].waitingTime = 0;
        for(j = 0; j < i; j++) {
            customers[i].waitingTime += customers[j].distance;
        }
        customers[i].waitingTime -= customers[i].BTime;
    }

    
    printf("\nCustomer\tBooking Time\tDistance\tWaiting Time\tTurnaround Time\tPriority\n");

    // Calculate turnaround time and display process details
    for(i = 0; i < n; i++) {
        customers[i].turnaroundTime = customers[i].distance + customers[i].waitingTime;
        avgWt += customers[i].waitingTime;
        avgTat += customers[i].turnaroundTime;
        printf("C[%d]\t\t%d\t\t%d\t\t%d\t\t%d\t%d\n",customers[i].id , customers[i].BTime, customers[i].distance, customers[i].waitingTime, customers[i].turnaroundTime,customers[i].priority);
    }
    avgWt /= n;
    avgTat /= n;
    printf("\nAverage Waiting Time: %.2f", avgWt);
    printf("\nAverage Turnaround Time: %.2f", avgTat);
    printf("\n\nGantt Chart:\n");
    printf("__________________________________________\n");
    printf("|"); 

    for(i = 0; i < n; i++) {
        printf("| C[%d] |", customers[i].id);
    }
    printf("|\n");
    printf("__________________________________________\n");

    return 0;
}







 /* 2. i. Consider an online delivery app, which delivers the product to the customer
          who have booked online. The app always chooses the nearest customer first
          for deliver and then next customer. Suppose 2 customers are booking the product
          at the same time then the nearest customer will be chosen first.Consider the
          booking time as arrival time. Choose an appropriate scheduling algorithm to 
          delivery the product in an efficient manner(bustime = distance)

      ii. For the same app compute for the frequent customer will be given discount 
          and consider that the customer is chosen with discount code as highest 
          protity(busttime = distance, priority = frequency)

    Write a program in c to implement 2 scheduling algorithm for case i and ii.
    Display all results on screen.
 */

#include <stdio.h>

struct Customer {
    int id;
    int BTime;
    int distance;
    int waitingTime;
    int priority;
    int turnaroundTime
};

int main(){
    int n;
    float avg_taTime = 0.00,avg_wtTime = 0.00;
    printf("Enter the number of Customers: ");
    scanf("%d",&n);
    struct Customer customers[n];
    printf("Enter the Booking Time(Arrival Time)\n");
    for(int i=0;i<n;i++){
        customers[i].id = i+1;
        printf("C[%d] : ",customers[i].id);
        scanf("%d",&customers[i].BTime);
    }

    printf("Enter the Distance(Burst Time)\n");
    for(int i=0;i<n;i++){
        customers[i].id = i+1;
        printf("C[%d] : ",customers[i].id);
        scanf("%d",&customers[i].distance);
    }
    int flag = 0;
    printf("Enter the option(Priority -1 | SJF -0): ");
    scanf("%d",&flag);

    //For Priority
    if(flag == 1){
        printf("Enter the discout Code for each Customer:\n");
        for(int i =0;i<n;i++){
            printf("C[%d] : ",customers[i].id);
            scanf("%d",&customers[i].priority);
        }
        //Sorting
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(customers[j].priority > customers[j+1].priority){
                    struct Customer temp = customers[j];
                    customers[j] = customers[j+1];
                    customers[j+1] = temp; 
                }
            }
        }
    }
    //For SJF
    else{
        for(int i=0;i<n-1;i++){
            for(int j=0;j<n-i-1;j++){
                if(customers[j].distance > customers[j+1].distance){
                    struct Customer temp = customers[j];
                    customers[j] = customers[j+1];
                    customers[j+1] = temp;
                }
                else if(customers[j].distance == customers[j+1].distance ){
                    if(customers[j].BTime > customers[j+1].BTime){
                        struct Customer temp = customers[j];
                        customers[j] = customers[j+1];
                        customers[j+1] = temp; 
                    }
                }
            }
        }
    }
    // Calculate waiting time for each process
    customers[0].waitingTime = 0;
    for (int i = 1; i < n; i++) {
        customers[i].waitingTime = 0;
        for (int j = 0; j < i; j++) {
            customers[i].waitingTime += customers[j].distance;
        }
        customers[i].waitingTime -= customers[i].BTime;
    }

    // Calculate turnaround time for each process
    for (int i = 0; i < n; i++) {
        customers[i].turnaroundTime = customers[i].waitingTime + customers[i].distance;
        avg_wtTime += customers[i].waitingTime;
        avg_taTime += customers[i].turnaroundTime;
    }

    avg_taTime /= n;
    avg_wtTime /= n;
    printf("CustomerId\tBookingTime\tDistance\tPriority\n");
    for(int i=0;i<n;i++){ 
        printf("%d\t\t%d\t\t%d",customers[i].id,customers[i].BTime,customers[i].distance);
        if(flag == 1){
            printf("\t\t%d",customers[i].priority);
        }
        printf("\n");
    }
    printf("\nCustomerId\tWaiting Time\tTurnaround Time\n");
    for(int i=0;i<n;i++){
        printf("%d\t\t%d\t\t%d\n",customers[i].id,customers[i].waitingTime,customers[i].turnaroundTime);
    }
    printf("\n");

    printf("Average Waiting Time : %d\n",avg_wtTime);
    printf("Average Turnaround Time : %d\n",avg_taTime);
    printf("|");
    for(int i=0;i<n;i++){
        printf("| C[%d] |",customers[i].id);
    }
    printf("|");
    return 0;
}
