#include <stdio.h>
#include <string.h>

#define MAX 100
char buff[MAX];

int hash(char* str, int size)
{
  int len = strlen(str);
  int i, num;
  num = str[0];
  for(i = 1; i < len; i++)
  {
    num += (num << 5)*str[i]; 
  }
  return num % size;
}

int main(int argc, char** argv)
{
  while(scanf("%s", buff) == 1)
  {
    printf("Hash: %d\n", hash(buff, MAX));
  }
  return 0;
}
