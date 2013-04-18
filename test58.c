#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
  int buff[10];
  int i;
  printf("%d", sizeof(buff));
  memset(buff, 0, sizeof(buff));
  for (i = 0; i < 10; i++)
  {
    printf("%d", buff[i]);
  }
  return 0;
}
