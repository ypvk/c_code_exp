#include <stdio.h>

int strcmp(const char* s1, const char* s2)
{
  while(*s1 && *s2 && *s1++ == *s2++);
  return *s1 - *s2;
}

int main(int argc, char** argv)
{
  char str1[50];
  char str2[50];

  while(scanf("%s%s", str1,str2) == 2)
  {
    if(strcmp(str1, str2) == 0)printf("OK\n");
    else printf("Wrong\n");
  }
  return 0;
}
