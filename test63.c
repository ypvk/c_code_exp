#include <stdio.h>
#define MAX 100
int buff[MAX];

void print_subset(int n, int* A, int cur)
{
  int i;
  for(i = 0; i < cur; i++)printf("%d ", A[i]);
  printf("\n");

  int s = cur ? A[cur-1]+1 : 0;
  for(i = s; i < n; i++)
  {
    A[cur] = i;
    print_subset(n, A, cur+1);
  }
  return;
}

int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", &n) == 1)
  {
    print_subset(n, buff, 0);
  }
  return 0;
}
