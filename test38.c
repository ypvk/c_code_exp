#include <stdio.h>

#define MAX 100
int buff[MAX];
/* get max linear list [x, y)*/
int maxsum(int* A, int x, int y)
{
  if(y - x == 1) 
  {
    if (A[x] >= 0)return A[x];
    else return 0;
  }
  int i,m;
  int max1, max2, L, R;
  int sum;
  m = x + (y-x)/2;
  max1 = maxsum(A, x, m);
  max2 = maxsum(A, m, y);
  max1 = max1 > max2 ? max1 : max2;
  L = 0;
  sum = 0;
  for(i = m - 1; i >= x; i--)
  {
    sum += A[i];
    if (L < sum) L = sum;
  }
  sum = 0;
  R = 0;
  for(i = m; i < y; i++)
  { 
    sum += A[i];
    if ( R < sum) R = sum;
  }
  max1 = max1 > (L+R) ? max1: (L+R);
  return max1;
}

int main(int argc, char** argv)
{
  int m;
  while(scanf("%d", &m) == 1)
  {
    int i;
    for(i = 0; i<m; i++)scanf("%d", &buff[i]);
    int max = maxsum(buff, 0, m);
    printf("%d\n", max);
  }
  return 0;
}


