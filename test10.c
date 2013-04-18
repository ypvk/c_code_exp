#include <stdio.h>
#include <string.h>

int isalpha(char);
int isdigit(char);

int main(int argc, char* argv[])
{
  char buff[100];
  int i, n;
  scanf("%s", buff);
  printf("input is :%s\n", buff);
  n = strlen(buff);
  for(i = 0; i < n; i++)
  {
    if (isalpha(buff[i]))
    {
      printf("is alpha %c\n", buff[i]);
    }
    if (isdigit(buff[i]))
    {
      printf("is digit %c\n", buff[i]);
    }
  }
  return 0;
}
int isalpha(char c)
{
  return (c - 'a'>= 0 && c - 'z' <= 0) || (c - 'A' >= 0 && c - 'Z' <= 0);
}
int isdigit(char c) {
  return (c - '0' >=  0 && c - '9'<= 0);
}
