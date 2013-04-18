#include <stdio.h>
#include <string.h>

void build(int n, char* s1, char *s2, char* ans)
{
  if (n <= 0) return;
  int p = strchr(s2, s1[0]) - s2;
  build(p, s1+1, s2, ans);
  build(n-p-1, s1+1+p, s2+1+p, ans+p);
  ans[n-1] = s1[0];
}

int main(int argc, char** argv)
{
  char s1[50], s2[50], ans[50];
  while(scanf("%s%s", s1, s2) == 2)
  {
    memset(ans, 0, sizeof(ans));
    build(strlen(s1), s1, s2, ans);
    printf("%s\n", ans);
  }
  return 0;
}
