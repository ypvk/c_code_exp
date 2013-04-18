#include <stdio.h>
#include <string.h>


void trace(int n_left, int n_right, int stack[], int top,  char next, char* str, int end)
{
  if(next == '(') {
    stack[top] = next;
    str[end] = next;
    if(n_left > 0) trace(n_left - 1, n_right, stack, top+1, '(', str, end+1);
    if(n_right > 0) trace(n_left, n_right-1, stack, top+1, ')', str, end+1);
  } 
  if(next == ')') {
    str[end] = ')';
    if(n_left == 0 && n_right == 0 && top - 1 == 0)
    {
      str[end+1] = '\0';
      printf("%s, ", str);
      return;
    }
    if (top == 0) return; // wrong ans
    if(n_left > 0)trace(n_left -1, n_right, stack, top - 1, '(', str, end+1);
    if(n_right > 0)trace(n_left, n_right-1, stack, top - 1, ')', str, end+1);
  }
}

void backet(int n)
{
  int stack[100];
  int top = 0;
  char str[100];
  int end = 0;
  trace(n-1, n, stack, top, '(', str, end);
}

int main(int argc, char** argv)
{
  int n;
  while(scanf("%d", &n) == 1)
  {
    backet(n);
    printf("\n");
  }
}
