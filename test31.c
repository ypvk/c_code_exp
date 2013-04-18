#include <stdio.h>
#include <string.h>

#define MAX 100
int queue[MAX*MAX];
int vis[MAX][MAX];
int fa[MAX][MAX];
int maze[MAX][MAX];
int last_dir[MAX][MAX];
int dis[MAX][MAX];
int dx[4], dy[4];
int m;

void bfs(int x, int y)
{
  int front = 0;
  int rear = 0;
  int u;
  int d;
  u = x*m +y;
  memset(vis, 0, sizeof(vis));
  memset(fa, 0, sizeof(vis));
  memset(last_dir, 0, sizeof(vis));
  memset(dis, 0, sizeof(vis));
  queue[rear++] = u;
  vis[x][y] = 1;
  while(front < rear)
  {
   u = queue[front++];
   x = u/m;
   y = u%m; 
   for (d = 0; d < 4; d++)
   {
    int nx = x + dx[d];
    int ny = y + dy[d];
    if(nx >= 0 && ny >= 0 && nx < m && ny < m && maze[nx][ny] && !vis[nx][ny])
    {
      queue[rear++] = nx * m + ny;
      vis[nx][ny] = 1;
      dis[nx][ny] = dis[x][y] +1;
      fa[nx][ny] = u;
      last_dir[nx][ny] = d;
    }
   }
  }
}

char name(int d)
{
  char c;
  switch(d){
    case 0:
      c = 'U';break;
    case 1:
      c = 'R'; break;
    case 2:
      c = 'D';break;
    case 3:
      c = 'L';break;
  }
  return c;
}


void print_path(int x, int y)
{
  int fx = fa[x][y] /m;
  int fy = fa[x][y]%m;
  if(fx != x || fy != y)
  {
    print_path(fx, fy);
    putchar(name(last_dir[x][y]));
  }
}
void init_dir()
{
  int i;
  for(i = 0; i < 4; i++)
  {
    if(i % 2)
    {
      dx[i] = 0;
      dy[i] = i == 1 ? 1 : -1;
    }
    else
    {
      dy[i] = 0;
      dx[i] = i == 0 ? -1 : 1;
    }
  }
}
int main(int argc, char** argv)
{
  init_dir();
  while(scanf("%d", &m) == 1)
  {
    int i, j;
    for(i = 0; i < m; i++)
      for(j = 0; j < m; j++)
      {
        scanf("%d", &maze[i][j]);
      }
    bfs(0, 0);
    print_path(m-1, m-1);
  }
  return 0;
}
