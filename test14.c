#include <stdio.h>
#include <stdlib.h>

int main(int argc, char** argv)
{
  char buff[50];
  int a, b;
  char op[2];
  /*fgets(buff, 50, stdin);*/
  /*sscanf(buff, "%d%s%d", &a, op, &b);*/
  scanf("%d%s%d", &a, op, &b);
  printf("%d%s%d", a, op, b);
  return 0;
}
  
