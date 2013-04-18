#include <stdio.h>
#include <math.h>

void revert(int);

int main(int argc, char* argv[])
{
  int n;
  scanf("%d", &n);
  printf("%d%d%d\n", n%10, n/10%10, n/100);
  revert(n);
  return 0;
}

void revert(int n)
{
  int a = n%10*100 + (n/10%10)*10 + n/100;
  printf("%d\n", a);
}
