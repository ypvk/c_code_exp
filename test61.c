#include <stdio.h>
#include <string.h>

#define MAX 100
int num[MAX];

int main(int argc, char** argv)
{
  int n;
  int i;
  while(scanf("%d", &n) == 1)
  {
    for (i = 0; i< n; i++)
    {
      scanf("%d", &num[i]);
    }
    int max_sum = 0;
    int tmp_sum = 0;

    for(i = 0; i<n; i++)
    {
      tmp_sum += num[i];
      if(tmp_sum > max_sum) max_sum = tmp_sum;
      if(tmp_sum < 0)tmp_sum = 0;
    }
    printf("%d\n", max_sum);
  }
  return 0;
}

