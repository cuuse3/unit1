#include<stdio.h>

int main()
{
for(int i=0;i<7;i++){
for(char ch = 'A'; ch <= 'G'-i; ch++){
printf("%c",ch);
}
  for (int s = 0; s <= i*2-2 ; s++)
                printf(" ");

for (char ch = 'G' - i; ch >= 'A'; ch--) {
  if (ch == 'G') continue;
    printf("%c", ch);
}
printf("\n");
} 
}