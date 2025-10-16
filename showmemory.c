// Program to display memory size of different data types
#include <stdio.h>

int main() {
	printf("Memory size of different data types in C:\n");
	printf("char      : %d bytes\n", sizeof(char));
	printf("int       : %d bytes\n", sizeof(int));
	printf("float     : %d bytes\n", sizeof(float));
	printf("double    : %d bytes\n", sizeof(double));
	printf("short     : %d bytes\n", sizeof(short));
	printf("long      : %d bytes\n", sizeof(long));
	printf("long long : %d bytes\n", sizeof(long long));
	return 0;
}
