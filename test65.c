#include <stdio.h>

#define MAX 100
int n, m;
int first[MAX];
int u[MAX], v[MAX], w[MAX], next[MAX];
void read_graph()
{
  scanf("%d%d", &n, &m);
  int i;
  for(i = 0; i < n; i++) first[i] = -1;
  for(i = 0; i < m; i++)
  {
    scanf("%d%d%d", &u[i], &v[i], &w[i]);
    next[i] = first[u[i]];
    first[u[i]] = i;
  }
}

priority_queue<int, vector<int>, cmp> q
int main(int argc, char** argv)
{
  printf("hello world\n");
  return 0;
}
