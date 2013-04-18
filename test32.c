#include <stdio.h>
#include <string.h>

#define MAX 100
int ans[MAX];
int v[MAX];
int G[MAX][MAX];
int t;
int n;

int dfs(int u)
{
  v[u] = -1;
  int i;
  for(i = 0; i < n; i++)
  {
    if(G[u][i])
    {
      if (v[i] == -1) return 0;
      else if(!v[i] && !dfs(i)) return 0;
    }
  }
  v[u] = 1;
  ans[--t] = u;
  return 1;
}
int top_sort()
{
  memset(v, 0, sizeof(v));
  int i;
  for(i = 0; i < n; i++)
  {
    if(!v[i] && !dfs(i)) return 0;
  }
  return 1;
}

int main(int argc, char** argv)
{
  int m;
  int i;
  char s[4];
  while(scanf("%d%d", &n, &m) == 2)
  {
    t = n;
    memset(G, 0, sizeof(G));
    for(i = 0; i < m; i++)
    {
      scanf("%s", s);
      G[s[0]-'a'][s[2]-'a'] = 1;
    }
    if(top_sort())
    {
      for(i = 0; i < n; i++)
        printf("%c ", 'a'+ans[i]);
      printf("\n");
    }
    else printf("-1\n");
  }
  return 0;
}
    
