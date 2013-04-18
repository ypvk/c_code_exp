#include <stdio.h>

#define MAX 100
int buff[MAX];
/* quick sort [x,y)*/
void quick_sort(int* A, int x, int y)
{
  if(y-x == 1 || y == x) return;
  int i = x + 1;
  int j = y-1;
  int a = A[x];
  while(i <= j)
  {
    while(A[i] < a) i++;
    while(A[j] >=a && j > x)j--;
    if(i < j)
    {
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  A[x] = A[j];
  A[j] = a;
  quick_sort(A, x, j);
  quick_sort(A, j+1, y);
}

int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", &n) == 1)
  {
    int i;
    for(i = 0; i < n; i++)scanf("%d", &buff[i]);
    quick_sort(buff, 0, n);
    for(i = 0; i < n; i++)printf("%d ", buff[i]);
    printf("\n");
  }
  return 0;
}
