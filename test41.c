#include <stdio.h>

#define MAX 100
int buff[MAX];

/* [x, y)*/
int rever_pairs(int* A, int x, int y)
{
  if(y-x == 1) return 0;
  int m;
  m = x + (y-x)/2;
  int count1 = rever_pairs(A, x, m);
  int count2 = rever_pairs(A, m, y);
  int i, j;
  int count3 = 0;
  for(i = x; i < m; i++)
    for(j = m; j < y; j++)
      if(A[i] > A[j])count3++;
  return count1 + count2 + count3;
}

int main(int argc, char** argv)
{
  int n;
  scanf("%d", &n);
  int i;
  for(i = 0; i< n; i++)scanf("%d", &buff[i]);
  printf("%d\n", rever_pairs(buff, 0, n));
  return 0;
}
