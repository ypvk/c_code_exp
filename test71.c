#include <stdio.h>
#include <string.h>
#define MAX 100
typedef int vector[MAX];
vector buff[10];
int list[MAX];

int main(int argc, char** argv)
{
  int n; 
  while(scanf("%d", &n) == 1)
  {
    int i;
    int max = 0;
    for(i = 0; i < n; i++)
    {
      scanf("%d", &list[i]);
      if(max < list[i]) max = list[i];
    }
    // sort it 
    memset(buff, 0, sizeof(buff));
    int mod = 1;
    while(max / mod)
    {
      for(i = 0; i < n; i++)
      {
        int index = (list[i]/mod) % 10;
        int j = 0;
        while(buff[index][j])j++;
        buff[index][j] = list[i];
      }
      int j = 0;
      int k = 0;
      for(i = 0; i < 10; i++)
      {
        if(buff[i][0])
        {
          k = 0;
          while(buff[i][k]){list[j++] = buff[i][k]; buff[i][k]=0; k++;}
        }
      }
      mod *= 10;
    }
    int j = 0;
    int k = 0;
    for(i = 0; i < 10; i++)
    {
      if(buff[i][0])
      {
        k = 0;
        while(buff[i][k]){list[j++] = buff[i][k++];}
      }
    }
    //print
    for(i = 0; i < n; i++)
    {
      printf("%d ", list[i]);
    }
    printf("\n");
  }
  return 0;
}
