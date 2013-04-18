#include <stdio.h>
#include <string.h>

#define MAX 100
int val[MAX][MAX], vis[MAX][MAX];
int xlen, ylen;

void visit(int x, int y)
{
  if(x < 0 || y <0 || x >= xlen || y >= ylen || !val[x][y] || vis[x][y])
    return;

  vis[x][y] = 1;
  
  visit(x-1, y-1);
  visit(x-1, y);
  visit(x-1, y+1);
  visit(x, y-1);
  visit(x, y+1);
  visit(x+1, y-1);
  visit(x+1, y);
  visit(x+1, y+1);
}
int main(int argc, char** argv)
{
  int m,n;
  int i, j;
  int count;
  while(scanf("%d%d", &m, &n) == 2)
  {
    memset(vis, 0, sizeof(vis));
    xlen = m;
    ylen = n;
    count = 0;
    for(i = 0; i < m; i++)
      for(j = 0; j< n; j++)
      {
        scanf("%d", &val[i][j]);
      }
    for(i = 0; i < m; i++)
      for(j =0; j<n;j++)
      {
        if(val[i][j] && !vis[i][j])
        {
          visit(i,j);
          count++;
        }
      }
    printf("%d\n", count);
  }
  return 0;
}
