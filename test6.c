#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int a, b, c;
  scanf("%d%d%d", &a, &b, &c);
  char output[15] = "%.";
  char num[4];
  char end[3] = "lf\n";
  sprintf(num, "%d", c);
  strcat(output, num);
  strcat(output, end);
  printf(output, 2.43253456);
  return 0;
}
