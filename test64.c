#include <stdio.h>

#define MAX 100
int buff[MAX];
int L;
int N;

int bfs(int cur)
{
  int i;
  if(cur == N)
  {
    for(i = 0; i< N; i++)
      printf("%c ", 'A' + buff[i]);
    printf("\n");
    return 0;
  }
  for(i = 0; i < L; i++)
  {
    int j, k;
    buff[cur] = i;
    int equal = 1;
    int ok = 1;
    for(j = 1; j * 2 <= cur + 1; j++)
    {
      equal = 1;
      for(k = 0; k < j; k++)
      {
        if(buff[cur-k] != buff[cur - j - k]){equal = 0; break;}
      }
      if(equal) {ok = 0; break;}
    }
    if(ok) {
      if(!bfs(cur+1))return 0;
    }
  }
  return 1;
}

int main(int argc, char** argv)
{
  while(scanf("%d%d", &N, &L) == 2)
  {
    bfs(0); 
  }
  return 0;
}
