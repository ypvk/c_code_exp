#include <stdio.h>
#include <string.h>

int main(int argc, char** argv)
{
  int c;
  int f = 1;
  while((c = getchar()) != EOF)
  {
    if ( c == '"' && f) {printf("%s", "``"); f = !f;}
    else if ( c== '"' && !f) {printf("%s", "''"); f = !f;}
    else putchar(c);
  }
  return 0;
}
