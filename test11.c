#include <time.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main(int argc, char* argv[])
{
  int i;
  char c;
  //initial seed
  srand(time(NULL));
  for (i = 0; i < 10; i++){
    c = rand() % 127;
    printf("%c", c);
  }
  return 0;
}
  
