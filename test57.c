#include <stdlib.h>
#include <stdio.h>
#include <string.h>

#define MAXN 1000
char num[MAXN];
int main(int argc, char** argv)
{
  int n;
  int i, j;
  int c;
  int l;
  memset(num, -1, sizeof(num));
  scanf("%d", &n);
  num[0] = 1;
  c = 0;
  if (n <= 1) {printf("%d", 1); return 0;}
  for (i = 2; i <= n; i++)
  {
    for(j = 0; num[j] != -1; j++)
    {
      l = num[j] * i + c;
      num[j] = l % 10;
      c = l / 10;
    }
    while(c != 0)
    {
      num[j++] = c % 10;
      c = c/10;
    }
  }
  for (i = j - 1; i >= 0; i--)
  {
    printf("%d", num[i]);
  }
  printf("\n");
  return 0;
}
