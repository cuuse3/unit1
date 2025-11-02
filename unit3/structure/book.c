// Define a Book structure with fields title, author, price, and pages. Accept details for books and display them.
#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
    int pages;
};

int main()
{   int n, i;
    printf("Enter the no. of book: ");
    scanf("%d",&n);
    struct Book b[n];

     for(i=0;i<n;i++) {
    printf("Enter the details of book %d \n", i+1);
    printf("Title of book: ");
    scanf("%s",b[i].title);
    printf("Author of book: ");
    scanf("%s",b[i].author);
    printf("Price of book: ");
    scanf("%f",&b[i].price);
    printf("pages of book: ");
    scanf("%d",&b[i].pages);
   }
     printf("\nBooks entered:\n");
     
    printf("| SN | Title |Author|Pages|Price|\n");
    for (i = 0; i < n; i++) {
    printf("| %d | %s | %s | %d | %.2f | \n", i+1,b[i].title,b[i].author,b[i].pages,b[i].price);
    printf("|---|--------|-------|----|------|\n ");
    }

    return 0;
}
