//student details
#include <stdio.h>
#define MAX 10

struct Std_Details
{
    char name[100];
    char DOB[10];
    char regNo[10];
    char branch[10];
    char grade;
    int marks[MAX];
};

int main(){
    int n;
    struct Std_Details std;
    printf("Enter student name: ");
    scanf("%s",std.name);
    printf("Enter the RegNo: ");
    scanf("%s",std.regNo);
    printf("Enter the DOB: ");
    scanf("%s",std.DOB);
    printf("Enter the Branch: ");
    scanf("%s",std.branch);
    printf("Enter the Number of Subjects: ");
    scanf("%d",&n);

    for(int i=0;i<n;i++) {
        printf("Enter the Marks of subj %d: ",i+1);
        scanf("%d",&std.marks[i]);
    }

    float avg = 0;
    float total = 0;
    for(int i=0;i<n;i++){
    total = total + std.marks[i];
    }
    avg = total/n;

    if (avg>90)
    {
        std.grade = 'S';
    }
    else if(avg>80){
        std.grade = 'A';
    }
    else if (avg>70)
    {
        std.grade = 'B';
    }
    else if(avg > 60){
        std.grade = 'C';
    }
    else if(avg > 50){
        std.grade = 'D';
    }
    else {
        std.grade = 'F';
    }
    
    printf("\nStudent Details\n");
    printf("name: %s\n",std.name);
    printf("Reg No: %s\n",std.regNo);  
    printf("Branch: %s\n",std.branch);    
    printf("DOB: %s\n",std.DOB);    
    printf("Avg Mark: %lf\n",avg);    
    printf("Grade: %c\n",std.grade);
}
