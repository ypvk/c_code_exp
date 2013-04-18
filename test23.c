#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  int n;
  int k = 1;
  int s = 0;
  while(scanf("%d", &n) != EOF)
  {
    for(k = 1, s = 1; s < n; ++k, s+=k);
    if (s == n) printf("%d/%d\n", 1, k);
    else printf("%d/%d\n",  s-n+1, k-s+n);
  }
  return 0;
}
