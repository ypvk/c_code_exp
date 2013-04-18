#include <stdio.h>

#define MAX 10
int buff[1<<MAX][1<<MAX];

void calender_make(int start, int k)
{
  if(k == 1)
  {
    buff[start][1] = buff[start+1][0];
    buff[start+1][1] = buff[start][0];
    return;
  }
  
  calender_make(start, k-1);
  calender_make(start + (1<<(k-1)), k-1);
  int i;
  int j;
  for(i = 0; i < 1<<(k-1); i++)
    for(j = 0; j < 1<<(k-1); j++)
    {
      buff[(1<<(k-1))+i+start][(1<<(k-1))+j] = buff[i+start][j];
      buff[i+start][j+(1<<(k-1))] = buff[i+(1<<(k-1))+start][j];
    }
  return;
}

int main(int argc, char** argv)
{
  int k;
  while(scanf("%d", &k) == 1)
  {
    int i, j;
    for(i = 0; i < 1<<k; i++)buff[i][0] = i+1;
    calender_make(0, k);
    for(i = 0; i < 1<<k; i++)
    {
      for( j = 0; j < 1 <<k; j++)
        printf("%d ", buff[i][j]);
      printf("\n");
    }
  }
  return 0;
}
