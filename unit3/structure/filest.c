#include <stdio.h>
#include <string.h>

struct Book {
    char title[100];
    char author[100];
    float price;
    int pages;
};

int main() {
    int n, i;
    printf("Enter the number of books: ");
    scanf("%d", &n);
    struct Book b[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter the details of book %d:\n", i + 1);
        printf("Title of book: ");
        scanf(" %[^\n]", b[i].title); // use %[^\n] to allow spaces
        printf("Author of book: ");
        scanf(" %[^\n]", b[i].author);
        printf("Price of book: ");
        scanf("%f", &b[i].price);
        printf("Pages of book: ");
        scanf("%d", &b[i].pages);
    }

    // Find max width for title and author
    int maxTitle = 5;  // minimum width for header
    int maxAuthor = 6; // minimum width for header
    for (i = 0; i < n; i++) {
        int titleLen = strlen(b[i].title);
        int authorLen = strlen(b[i].author);
        if (titleLen > maxTitle) maxTitle = titleLen;
        if (authorLen > maxAuthor) maxAuthor = authorLen;
    }

    // Print table header
    printf("\n%-4s | %-*s | %-*s | %-6s | %-7s\n",
           "SN", maxTitle, "Title", maxAuthor, "Author", "Pages", "Price");

    // Print separator line
    printf("-----+-");
    for (i = 0; i < maxTitle; i++) printf("-");
    printf("-+-");
    for (i = 0; i < maxAuthor; i++) printf("-");
    printf("-+--------+---------\n");

    // Print each book
    for (i = 0; i < n; i++) {
        printf("%-4d | %-*s | %-*s | %-6d | %-7.2f\n",
               i + 1, maxTitle, b[i].title, maxAuthor, b[i].author, b[i].pages, b[i].price);
    }

    return 0;
}
