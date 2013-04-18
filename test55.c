#include <stdarg.h>
#include <stdio.h>

int func(int a, ...)
{
  va_list ap;
  int i;
  va_start(ap, a);
  for(i = a; i != 0; i = va_arg(ap, int))
  {
    printf("%d ", i);
  }
  printf("\n");
  va_end(ap);
  return 0;
}
int main(int argc, char** argv)
{
  func(1);
  func(1, 2, 3);
  func(1,2,3,4,5,6,7,8);
  return 0;
}
