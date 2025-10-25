#include<stdio.h>

int main()
{
	int a,b,c;
	printf("Enter the first value ");
	scanf("%d",&a);
	printf("Enter the second value ");
	scanf("%d",&b);
	printf("The first value is : %d\n",a);
	printf("The second value is : %d\n",b);
	c=a;
	a=b;
	b=c;
	printf("Value after Swap\n");
	printf("The first value is : %d\n",a);
	printf("The second value is : %d",b);

}