#include <stdio.h>

int main ()
{
    
    int a, b, *p, *q, sum;
    printf("Enter the first number: ");
    scanf("%d",&a);
    
    printf("Enter the Second number: ");
    scanf("%d",&b);
     *p = a;
     *q = b;
     sum = *p + *q;

    printf("The sum of %d + %d is  : %d",*p,*q,sum);

    return 0;
  }
  