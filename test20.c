#include <stdio.h>
int main(int argc, char** argv)
{
  int a;
  while(scanf("%d", &a) != EOF && a !=0 )
  {
    printf("%d\n", a);
  }
  return 0;
}
