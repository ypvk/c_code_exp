#include <stdlib.h>
#include <stdio.h>

int main(int argc, char* argv[])
{
  int a,b,c;
  /*a = getchar();*/
  /*printf("%c", a);*/
  char* string = "12:56:78";
  sscanf(string, "%d:%d:%d", &a, &b, &c);
  printf("%d %d %d", a, b, c);
  return 0;
}
