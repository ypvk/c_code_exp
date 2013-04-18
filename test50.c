#include <stdio.h>

int pow_mod(int a, int n, int m)
{
  int i;
  int ans = 1;
  for(i = 0; i < n; i++)
  {
    ans = (int)((long long)ans*a % m);
  }
  return ans;
}

int pow_mod2(int a, int n, int  m)
{
  if(n == 0) return 1;
  int x = pow_mod2(a, n/2, m);
  long long ans;
  ans = (long long) x*x % m;
  if(n%2 == 1)ans = ans*a % m;
  return (int)ans;
}

int main(int argc, char** argv)
{
  int a, n, m;
  while(scanf("%d%d%d", &a, &n, &m) == 3)
  {
    printf("%d\n", pow_mod(a, n, m));
    printf("%d\n", pow_mod2(a, n, m));
  }
  return 0;
}
