#include <stdio.h>

int main(int argc, char** argv)
{
  int a;
  while(scanf("%d", &a) == 1)
  {
    if (!a) printf("No\n");
    else {
      int b = a & (a-1);
      printf("%s\n", b == 0 ? "Yes" : "No");
    }
  }
  return 0;
}
