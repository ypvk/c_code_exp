#include <stdio.h>

#define MAX 100
int buff[MAX];

void print_subset(int n, int* A, int cur)
{
  int i;
  for(i = 0; i < cur; i++)
  {
    printf("%d ", A[i]);
  }
  printf("\n");
  int s = cur? A[cur-1] + 1 : 0;
  for(i = s; i< n; i++)
  {
   A[cur] = s;
   print_subset(n, A, cur+1);
  }
} 

void print_subset2(int n, int *B, int cur)
{
  if(n == cur)
  {
    int i;
    for(i = 0; i < n; i++)
    {
      if(B[i])printf("%d ", A[i]);
    }
    printf("\n");
  }
  B[cur] = 0;
  print_subset2(n, B, cur+1);
  B[cur] = 1;
  print_subset2(n, B, cur+1);
}

/* function 3 */
void print_set(int n, int s)
{
  int i;
  for(i = 0; i < n; i++)
  {
    if ( s & 1 << i) printf("%d ", i);
  }
  printf("\n");
}
void print_subset3(int n)
{
  int i;
  for(i = 0; i < (1 << n); i++)
    print_set(n, i);
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

