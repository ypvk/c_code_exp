#include <stdio.h>
#include <string.h>

#define MAX 50
int buff[MAX];
int vis[MAX];
int prime[MAX];

int is_prime(int n)
{
  int i;
  for(i = 2; i*i <= n ; i++)
  {
    if (n % i == 0) return 0;
  }
  return 1;
}

void get_prime_cycle(int n, int* A, int cur)
{
  int i;
  if(cur == n ){
    if (prime[A[0]+A[cur-1]]){
      for(i = 0; i < n; i++)
        printf("%d ", A[i]);
      printf("\n");
      return;
    }
    else return;
  }
  for(i = 2; i <= n; i++)
  {
    if (!vis[i] && prime[A[cur-1] + i]) 
    {
      A[cur] = i;
      vis[i] = 1;
      get_prime_cycle(n, A, cur+1);
      vis[i] = 0;
    }
  }
}

int main(int argc, char** argv)
{
  int n;
  int i;
  for(i = 0; i < 2*16; i++)prime[i] = is_prime(i);
  while(scanf("%d", &n) == 1)
  {
    memset(vis, 0, sizeof(vis));
    buff[0] = 1;
    get_prime_cycle(n, buff, 1);
  }
  return 0;
}

