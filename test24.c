#include <stdio.h>
#include <string.h>

int is_prime(int a) 
{
  int i;
  for (i = 2; i * i <= a; i++)
  {
    if (a % i == 0) return 0;
  }
  return 1;
}

int main(int argc, char** argv)
{
  int prime[100];
  int ans[100];
  int count = 0;
  int i, j;
  int num;
  int n;
  int maxp = 0;
  for (i = 2; i < 100; i++)
  {
    if (is_prime(i))
    {
      prime[count++] = i;
    }
  }
  while(scanf("%d", &n) != EOF)
  {
    memset(ans, 0, sizeof(ans));
    maxp = 0;
    printf("%d!=", n);
    for(j = 2; j<=n; j++){
      num = j;
      for(i = 0; i < count; i ++)
      {
        while(num % prime[i] == 0)
        {
          num = num / prime[i];
          ans[prime[i]]++;
          if(maxp < i) maxp = i;
        }
      }
    }
    for(i = 0; i <= maxp; i++)
    {
      printf(" %d", ans[prime[i]]);
    }
    printf("\n");
  }
  return 0;
}
