#include <setjmp.h>
#include <signal.h>
#include <stdio.h>

jmp_buf buf;
void handler(int s)
{
  if(s == SIGINT) printf("Now got a SIGINT singal\n");
  longjmp(buf, 1);
}
int main(int argc , char** argv)
{
  signal(SIGINT, handler);
  if(setjmp(buf))
  {
    printf("back to main\n");
    return 0;
  }
  else
  {
    printf("first run\n");
  }
loop:
  goto loop;
}
