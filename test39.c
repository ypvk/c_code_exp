#include <stdio.h>

#define MAX 100
int buff[MAX];
int tmp[MAX];
/* merge sort for [x, y] */
void merge_sort(int* A, int x, int y, int* T)
{
  int m;
  if( y - x == 1) return;
  m = x + (y-x)/2;
  merge_sort(A, x, m, T);
  merge_sort(A, m, y, T);
  int q, p;
  q = x;
  p = m;
  int k = 0;
  /*while(q < m && p < y)*/
  /*{*/
    /*if(A[q] < A[p])T[k++] = A[q++];*/
    /*else T[k++] = A[p++];*/
  /*} */
  /*if (q < m) {*/
    /*while(q < m)T[k++] = A[q++];*/
  /*}*/
  /*else if( p < y) {*/
    /*while(p < y)T[k++] = A[p++];*/
  /*}*/
  while(q < m || p < y)
  {
    if(p == y || (q < m && A[q] < A[p]))T[k++] = A[q++];
    else T[k++] = A[p++];
  }
  for(k = 0; k < y - x; k++)
    A[x+k] = T[k];
}

int main(int argc, char** argv)
{
  int n;
  scanf("%d", &n);
  int i;
  for(i = 0; i < n; i++) scanf("%d", &buff[i]);
  merge_sort(buff, 0, n, tmp);
  for(i = 0; i < n; i++) printf("%d ", buff[i]);
  printf("\n");
  return 0;
}
