#include <cstdio>
#include <queue>
using namespace std;

int main(int argc, char** argv)
{
  int n;
  int i;
  queue<int> q;
  scanf("%d", &n);
  for(i = 1; i <= n; i++)
  {
    q.push(i);
  }
  while(!q.empty())
  {
    printf("%d ", q.front());
    q.pop();
    q.push(q.front());
    q.pop();
  }
  return 0;
}
