#include <stdio.h>

int main() {
  int rows;
  int i, j, k;
  char a=65;

    printf("Enter the noof rows; ");
    scanf("%d",&rows);
  for (i = 0; i < rows; i++) {
    for (j = 0; j <= rows - i; j++) {
      printf("%c", a + j);
    }

    for (k = 0; k <=i*2-2; k++) {
      printf(" ");
    }

    for (j = rows - i; j >= 0; j--) {
      if( j== rows) continue;
      printf("%c", a + j);
    }
    printf("\n");
  }

  return 0;
}