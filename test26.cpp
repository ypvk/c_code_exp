#include <cstdio>
#include <stack>
using namespace std;

#define MAX 1000

int main(int argc, char** argv)
{
  int n;
  int i;
  int target[MAX];
  int A,B;
  int ok;
  while(scanf("%d", &n) == 1)
  {
    for (i = 1; i <= n; i++)
    {
      scanf("%d", &target[i]);
    }
    stack<int> s;
    A=1;
    B=1;
    ok = 1;
    while(B <= n)
    {
      if (A == target[B]) {A++; B++;}
      else if( !s.empty() && s.top() == target[B]){ s.pop(); B++;}
      else if (A <= n){ s.push(A++);}
      else { ok = 0; break;}
    }
    printf("%s\n", ok ? "Yes" : "No");
  }
  return 0;
}
      
      
