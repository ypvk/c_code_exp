#include <stdio.h>

#define MAX 100
int buff[MAX];
/* get index large num in [x, y)*/
void max_index(int* A, int x, int y, int index)
{ 
  if (y-x == 1 || y == x) return;
  int a = A[x];
  int i = x + 1;
  int j = y - 1;
  while(i <= j)
  {
    while(A[i] < a) i++;
    while(A[j] >= a && j > x) j--;
    if(i < j)
    {
      int tmp = A[i];
      A[i] = A[j];
      A[j] = tmp;
    }
  }
  int tmp = A[x];
  A[x] = A[j];
  A[j] = tmp;
  if (j == index - 1) return;
  if (j > index - 1) max_index(A, x, j, index);
  else max_index(A, j+1, y, index);
}

int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", &n) == 1)
  {
    int i;
    for(i = 0; i<n; i++) scanf("%d", &buff[i]);
    int m;
    scanf("%d", &m);
    max_index(buff, 0, n, m);
    printf("%d\n", buff[m-1]);
  }
  return 0;
}
      
