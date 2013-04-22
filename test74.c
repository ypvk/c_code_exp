#include <stdio.h>
#include <string.h>

#define MAX 100
char a[MAX];
char b[MAX];
char result[2*MAX];

int main(int argc, char** argv)
{
  memset(a, 0, sizeof(a));
  memset(b, 0, sizeof(a));
  while(scanf("%s%s", a, b) == 2)
  {
    memset(result, 0, sizeof(result));
    int c = 0;
    int len1 = strlen(a);
    int len2 = strlen(b);
    printf("%s %s\n", a, b);
    int i;
    int j;
    int k = 0;
    for(i = len1-1; i >= 0; i--)
    {
      c = 0;
      for(j = len2-1; j >= 0; j--)
      {
        int tmp = (a[i] - '0') * (b[j] - '0') + c + result[len1 - i -1 + len2 - j-1]; 
        result[len1 - i  - 1 + len2 - j - 1] = tmp % 10;
        c = tmp / 10;
      }
      if(c) result[len1-i -1+len2] = c;
    }
    // print it
    i = 2*MAX - 1;
    while(!result[i])i--;
    if(i < 0)printf("0\n");
    else {
      for(; i >= 0; i--)printf("%c", result[i]+'0');
      printf("\n");
    } 
  }
  return 0;
}
