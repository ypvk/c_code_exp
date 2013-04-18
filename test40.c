#include <stdio.h>

#define MAX 100
int buff[MAX];

/* search value frome [x,y)*/
int bsearch(int* A, int x, int y, int value)
{
  int m;
  int i = x;
  int j = y;
  while(i < j)
  {
    m = i + (j-i)/2;
    if(A[m] == value)return m;
    if(A[m] > value) j = m;
    else i = m + 1;
  }
  return -1;
}
int main(int argc, char** argv)
{
  int n;
  int value;
  scanf("%d", &n);
  int i;
  for(i = 0; i < n; i++)scanf("%d", &buff[i]);
  scanf("%d", &value);
  int result = bsearch(buff, 0, n, value);
  printf("%d\n", result);
  return 0;
}
