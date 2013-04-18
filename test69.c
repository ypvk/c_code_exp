#include <stdio.h>
#include <string.h>

#define MAX 100
int stack[MAX];
char buff[MAX];
int top;

int max_substr(const char* str, int start)
{
  if(str[start] == ')')return 0;
  top = 0;
  int len = strlen(str);
  int i;
  int num = 0;
  for(i = start; i < len; i++)
  {
    if(str[i] == '('){stack[top++] = str[i];}
    else
    {
      if(top == 0)break;
      else
      {
        top--;
        num += 2;
      }
    }
  }
  return num;
}

int main(int argc, char** argv)
{
  while(scanf("%s", buff) == 1)
  {
    int max = 0;
    int pos;
    int len = strlen(buff);
    int i;
    for(i = 0; i < len; i++)
    {
      if((len - i) < max)break;
      int result = max_substr(buff, i);
      if(max <= result)
      {
        max = result;
        pos = i;
      }
    }
    printf("%d %d", pos, max);
    //print it
    for(i = 0; i <  max; i++)
    {
      printf("%c", buff[pos+i]);
    }
    printf("\n");
  }
  return 0;
}
