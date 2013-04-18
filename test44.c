#include <stdio.h>

#define MAX 100
int buff[MAX];

int lower_bound(int* A, int x, int y, int v)
{
  int m;
  while(x < y)
  {
    m = x + (y-x)/2;
    if(A[m] == v) return m;
    if(A[m] > v) y = m;
    else x = m+1;
  }
  if (y == m) return m - 1;
  return m;
}

int upper_bound(int* A, int x, int y, int v)
{
  int m;
  while(x < y)
  {
    m = x + (y-x)/2;
    if(A[m] == v) return m;
    if(A[m] > v) y = m;
    else x = m+1;
  }
  if (y == m) return m;
  return m+1;
}

int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", &n) == 1)
  {
    int i;
    int a, b;
    for(i = 0; i<n; i++)scanf("%d", &buff[i]);
    scanf("%d%d", &a, &b);
    printf("%d %d\n", upper_bound(buff, 0, n, a), lower_bound(buff, 0, n, b));
  }
 return 0;
} 
