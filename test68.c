#include <stdio.h>
#include <string.h>
#define MAX 100
char str[MAX];
int stack[MAX];
int top = 0;

void judge(const char* string)
{
  int len = strlen(string);
  int i;
  top = 0;
  for(i = 0; i < len; i++)
  {
    if(string[i] == '('){stack[top++] = string[i];}
    else
    {
      if(top == 0) {printf("False\n"); return;}
      top--;
    }
  } 
  if (top == 0)printf("True\n");
  else printf("False\n");
}

int main(int argc, char** argv)
{
  while(scanf("%s", str) == 1)
  {
    judge(str);
  }
  return 0;
}
