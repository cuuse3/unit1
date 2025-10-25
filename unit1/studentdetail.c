#include<stdio.h>

int main()
{
    int  age , roll;
    char name[30];
    printf("Enter the roll no of atudent: ");
    scanf("%d", &roll);
    printf("Enter the name of student: ");
    scanf("%s", &name);
    printf("Enter the age of Student : ");
    scanf("%d",&age);

    printf(" The roll no and age of %s is :\n %d and %d ", name, roll, age);

    return 0;
}