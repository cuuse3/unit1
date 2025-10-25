#include <stdio.h>

int main ()
{
    
    int a, b, sum;
    int  *p, *q;
    printf("Enter the first number: ");
    scanf("%d",&a);
    
    printf("Enter the Second number: ");
    scanf("%d",&b);
     p = &a;
     q = &b;
     sum = *p + *q;

    printf("The sum of %d + %d is  : %d \n",*p,*q,sum);

    return 0;
  }
  