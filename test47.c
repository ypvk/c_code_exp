#include <stdio.h>
#define MAX 100
int buff[MAX];
/*get sum between [x, y)*/
int sum(int* A, int x, int y)
{
  int sum = 0;
  int i = x;
  for(;i < y; i++)sum += A[i];
  return sum;
}

int main(int argc, char** argv)
{
  int num, n;
  scanf("%d", &n);
  int i, j, k;
  for(i = 0; i < n; i++)scanf("%d", &buff[i]);
  scanf("%d", &num);
  int x = 0;
  int y = sum(buff, 0, n);
  int m;
  int flag;
  while(y-x > 1)
  {
    flag = 0;
    m = x + (y - x)/2;
    j = 0; 
    for(k = 0; k < num; k++)
    {
      int sum = 0;
      /* make sure evey subset sum be less than the m */
      for(i = j; i < n; i++)
      {
        sum += buff[i];
        if (sum > m) break;
      }
      if(i == n) {flag = 1; break;}
      j = i;
    } 
    if(flag == 1) y = m;
    else x = m;
  }
  printf("%d\n", y);
  return 0;
}
