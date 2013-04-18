#include <stdio.h>
#define MAX 100
int buff[MAX];

int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", &n) == 1)
  {
    int i;
    long long max;
    long long tmp;
    int j;
    for(i = 0; i < n; i++)
    {
      scanf("%d", &buff[i]);
    }
    max = -1;
    tmp = 1;
    for(i = 0; i < n; i++)
     for(j = i; j < n; j++)
     {
      tmp *= buff[i];
      if(tmp > max) max = tmp;
     }
    if(max < 0) printf("-1\n");
    else printf("%d\n", max);
  }
 return 0;
} 
