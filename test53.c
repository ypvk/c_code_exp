#include <stdio.h>
#include <signal.h>
#include <stdlib.h>

void handler(int s)
{
  /*if (s == SIGBUS)printf("bus error signal\n");*/
  if (s == SIGSEGV)printf("get segemnt violation signal\n");
  if (s == SIGILL)printf("iillegel instruction \n");
  exit(1);
}

int main(int argc, char** argv)
{
  int *p = NULL;
  /*signal(SIGBUS, handler);*/
  signal(SIGSEGV, handler);
  signal(SIGILL, handler);
  *p = 0;
}
