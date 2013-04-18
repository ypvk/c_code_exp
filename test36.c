#include <stdio.h>
#include <string.h>

typedef int State[9];
const int MAX = 1000000;
State st[MAX];
int dist[MAX];
int goal[9];
int dx[4] = {-1, 1, 0, 0};
int dy[4] = {0, 0, -1, 1};
char vis[900000000];

int try_to_insert(int rear)
{
  int i;
  for(i = 1; i < rear; i++)
  {
    if(memcmp(st[i], st[rear], sizeof(st[0])) == 0) return 0;
  }
  return 1;
}

int bfs()
{
  memset(dist, 0, sizeof(dist));
  memset(vis, 0, sizeof(vis));
  int front = 1;
  int rear = 2;
  int i;
  int num;
  num = 0;
  for(i = 0; i < 9; i++)
    num = num*10 + st[front][i];
  vis[num] = 1;
  while(front < rear)
  {
    State& s = st[front];
    if (memcmp(s, goal, sizeof(s)) == 0) return front;
    int z;
    for(i = 0; i < 9; i++)
    {
      if (s[i] == 0) break;
    }
    z = i;
    int x = z/3;
    int y = z%3;
    int d;
    for(d = 0; d<4; d++)
    {
      int newx = x + dx[d];
      int newy = y + dy[d];
      if(newx >= 0 && newx < 3 && newy >=0 && newy < 3)
      {
        int newz = newx*3 + newy;
        State& t = st[rear];
        memcpy(t, s, sizeof(s));
        t[z] = t[newz];
        t[newz] = 0;
        dist[rear] = dist[front] + 1;
        num = 0;
        for(i = 0; i < 9; i++)
          num = num*10 + t[i];
        if(!vis[num])
        {
          vis[num] = 1;
          rear++;
        }
        /*if(try_to_insert(rear)){*/
          /*num = 0;*/
          /*for(i = 0; i < 9; i++)*/
            /*num == num*10 + t[i];*/
          /*vis[num] = 1;*/
          /*rear++; */
      }
    }
    front++;
  }
  return 0;
}

int main(int argc, char** argv)
{
  int i;
  for(i = 0; i < 9; i++) scanf("%d", &st[1][i]);
  for(i = 0; i < 9; i++) scanf("%d", &goal[i]);
  int n;
  n = bfs();
  if(n) printf("%d\n", dist[n]);
  else printf("-1\n");
  return 0;
}
