#include <stdio.h>
#include <math.h>
int main(int argc, char* argv[])
{
  int a, b, n;
  double m;
  for (int i = 1; i <= 9; i++)
    for(int j = 0; j <= 9; j++)
    {
      n = 1100*i + 11*j;
      m = sqrt(n);
      if(floor(m+0.5) == m) printf("%d ", n);
    }
  printf("\n");
  return 0;
}
