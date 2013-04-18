#include <stdio.h>
int main(int argc, char** argv)
{
  int a, b;
  int count, num;
  while(scanf("%d%d", &a, &b) != EOF && ( a != 0 || b != 0))
  {
    count = 0;
    num = 0;
    while(a && b) {
      num = (a%10 + b%10 + num)/10;
      if (num) {
        count++;
      }
      a = a/10;
      b = b/10;
    }
    num = (a%10 + b%10 + num)/10;
    if(num)count++;
    printf("%d\n", count);
  }
  return 0;
}
