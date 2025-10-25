#include <stdio.h>

int main() {
    // Create a null pointer
    int *ptr = NULL;
    
    // Attempt to dereference a null pointer, which will cause a segmentation fault
    *ptr = 42;
    
    // This line will never be reached due to the segmentation fault
    printf("This won't be printed\n");
    
    return 0;
}